EXEC = ./bin/tcp_server 
OBJS = tcp_server.o
SRC  = tcp_server.c

CC = arm-fsl-linux-gnueabi-gcc
CFLAGS += -O2 -Wall
LDFLAGS += 

all:$(EXEC)

$(EXEC):$(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) -pthread

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ -pthread

clean:
	@rm -vf $(EXEC) *.o *~
