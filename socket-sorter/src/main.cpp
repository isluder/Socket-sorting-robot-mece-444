#include <Arduino.h>
#include "myConfig.h"
// #include "myColorSensor.h"
// #include "myMotorControl.h"
// #include "myScaleSensor.h"
#include "myLimitSwitch.h"


//LIMIT SWITCHES
bool read_average_motor_limit_pin();
bool switch_detected_bool;

void setup() {
  Serial.begin(9600);
  pinMode(motor_limit_switch_1, INPUT);
}

void loop() {

  switch_detected_bool = read_average_motor_limit_pin(motor_limit_switch_1);


  if (switch_detected_bool == true){
    Serial.println("Sensing Metal");
  }
  else{
    Serial.println("No Metal");
  }

}

