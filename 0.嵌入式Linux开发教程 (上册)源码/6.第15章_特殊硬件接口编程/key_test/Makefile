EXEC = event_test
OBJS = event_test.o
SRC  = event_test.c

CC = arm-fsl-linux-gnueabi-gcc
#LD = arm-linux-ld
CFLAGS += -O2 -Wall
LDFLAGS += 

all:$(EXEC)

$(EXEC):$(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) 

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -vf $(EXEC) *.o *~
