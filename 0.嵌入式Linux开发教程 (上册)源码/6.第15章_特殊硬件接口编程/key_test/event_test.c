#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>

int main (int argc, char * argv[])
{
	int fd,count;
	struct input_event input_event_value;
	char input_type[20];

	if (argc !=2 ) {
                printf("usage : input_type /dev/input/eventX\n");
                return 0;
        }

	fd = open (argv[1], O_RDWR);
	if (fd < 0) {
		printf ("open %s failed\n", argv[1]);
		exit(0);
	}

	while(1) {							
		count=read(fd, &input_event_value, sizeof(struct input_event));
		if (count < 0) {
			printf("read iput device event error \n");
			return -1;
		}

		switch(input_event_value.type) {
		case EV_SYN:
			strcpy(input_type, "SYNC");
			break;
		case EV_REL:
			strcpy(input_type, "REL");
			break;
		case EV_ABS:
			strcpy(input_type, "ABS");
			break;
		case EV_KEY:
			strcpy(input_type, "KEY");
			break;
		default:
			printf("even type unkown \n");
			return -1;
		}

		printf("time:%ld.%ld",input_event_value.time.tv_sec,input_event_value.time.tv_usec);
		printf(" type:%s code:%d value:%d\n",input_type,input_event_value.code,input_event_value.value);
	}

	return 0;
}
