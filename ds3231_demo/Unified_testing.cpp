#include "Unified_testing.h"




/**************************************************************************/
/*!
    @brief  Prints sensor information to serial console
*/
/**************************************************************************/
void Shakti_Sensor::printSensorDetails(void) {
  sensor_t sensor;
  getSensor(&sensor);
  printf("");
  printf("Sensor:       ");
  std::cout<<sensor.name;
  printf("Type:         ");
  switch ((sensors_type_t)sensor.type) {
  
  case SENSOR_TYPE_RELATIVE_HUMIDITY:
    printf("Relative Humidity (%)");
    break;
  case SENSOR_TYPE_AMBIENT_TEMPERATURE:
    printf("Ambient Temp (C)");
    break;
  case SENSOR_TYPE_OBJECT_TEMPERATURE:
    printf("Object Temp (C)");
    break;
  
  }


  printf("Driver Ver:   ");
  std::cout<<sensor.version;
  printf("Unique ID:    ");
  std::cout<<sensor.sensor_id;
  std::cout<<sensor.min_value;
  printf("Max Value:    ");
   std::cout<<sensor.max_value;
  printf("Resolution:   ");
  std::cout<<sensor.resolution;
  
}
