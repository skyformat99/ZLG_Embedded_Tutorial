#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <pthread.h>

#include "temperature.h"
#include "digitron.h"
#include "eeprom.h"
#include "digitron.h"
#include "key_event.h"

#define BEEP_DEV        "/sys/class/leds/beep/brightness"

static int beep_fd;

static enum {
	SHOW_L,
	SHOW_H,
	SHOW_TEMPER,
} sys_status;

static void beep_on(void)
{
	write(beep_fd, "1", 1);
}

static void beep_off(void)
{
	write(beep_fd, "0", 1);
}

static int key1_action(int value)
{
	int min_temperature = 0, max_temperature = 0, temperature;
	int ret;

	if (value == 0) {
		return 0;
	}

	ret = get_temperature_from_eeprom(&min_temperature, &max_temperature);	
	if (ret) {
		printf("get temperature from eeprom faile at %s \n", __FUNCTION__);
		return -1;
	}

	switch (sys_status) {
	/* 若当处于显示最低温度状态	*/
	case SHOW_L:
		if (min_temperature > 0) {
			min_temperature--;	
		}
		break;
	/* 当处于显示最高温度状态	*/
	case SHOW_H:
		if (max_temperature > min_temperature) {
			max_temperature--;
		}
		break;

	case SHOW_TEMPER:

		break;
	}		

	ret = set_temperature_to_eeprom(min_temperature, max_temperature);
	if (ret) {
		printf("set temperature to eeprom faile at %s \n", __FUNCTION__);
		return -1;
	}
	
	//printf("type:%d code:%d value:%d \n", type, code, value);	
	return 0;

}

static int key5_action(int value)
{
	int min_temperature = 0, max_temperature = 0, temperature;
	int ret;

	if (value == 0) {
		return 0;
	}

	ret = get_temperature_from_eeprom(&min_temperature, &max_temperature);	
	if (ret) {
		printf("get temperature from eeprom faile at %s \n", __FUNCTION__);
		return -1;
	}

	switch (sys_status) {
	/* 若当处于显示最低温度状态	*/
	case SHOW_L:
		if (min_temperature < max_temperature)	{
			min_temperature++;	
		}
		break;
	/* 当处于显示最高温度状态	*/
	case SHOW_H:
		if (max_temperature < 85) {
			max_temperature++;
		}

		break;

	case SHOW_TEMPER:

		break;
	}		

	ret = set_temperature_to_eeprom(min_temperature, max_temperature);
	if (ret) {
		printf("set temperature to eeprom faile at %s \n", __FUNCTION__);
		return -1;
	}
	
	//printf("type:%d code:%d value:%d \n", type, code, value);	
	return 0;

}

static int key2_action(int value)
{
	if (value == 0) {
		return 0;
	}
	
	sys_status = SHOW_L;

	return 0;
}

static int key3_action(int value)
{
	if (value == 0) {
		return 0;
	}
	
	sys_status = SHOW_TEMPER;

	return 0;
}

static int key4_action(int value)
{
	if (value == 0) {
		return 0;
	}
	
	sys_status = SHOW_H;

	return 0;
}


static int thread_control(int *value)
{
	int min_temperature = 0, max_temperature = 0, temperature;
	float temp_t;
	int ret = -1;
	int value1, value2, value3,value4;
	
	

	while (1) {

		ret = get_temperature_from_eeprom(&min_temperature,&max_temperature);
		if (ret) {
			printf("read temperature faile \n");
			break;
		}
		
		temp_t = get_temperature();
		temperature = (int )(temp_t * 100.0);			/* 获取热敏电阻温度并转换为整数	*/

		/* 显示	*/
		switch (sys_status) {
		/* 当处于显示最低温度状态时，数码管显示类似：26.0L */
		case SHOW_L:	
			value1 = min_temperature / 10;
			value2 = min_temperature % 10;
			value3 = 0;
			value4 = 22;					/* 显示"L"			*/
				
			set_digitron_vlue(value1, value2, value3, value4);
			
			break;

		/* 当处于显示最高温度状态时，数码管显示类似:40.0H */
		case SHOW_H:
			value1 = max_temperature / 10;
			value2 = max_temperature % 10;
			value3 = 0;
			value4 = 21;					/* 显示"H"			*/
				
			set_digitron_vlue(value1, value2, value3, value4);
	
			break;

		case SHOW_TEMPER:
			value1 = temperature/1000;
			value1 = value1%10;

			value2 = temperature/100;
			value2 = value2%10;

			value3 = temperature/10;	
			value3 = value3%10;

			value4 = temperature%10;

			set_digitron_vlue(value1, value2, value3, value4);

			break;
		default:
			break;

		}

		/* 监控 */
		if (temp_t < min_temperature) { 			/* 温度过低			*/
			 /* 蜂鸣器短鸣一声，数码管显示的数字闪烁 */      
                        beep_on();
                        set_digitron_on(DIGITRON_OFF);
                        usleep(50*1000);
                        set_digitron_on(DIGITRON_ON);
                        beep_off();

		} else if (temp_t > max_temperature) {			/* 温度过高			*/
			 /* 蜂鸣器短鸣两声，数码管显示的数字闪烁 */
                        beep_on();
                        set_digitron_on(DIGITRON_OFF);
                        usleep(50*1000);
                        set_digitron_on(DIGITRON_ON);
                        beep_off();

                        usleep(20*1000);

                        beep_on();
                        usleep(50*1000);
                        beep_off();
		}
		
		usleep(300*1000);
	}	
}

int init_control(void)
{
	int ret;
	pthread_t thread_control_t;

	sys_status = SHOW_TEMPER;					/* 初始化为显示当前温度状态	*/

	beep_fd = open(BEEP_DEV, O_RDWR);
        if (beep_fd < 0) {
                perror("open beep device");
        }

	ret = install_key_function(key1_action, KEY1);
	if (ret) {
		printf("install call fun faile in %s \n", __FUNCTION__);
		return -1;
	}

	ret = install_key_function(key2_action, KEY2);
	if (ret) {
		printf("install call fun faile in %s \n", __FUNCTION__);
		return -1;
	}

	ret = install_key_function(key3_action, KEY3);
	if (ret) {
		printf("install call fun faile in %s \n", __FUNCTION__);
		return -1;
	}

	ret = install_key_function(key4_action, KEY4);
	if (ret) {
		printf("install call fun faile in %s \n", __FUNCTION__);
		return -1;
	}

	ret = install_key_function(key5_action, KEY5);
	if (ret) {
		printf("install call fun faile in %s \n", __FUNCTION__);
		return -1;
	}

	ret = pthread_create(&thread_control_t, PTHREAD_CREATE_JOINABLE, (void *)thread_control, NULL);
        if (ret) {
                printf("create thread faile in %s \n", __FUNCTION__);
                return -1;
        }

	return 0;
}

