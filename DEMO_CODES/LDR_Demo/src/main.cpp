#include <Arduino.h>
#define Light 2

void setup() 
{
  
  Serial.begin(115200);  
  delay(1000);  
 
}

void loop() {

  // put your main code here, to run repeatedly:
 int val = analogRead(Light);  
 Serial.print(val);
 Serial.println("lm ");  
 delay(100); 

}