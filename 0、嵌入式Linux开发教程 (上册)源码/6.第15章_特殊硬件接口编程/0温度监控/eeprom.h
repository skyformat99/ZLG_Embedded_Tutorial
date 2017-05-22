#ifndef __EEPROM_H
#define __EEPROM_H

int set_temperature_to_eeprom(int min_temperature, int max_temperature);

int get_temperature_from_eeprom(int *min_temperature, int *max_temperature);


int init_eeprom(void);

#endif
