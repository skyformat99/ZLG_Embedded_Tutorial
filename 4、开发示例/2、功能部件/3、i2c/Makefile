
CFLAGS += 
obj := ./bin/i2c_ds2460_test
src := i2c_ds2460_test.c
CC  := arm-fsl-linux-gnueabi-gcc

$(obj): $(src)
	$(CC) $(CFLAGS)  -o $@  $^

.PHONY: clean
clean:
	-rm $(obj)
