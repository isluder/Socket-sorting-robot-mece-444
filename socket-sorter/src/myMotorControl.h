// #include <Arduino.h>

// #include <Arduino.h>

// // defines pins numbers
// const int stepPin = 3; 
// const int dirPin = 4; 
// // const byte ledPin = 13;
// // Makes 200 pulses for making one full cycle rotation
// const int numberOfSteps = 400;
// const unsigned int sleepTimeInit = 500; // microseconds
 
// void setup() {
//   Serial.begin(9600);
//   Serial.println("Starting StepperTest");
//   // digitalWrite(ledPin, LOW);
  
//   // Sets the two pins as Outputs
//   pinMode(stepPin,OUTPUT); 
//   pinMode(dirPin,OUTPUT);
// }
// void loop() {
//   digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
//   for(int x = 0; x < numberOfSteps; x++) {
//     digitalWrite(stepPin,HIGH); 
//     delayMicroseconds(sleepTimeInit); 
//     digitalWrite(stepPin,LOW); 
//     delayMicroseconds(sleepTimeInit); 
//   }
//   delay(1000); // One second delay
  
//   digitalWrite(dirPin,LOW); //Changes the rotations direction
//   for(int x = 0; x < numberOfSteps; x++) {
//     digitalWrite(stepPin,HIGH);
//     delayMicroseconds(sleepTimeInit);
//     digitalWrite(stepPin,LOW);
//     delayMicroseconds(sleepTimeInit);
//   }
//   delay(1000);
// }