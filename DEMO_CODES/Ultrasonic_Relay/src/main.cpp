//This code will control the relay switch to the pump based on a set distance measured
//with the Ultrasonic sensor

#include <Arduino.h>

//assign pin numbers
const int relay = 27;
const int trigPin = 26;
const int echoPin = 25;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;
float perc = 0.0;
void setup() {
  
  Serial.begin(115200);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(relay,OUTPUT);
}

void loop() {

    //1. Clear the trig pin by setting it to low
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);

    //2. set trig pin on high for 10uS
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);

    //3. Read echo pin, returns sound wave travel time in microseconds
    duration = pulseIn(echoPin,HIGH);

    //Calculate distance 
    // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;

  //distance in percentage
  perc = (distanceCm/50)*100;

  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);

  if(distanceCm > 25 && distanceCm < 35)
  {
    // Normally Open configuration, send LOW signal to let current flow
    // (if you're usong Normally Closed configuration send HIGH signal)
    digitalWrite(relay,LOW);
    
     
    Serial.println("PUMP ON");
    Serial.print("Distance (cm): ");
    Serial.println(distanceCm);
    Serial.print("The tank is at ");
    Serial.print(perc);
    Serial.println("%");
    Serial.println("===============================================");
    delay(500);

  }
  else 
  {
   // Normally Open configuration, send HIGH signal stop current flow
  // (if you're usong Normally Closed configuration send LOW signal)
   digitalWrite(relay,HIGH);
    Serial.println("PUMP OFF");
    Serial.print("Distance (cm): ");
    Serial.println(distanceCm);
    delay(500);

   delay(500);
  }  



}