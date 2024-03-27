#include <Arduino.h>
// #include "myMotorControl.h"
// #include "myScaleSensor.h"
#include "myLimitSwitch/myLimitSwitch.h"
#include "myConfig.h"


//LIMIT SWITCHES
bool switch_detected_bool;

void setup() {
  Serial.begin(9600);
  pinMode(motor_limit_switch_1, INPUT_PULLUP);
}

void loop() {

  switch_detected_bool = read_average_motor_limit_pin(motor_limit_switch_1);


  if (switch_detected_bool == true){
    Serial.println("Sensing Metal");  //Replace with Action
  }
  else{
    Serial.println("No Metal");       //Replace with Action
  }
}