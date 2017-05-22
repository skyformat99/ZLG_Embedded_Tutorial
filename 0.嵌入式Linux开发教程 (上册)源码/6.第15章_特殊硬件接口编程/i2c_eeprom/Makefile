
CFLAGS += -Wall
obj := i2c_eeprom_test
src := i2c_eeprom_test.c
CC  :=  arm-fsl-linux-gnueabi-gcc

$(obj): $(src)
	$(CC) $(CFLAGS) $^ -o $@  -static

.PHONY: clean
clean:
	-rm i2c_eeprom_test
