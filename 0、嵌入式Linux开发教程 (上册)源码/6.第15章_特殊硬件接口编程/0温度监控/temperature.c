#include<stdio.h>     
#include<stdlib.h>   
#include<fcntl.h>    
#include<sys/ioctl.h>  
#include <math.h>

#include "lradc.h"

#define ADC_DEV		"/dev/magic-adc"
#define ADC_MODULE_PATH "/lib/modules/lradc.ko"

#define R33		2000
#define V_ADC		3.3
#define T1		(273.15 + 25)
#define R1 		27600
#define B		3435*1000
#define MAX_SIZE	100


static int fd;

double get_temperature(void)
{
	int adc_value;
	double voltage;
	double RT = 0;
	double  temp = 0;
	int ret;

     	ret = ioctl(fd, IMX28_ADC_CH1, &adc_value);                   //283A & 287A
     	//ret = ioctl(fd, IMX28_ADC_CH4, &adc_value);                     //280
	if (ret) {
		printf("get adc value faile \n");
		return -1;
	}

      	voltage = (adc_value*1.85)/4096.0;				/* 计算测量电压			*/
	RT = (V_ADC/voltage - 1)*R33;					/* 计算热敏电阻的阻值		*/

	temp = 3435/log(10*RT) - 273.15;				/* 计算热敏电阻的温度		*/

	return temp;
}

int init_temperature_function(void)
{
	char curren_dir[MAX_SIZE];

	if (access(ADC_DEV, F_OK)) {					/* 检查ADC设备文件是否存在	*/
		if (access(ADC_MODULE_PATH, F_OK) == 0) {		/* 检查ADC模块是否存在		*/
			system("insmod /lib/modules/lradc.ko");
			//system("udevtrigger");				/* 促使ADC的设备文件生成	*/
			while (access(ADC_DEV, F_OK)) {
				sleep(1);	
			}
		} else {
			printf("ADC module moust at /lib/modules/ \n");
			return -1;
		}
	}
		

        fd = open(ADC_DEV, 0);
        if(fd < 0){
                printf("open error by APP- %d\n",fd);
                return -1;
        }

	return 0;	
}

