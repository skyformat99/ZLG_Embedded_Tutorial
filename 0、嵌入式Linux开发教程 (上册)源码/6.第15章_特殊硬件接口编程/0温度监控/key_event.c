#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <pthread.h>

#include "key_event.h"
#include "digitron.h"

#define DEV_NAME 	"/dev/input/event1"
#define KEY_MODULE_PATH "/lib/modules/imx28x_key.ko"


static int fd;

/* 五个按键，每个按键可以注册一个回调函数	*/
static key_callback key_callback_fun[5] = {NULL, NULL, NULL, NULL, NULL};				

int install_key_function(key_callback p, int key)				/* 注册回调函数			*/
{
	if (p == NULL) {
		return -1;
	}

	if (key_callback_fun[key]) {						/* 防止多次设置			*/
		return -1;
	} else {
		key_callback_fun[key] = p;
	}

	return 0;
}



static int key_pthread(void)
{
	int count;
	struct input_event input_event_value;
	//char input_type[20];
	//static int ret = 0;


	while(1) {							
		count=read(fd, &input_event_value, sizeof(struct input_event));
		if (count < 0) {
			printf("read iput device event error \n");
			return -1;
		}

		switch (input_event_value.code) {
		case KEY_A:
			if (key_callback_fun[KEY1]) {
				key_callback_fun[KEY1](input_event_value.value);
			}	
			break;

		case KEY_B:
			if (key_callback_fun[KEY2]) {
				key_callback_fun[KEY2](input_event_value.value);
			}

			break;

		case KEY_C:
			if (key_callback_fun[KEY3]) {
				key_callback_fun[KEY3](input_event_value.value);
			}
			break;


		case KEY_D:
			if (key_callback_fun[KEY4]) {
				key_callback_fun[KEY4](input_event_value.value);
			}
			break;
		
		case KEY_E:
			if (key_callback_fun[KEY5]) {
				key_callback_fun[KEY5](input_event_value.value);
			}
			break;

		default:
			break;
		
		}

	}

	return 0;
}


int init_event_key(void)
{
	int ret;
	pthread_t thread_key;

	if (access(DEV_NAME, F_OK)) {                                   /* 检查按键设备文件是否存在      */
                if (access(KEY_MODULE_PATH, F_OK) == 0) {               /* 检查按键模块是否存在          */
                        system("insmod /lib/modules/imx28x_key.ko");
                        //system("udevtrigger");                          /* 促使ADC的设备文件生成        */
			while (access(DEV_NAME, F_OK)) {		/* 等待按键设备文件生成		*/
				sleep(1);
			}
                } else {
                        printf("key module moust at /lib/modules/ \n");
                        return -1;
                }
        }

	fd = open (DEV_NAME, O_RDWR);
	if (fd < 0) {
		perror(DEV_NAME);
		exit(0);
	}


	 /* start key conctol pthread */
        ret = pthread_create(&thread_key, PTHREAD_CREATE_JOINABLE, (void *)key_pthread, NULL);
        if (ret) {
                printf("create thread faile at %s \n", __FUNCTION__);
                return -1;
        }

	return 0;
}
