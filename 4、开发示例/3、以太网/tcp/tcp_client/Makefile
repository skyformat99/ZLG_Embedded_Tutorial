EXEC = ./bin/tcp_client 
OBJS = tcp_client.o
SRC  = tcp_client.c

#CC = arm-none-linux-gnueabi-gcc
CC = gcc
CFLAGS += -O2 -Wall
LDFLAGS += 

all:$(EXEC)

$(EXEC):$(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) -pthread

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ -pthread

clean:
	@rm -vf $(EXEC) *.o *~
