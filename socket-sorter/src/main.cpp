#include <Arduino.h>
// #include "myMotorControl/myMotorControl.h"
#include "myLoadCell/myLoadCell.h"
#include "myLimitSwitch/myLimitSwitch.h"
#include "myServo/myServo.h"
#include "myConfig.h"

// Classification
float minDistance = 1.25; // Minimum distance threshold
const String ids[] = {"m10", "m11", "m12", "m13", "m14", "m15", "m16", "m17", "m18", "m19"};
const float weights[] = {56.5, 60.9, 54.9, 61.5, 82.6, 106.3, 96.7, 122.8, 129.2, 142.3};
int numWeights = sizeof(weights) / sizeof(weights[0]);

void home_steppers();
void move_to_socket();
void lift_socket();
int findNearestWeightIndex(float weight, const float *weights, int numWeights, float minDistance);
void place_socket(String socket);
void clearSerial1Buffer();
void command_wait(const char* command);

void setup()
{

  Serial.begin(250000);
  Serial.println("Resetting");
  pinMode(RESET_PIN, OUTPUT);
  digitalWrite(RESET_PIN, LOW);
  delay(1000);
  digitalWrite(RESET_PIN, HIGH);

  delay(1000);
  Serial.println("GCODE Portal Initiated");
  Serial1.begin(250000);

  pinMode(limit_switch_1, INPUT_PULLUP); // Socket1 For limit switch

  Serial.print("*/");
  Serial.print(get_weight());
  Serial.println("/*");
  // Initialize Scale - scale is initialized through the myLoadCell.cpp file
  Serial.println("Open Gripper");
  set_up_servo(); // Initialize and Set up Servo, Open fully

  Serial.println("Homing Steppers");
  home_steppers();
  // delay(62000); // Delay for 62 seconds while the motors are homing
  Serial.println("Homing Completed");
}

void loop()
{

  if (read_average_limit_pin(limit_switch_1))
  {
    Serial.println("Socket Detected");
    delay(1000); // Sanity Check

    float weight = get_weight();
    Serial.print("*/");
    Serial.print(weight);
    Serial.println("/*");

    int nearestIndex = findNearestWeightIndex(weight, weights, numWeights, minDistance);

    // Select predicted string
    if (nearestIndex != -1)
    {
      Serial.println("Predicted string: " + ids[nearestIndex]);
      Serial.println("Move to Socket");
      move_to_socket();
      // delay(4000);
      Serial.println("Close Gripper Over Socket");
      close_gripper();
      Serial.println("Lift Socket Up");
      lift_socket();
      command_wait("G1 X 150 Y 200 Z 100");
      // delay(3000);
      place_socket(ids[nearestIndex]);
      // delay(7500);
      open_gripper();
      command_wait("G1 Z 100");
      command_wait("G1 X 150 Y 200");
      command_wait("M400");
    }
    else
    {
      Serial.println("No string selected");
    }
  }

}

void home_steppers()
{
  // command_wait();
  command_wait("M203 X400 Y400 Z30");
  command_wait("G1 F20000");
  command_wait("G1 Z 20");
  command_wait("G28 X Y");
  command_wait("G1 X 150 Y 200");
  command_wait("G28 Z");
  command_wait("G1 Z 30");
  command_wait("M400");
  // command_wait("M203 X10000 Y10000 Z1000");
  
}

void move_to_socket()
{
  // command_wait();
  command_wait("G1 X 259");
  command_wait("G1 Z 1");
  command_wait("M400");
}

void lift_socket()
{
  command_wait("G1 Z 100");
}

int findNearestWeightIndex(float weight, const float *weights, int numWeights, float minDistance)
{
  float minDist = minDistance;
  int minIndex = -1;

  for (int i = 0; i < numWeights; ++i)
  {
    float dist = abs(weights[i] - weight);
    if (dist < minDist)
    {
      minDist = dist;
      minIndex = i;
    }
  }

  return minIndex;
}

void place_socket(String socket)
{
  if (socket == "m10")
  {
    Serial.println("Socket value " + socket);
    // command_wait();
    command_wait("G1 X 73 Y 17");
    command_wait("G1 Z 17");
  }
  else if (socket == "m11")
  {
    Serial.println("Socket value " + socket);
    // command_wait();
    command_wait("G1 X 26 Y 18");
    command_wait("G1 Z 17");
  }
  else if (socket == "m12")
  {
    Serial.println("Socket value " + socket);
    // command_wait();
    command_wait("G1 X 74 Y 54");
    command_wait("G1 Z 17");
  }
  else if (socket == "m13")
  {
    Serial.println("Socket value " + socket);
    // command_wait();
    command_wait("G1 X 26 Y 54");
    command_wait("G1 Z 17");
  }
  else if (socket == "m14")
  {
    Serial.println("Socket value " + socket);
    // command_wait();
    command_wait("G1 X 76 Y 90");
    command_wait("G1 Z 17");
  }
  else if (socket == "m15")
  {
    Serial.println("Socket value " + socket);
    // command_wait();
    command_wait("G1 X 26 Y 91");
    command_wait("G1 Z 17");
  }
  else if (socket == "m16")
  {
    Serial.println("Socket value " + socket);
    // command_wait();
    command_wait("G1 X 77 Y 125");
    command_wait("G1 Z 17");
  }
  else if (socket == "m17")
  {
    Serial.println("Socket value " + socket);
    // command_wait();
    command_wait("G1 X 27 Y 127");
    command_wait("G1 Z 17");
  }
  else if (socket == "m18")
  {
    Serial.println("Socket value " + socket);
    // command_wait();
    command_wait("G1 X 78 Y 162");
    command_wait("G1 Z 17");
  }
  else if (socket == "m19")
  {
    Serial.println("Socket value " + socket);
    // command_wait();
    command_wait("G1 X 29 Y 164");
    command_wait("G1 Z 17");
  }
  else
  {
    Serial.println("Unknown socket value: " + socket);
  }
  command_wait("M400");
}

void clearSerial1Buffer() {
  while (Serial1.available()) {
    Serial1.read(); // Read and discard any pending characters
  }
}

void command_wait(const char* command) {
  clearSerial1Buffer();      // First, clear any leftover data in the buffer
  Serial1.println(command);  // Send the command to Marlin
  Serial.println("Sent command: " + String(command)); // Debug print to main serial
  // Wait for an acknowledgement from Marlin
  String readData = "";
  while (true) {
    if (Serial1.available()) {
      char c = Serial1.read();
      readData += c; // Append received char to the readData string
      // Check if the received data ends with "ok"
      if (readData.endsWith("ok")) {
        Serial.println("Received ack: ok");
        break; // Exit the loop if "ok" was received
      }
    }
  }
}