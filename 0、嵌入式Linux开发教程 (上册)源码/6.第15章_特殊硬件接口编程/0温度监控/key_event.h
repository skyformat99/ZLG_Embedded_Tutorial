#ifndef __KEY_EVENT_H
#define __KEY_EVENT_H

#include <linux/input.h>

enum{
	KEY1,
	KEY2,
	KEY3,
	KEY4,
	KEY5
};

typedef int (*key_callback)(int value);

int install_key_function(key_callback, int key);
int init_event_key(void);

#endif
