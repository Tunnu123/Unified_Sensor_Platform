
#include "i2c.h"
#include "log.h"
#include "uart.h"
#include"Unified_testing.h"
#include<stdio.h>
#define UPDATE_TIME 1
#define I2C i2c_instance[1]
#define DS3231_SLAVE_ADDRESS 0XD0
#define DS3231_REG_OFFSET 0
#define DS3231_DEC_TO_HEX(decimal)  ( ( (decimal / 10 ) << 4) | (decimal % 10) )
#define DELAY_VALUE 900
#define PRESCALER_COUNT 0x1F
#define SCLK_COUNT 0x91




class Unified_ds3231:public Shakti_Sensor
{
 public:
unsigned int ds3231_decimal_to_hex(unsigned int);
int read_ds3231_registers(i2c_struct* , unsigned int , unsigned int*, unsigned char , unsigned long delay);
int write_ds3231_registers(i2c_struct * , unsigned int , unsigned int *, unsigned char , unsigned long );
int begin();
void working();
int dayofweek(int, int, int);
bool getEvent(sensors_event_t *);
void getSensor(sensor_t *);
void log_info(const char*fmt, ...);
};





