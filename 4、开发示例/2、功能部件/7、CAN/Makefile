
CFLAGS += -Wall
obj := ./bin/can_test
src := can_test.c
CC  := arm-fsl-linux-gnueabi-gcc

$(obj): $(src)
	$(CC) $(CFLAGS) $^ -o $@ -g

.PHONY: clean
clean:
	-rm $(obj)
