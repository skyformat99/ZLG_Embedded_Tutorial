EXEC = zlg_temp_control
OBJS = main.o temperature.o digitron.o eeprom.o key_event.o control.o
SRC  = main.c temperature.c digitron.c eeprom.c key_event.c control.c

CC = arm-fsl-linux-gnueabi-gcc
CFLAGS +=
LDFLAGS +=  -lm -lrt -lpthread
all:$(EXEC)

$(EXEC):$(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) 
	cp -av zlg_temp_control /nfsroot/

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -vf $(EXEC) *.o *~

