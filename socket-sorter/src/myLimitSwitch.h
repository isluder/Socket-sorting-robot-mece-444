#include <Arduino.h>
#include "myConfig.h"

bool read_average_motor_limit_pin(int lim_pin){
  long sum = 0;
  for (int i = 0; i < motor_limit_samples; i++)
  {
    bool switch_detected_bool = digitalRead(lim_pin);
    sum += switch_detected_bool;
  }
  float average = sum / motor_limit_samples;
  if (average == 0){
    return true;
  }
  else {
    return false;
  }
}