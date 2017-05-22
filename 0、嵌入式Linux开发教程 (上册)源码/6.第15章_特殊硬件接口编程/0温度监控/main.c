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
#include "key_event.h"

#define BEEP_DEV   	"/sys/class/leds/beep/brightness"

static int min_temperature = 0;
static int max_temperature = 0;

extern int init_control(void);

int main(int argc, char *argv[])
{
	int ret;
	int fd;
	double value;

	ret = init_digitron();						/* 初始化数码管模块		*/
	if (ret)
		return -1;

	ret = init_eeprom();						/* 初始化eeprom模块		*/
	if (ret)
		return -1;

	ret = init_temperature_function();				/* 初始化温度检测模块		*/
	if (ret)  
		return -1;

	ret = init_event_key();						/* 初始化按键模块		*/
	if (ret) 
		return -1;

	ret = init_control();						/* 初始化监控模块		*/
	if (ret) 
		return -1;	


	while ( 1 ) {
		sleep(1);
	}

	return ret;
}
