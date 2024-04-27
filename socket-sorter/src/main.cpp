#include <Arduino.h>
// #include "myMotorControl.h"
// #include "myScaleSensor.h"
#include "myLoadCell/myLoadCell.h"
#include "myLimitSwitch/myLimitSwitch.h"
#include "myConfig.h"


//LIMIT SWITCHES
bool switch_detected_bool;

void setup() {
  Serial.begin(9600);
  pinMode(motor_limit_switch_1, INPUT_PULLUP);    //Limit Switch for motor

  // Initialize Scale - scale is initialized through the myLoadCell.cpp file
  get_weight();
}

void loop() {

  // switch_detected_bool = read_average_motor_limit_pin(motor_limit_switch_1);
  if (read_average_motor_limit_pin(motor_limit_switch_1)){
    // Serial.print(get_weight());
    Serial.print("*/");
    Serial.print(get_weight());
    Serial.println("/*");
  }

}












  // if (switch_detected_bool == true){
  //   Serial.println("Sensing Metal");  //Replace with Action
  // }
  // else{
  //   Serial.println("No Metal");       //Replace with Action
  // }