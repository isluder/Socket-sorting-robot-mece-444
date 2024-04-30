#include "myLimitSwitch/myLimitSwitch.h"
#include "myConfig.h"

bool read_average_limit_pin(int lim_pin){
if(!digitalRead(lim_pin)){
    return true;
}
  return false;
}