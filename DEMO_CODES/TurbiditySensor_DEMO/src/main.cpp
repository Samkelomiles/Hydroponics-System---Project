#include <Arduino.h>
#define turb 4


void setup() {
  Serial.begin(115200); //Baud rate: 9600
}
void loop() {
  int sensorValue = analogRead(turb);// read the input on analog pin 0:
  float turbidity = sensorValue * (3.3 / 4095.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  
  Serial.print(turbidity);
  Serial.println("NTU"); // print out the value you read:
  delay(1000);
}