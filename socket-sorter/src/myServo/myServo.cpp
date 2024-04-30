#include "myServo/myServo.h"
#include "myConfig.h"
#include "Servo.h"
#include "Arduino.h"

bool IS_SERVO_SET_UP = false;
bool IS_SERVO_CLOSED = false;
Servo myServo_1;

int open = 0;
int closed = 155;

void set_up_servo()
{
  myServo_1.attach(SERVO_PIN);
  myServo_1.write(0);
  delay(2000);
}

// void flip_servo()
// {
//   if (IS_SERVO_SET_UP == false)
//   {
//     set_up_servo();
//     IS_SERVO_SET_UP = true;
//   }
//   if(IS_SERVO_CLOSED == false){
//     myServo_1.write(155);
//     IS_SERVO_CLOSED = true;
//     delay(2000);
//   }
//   if(IS_SERVO_CLOSED == true){
//     myServo_1.write(0);
//     IS_SERVO_CLOSED = false;
//     delay(2000);
//   }
// }

void open_gripper(){
  myServo_1.write(open);
  // delay(250);
}

void close_gripper(){
  myServo_1.write(closed);
  delay(500);
}