#include     <stdio.h>
#include     <stdlib.h> 
#include     <unistd.h>  
#include     <sys/types.h>
#include     <sys/stat.h>
#include     <fcntl.h> 
#include     <termios.h>
#include     <errno.h>  

#define I2C_SLAVE	0x0703
#define I2C_TENBIT	0x0704

#define I2C_ADDR  0xA0
#define DATA_LEN  8

#define I2C_DEV_NAME  "/dev/i2c-1"

int main(int arg,char*args[])
{
    	unsigned int ret,len;
    	int i,flag=0;
	int fd;

    	char tx_buf[DATA_LEN + 1];
    	char rx_buf[DATA_LEN];
    	char addr[1];
	
	addr[0] = 0;

    	fd = open(I2C_DEV_NAME, O_RDWR);   
    	if(fd < 0) {
        	printf("open %s failed\r\n", I2C_DEV_NAME);
		return -1;
	}

  	ret = ioctl(fd, I2C_SLAVE, I2C_ADDR >> 1);  
    	if (ret < 0) {
		printf("setenv address faile ret: %x \n", ret);
		return -1;
     	}

	tx_buf[0] = addr[0];                           
	for (i = 1; i < DATA_LEN; i++)
        		tx_buf[i] = i;
    	
	len = write(fd, tx_buf, DATA_LEN + 1);                
	if (len < 0) {
		printf("write data faile \n");
		return -1;
	}

	usleep(1000*100);

    	len = write(fd, addr, 1);                         
	if (len < 0) {
		printf("write data addr faile \n");
		return -1;
	}
    	len = read(fd, rx_buf, DATA_LEN);        
	if (len < 0) {
		printf("read data faile \n");
		return -1;
	}

    	printf("read from eeprom:");
    	for(i = 0; i < DATA_LEN - 1; i++) {
         	printf(" %x", rx_buf[i]);
		if (rx_buf[i] != tx_buf[i+1]) flag = 1; 
    	}
    	printf("\n");

	if (!flag) {
		printf("eeprom write and read test sussecced!\r\n");
	} else {
		printf("eeprom write and read test failed!\r\n");
	}

	return 0;
}
