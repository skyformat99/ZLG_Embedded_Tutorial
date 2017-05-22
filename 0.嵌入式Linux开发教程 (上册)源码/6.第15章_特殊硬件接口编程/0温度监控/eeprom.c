#include     <stdio.h>
#include     <stdlib.h>
#include     <unistd.h>
#include     <sys/types.h>
#include     <sys/stat.h>
#include     <fcntl.h>
#include     <termios.h>
#include     <errno.h>
#include <pthread.h>

#define I2C_SLAVE       0x0703
#define I2C_TENBIT      0x0704

#define I2C_ADDR  0xA0
#define DATA_LEN  8

#define I2C_DEV_NAME  "/dev/i2c-1"
#define DATA_ADDR     0

static int i2c_fd;
static pthread_mutex_t mutex;

int set_temperature_to_eeprom(int min_temperature, int max_temperature)
{
	char buf[4];
	int len;
	int ret = 0;

	pthread_mutex_lock(&mutex);

	buf[0] = DATA_ADDR;
	buf[1] = (char)min_temperature;
	buf[2] = (char)max_temperature;
	buf[3] = 0xAA;

	len = write(i2c_fd, buf, 4);
        if (len < 0) {
                printf("write data faile \n");
		ret = -1;
                goto out;
        }

	usleep(1000);

out:

	pthread_mutex_unlock(&mutex);


	return ret;
}

int get_temperature_from_eeprom(int *min_temperature, int *max_temperature)
{
	char buf[3];
	int len;
	int ret = 0;

	pthread_mutex_lock(&mutex);

	buf[0] = DATA_ADDR;

	len = write(i2c_fd, buf, 1);
        if (len < 0) {
                printf("write data addr faile \n");
                ret = -1;
		goto out;
        }
        len = read(i2c_fd, buf, 3);
        if (len < 0) {
                printf("read data faile \n");
                ret = -1;
		goto out;
        }

	*min_temperature = (int)buf[0];
	*max_temperature = (int)buf[1];


	if (buf[2] != 0xAA) {
		ret = -2;
		goto out;
	}
out:
	pthread_mutex_unlock(&mutex);

	return ret;
}


int init_eeprom(void)
{
	int ret;
	int T1, T2;

	i2c_fd = open(I2C_DEV_NAME, O_RDWR);
        if(i2c_fd < 0) {
                printf("open %s failed\r\n", I2C_DEV_NAME);
                return -1;
        }

        ret = ioctl(i2c_fd, I2C_SLAVE, I2C_ADDR >> 1);
        if (ret < 0) {
                printf("setenv address faile ret: %x \n", ret);
                return -1;
        }
	
	pthread_mutex_init(&mutex, NULL);	

	/* 检查eeprom内部存储是否已经写入最低温度值和最高温度值，如果没则
    	   写最低温度为25，最高温度为40 */
	ret = get_temperature_from_eeprom(&T1, &T2);
	if (ret == -1) {
		printf("read data from eeprom faile at %s \n", __FUNCTION__);
		return -1;
	} else if (ret == -2) {
		printf("init min & max temperature to eepprom \n");
		
		ret = set_temperature_to_eeprom(25, 40);
		if (ret) {
			printf("write date to eeprom faile at %s \n", __FUNCTION__);
		}
	}

	

	return 0;
}
