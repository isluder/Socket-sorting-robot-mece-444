#include "myMotorControl/myMotorControl.h"
#include "myConfig.h"

bool IS_SERIAL_SET_UP = false;

void set_up_serial(){
    Serial1.begin(250000);
    IS_SERIAL_SET_UP = true;
}

void home_axis(){
    if (IS_SERIAL_SET_UP == false){
        set_up_serial();
    }
    if(Serial1.available()){
        Serial1.write('G1 Z 20');
        delay(1000);
        Serial1.write('G28 X Y');
        delay(5000);
        Serial1.write('G1 X 150 Y 200');
        delay(2500);
        Serial1.write('G28 Z');
    }
}

void go_to_load(){
    
}