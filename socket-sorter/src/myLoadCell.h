// #include <Arduino.h>
// #include "HX711.h"
// #include "myPrintout.h"

// // HX711 circuit wiring
// const int LOADCELL_DOUT_PIN = 53;
// const int LOADCELL_SCK_PIN = 52;

// HX711 scale;

// void printout(float reading);
// void initalize_printout();
// float mymap(float x, float in_min, float in_max, float out_min, float out_max);

// // Adjustment Settings
// // const float LOADCELL_DIVIDER = 5895655;
// // const float LOADCELL_OFFSET = 50682624;

// void setup()
// {
  
//   scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
//   initialize_printout();
//   delay(2500);
//   if (scale.is_ready())
//   {
//     scale.tare(15);
//   }
//   // scale.set_scale(LOADCELL_DIVIDER);
// }

// void loop()
// {
//   double reading = scale.get_units(1);
//   reading = mymap(reading, 0.00, 101700.00, 0.00, 141.00);
//   printout(reading);
// }

// float mymap(float x, float in_min, float in_max, float out_min, float out_max)
// {
//   return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
// }




// #include <Arduino.h>

// void initialize_printout(){
//     Serial.begin(9600);
//     Serial.println("Tare... remove any weights from the scale.");
// }

// void printout(float reading)
// {
//   Serial.print("*/");
//   Serial.print(reading);
//   Serial.println("/*");
// }