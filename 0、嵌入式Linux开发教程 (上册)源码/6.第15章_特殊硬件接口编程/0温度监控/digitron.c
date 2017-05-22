#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <sys/time.h>
#include <linux/spi/spidev.h>
#include <time.h>
#include <signal.h>
#include <math.h>
#include <pthread.h>
#include <string.h>

#include "digitron.h"

#define SPI_DEVICE	"/dev/spidev1.0"
#define GPIO_DEVICE 	"/sys/class/gpio/gpio117/value"
#define GPIO_EXPORT     "/sys/class/gpio/export"
#define GPIO117_DIR     "/sys/class/gpio/gpio117/direction"

/* Nixie light value tale   0     1     2     3     4     5      6     7    8     9  */
int led_value_table[] =   {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90,
/*                          0.    1.    2.    3.    4.    5.     6.    7.   8.    9  */  
			   0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10, 
			/*无显示    H     L	*/
			   0xFF,   0x89, 0xC7};

static uint8_t mode = 0;
static uint8_t bits = 8;
static uint32_t speed = 10000;
static uint16_t delay = 0;

static int fd_spi;
static int fd_gpio;


static int show_value[4] = {0, 0, 21, 22};
static int is_show = DIGITRON_ON;

static void show_led_num(int value, int num)
{
	int ret;

	uint8_t tx[] = {led_value_table[value], (1 << num)};

	struct spi_ioc_transfer tr_txrx[] = {
		{
                .tx_buf      = (unsigned long)tx,
                .rx_buf      = 0,
                .len         = 2,
                .delay_usecs = delay,
                .speed_hz    = speed,
                .bits_per_word = bits,
		},
	};

        ret = ioctl(fd_spi, SPI_IOC_MESSAGE(1), &tr_txrx[0]);
        if (ret == 1) {
                printf("can't revieve spi message");
		return;
	}
	
	write(fd_gpio, "0", 1);
	usleep(100);
	write(fd_gpio, "1", 1);

}


void set_digitron_on(int value)
{
	is_show = value;
}

void set_digitron_vlue(int value1, int value2, int value3, int value4)
{
	show_value[0] = value1;
	show_value[1] = value2 + 10;					/* 在个位加上小数点	*/	
	show_value[2] = value3;
	show_value[3] = value4;		
}


static int show_digitron(int *value)
{
	static int i = 0;
	int show_value_led = 0;
	
	while ( 1 ) {
		if (is_show == DIGITRON_ON) {
			show_led_num(show_value[i], i);
		} else {
			show_led_num(20, i);
		}
		

		i++;
		if (i == 4) 
			i = 0;
		usleep(1000);
	}

	return 0;
}

int init_digitron(void)
{
	int ret;
	pthread_t thread_show;
	struct sched_param param;

	fd_spi = open(SPI_DEVICE, O_RDWR);
	if (fd_spi < 0) {
		printf("can't open %s \n", SPI_DEVICE);
		return -1;
	}


	ret = ioctl(fd_spi, SPI_IOC_WR_MODE, &mode);			/* set spi mode 		*/
	if (ret == -1) {
		printf("can't set wr spi mode\n");
		return -1;
	}

	ret = ioctl(fd_spi, SPI_IOC_WR_BITS_PER_WORD, &bits);		/* set spi bits per word	*/
	if (ret == -1) {
		printf("can't set bits per word\n");
		return -1;
	}

	ret = ioctl(fd_spi, SPI_IOC_WR_MAX_SPEED_HZ, &speed);		/* max speed hz			*/
	if (ret == -1)	{
		printf("can't set max speed hz\n");
		return -1;
	}

	  if (access(GPIO117_DIR, F_OK)) {                                /* 判断GPIO3.21的属性文件是否存在*/
		int fd;
                /* 导出GPIO3.21的属性文件       */
                fd = open(GPIO_EXPORT, O_WRONLY);
                if (fd < 0){
                        perror(GPIO_EXPORT);
                }
                write(fd, "117", 4);
                close(fd);

                while (access(GPIO117_DIR, F_OK));

                /* 把GPIO3.21设置为输出状态     */
                fd = open(GPIO117_DIR, O_RDWR);
                if (fd < 0) {
                        perror(GPIO117_DIR);
                }
                write(fd, "out", 4);
                close(fd);
        }

	fd_gpio = open(GPIO_DEVICE, O_RDWR);	
	if (fd_gpio < 0) {
		printf("can't open %s device\n", GPIO_DEVICE);
		return -1;
	}

	ret = pthread_create(&thread_show, PTHREAD_CREATE_JOINABLE, (void *)show_digitron, NULL);
	if (ret) {
		printf("create thread faile \n");
		return -1;
	}
	
	return 0;
}


