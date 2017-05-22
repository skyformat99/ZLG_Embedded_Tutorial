#ifndef __DIGITRON_H 
#define __DIGITRON_H

#define DIGITRON_ON   1							/* 使能数码管显示		*/
#define DIGITRON_OFF  0							/* 禁能数码管显示		*/

void set_digitron_on(int value);
void set_digitron_vlue(int value1, int value2, int value3, int value4);
int init_digitron(void);

#endif
