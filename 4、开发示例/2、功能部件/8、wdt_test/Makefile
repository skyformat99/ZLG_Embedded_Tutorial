EXEC    = ./bin/wdt_test
OBJS    = wdt_test.o

CROSS   = arm-fsl-linux-gnueabi-
CC      = $(CROSS)gcc
STRIP   = $(CROSS)strip
CFLAGS  = -Wall -g -O2

$(EXEC):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	$(STRIP) $@

.PHONY:clean
clean:
	rm -f $(EXEC) $(OBJS)

