#include <Arduino.h>
#include <WiFi.h>
#include "declaration.h"

int pumpOFF = 0;
int pumpON = 0;
 

void SensorReadings();

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHTxx test!"));
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  //Sets echoPin as Input


//###################  SETUP RELAYS ###############################
 
  pinMode(relayA,OUTPUT);
  pinMode(relayB,OUTPUT);
  pinMode(relayC,OUTPUT);
  pinMode(relayD,OUTPUT);

  
      digitalWrite(relayA,HIGH);
      digitalWrite(relayB,HIGH);
      digitalWrite(relayC,HIGH);
      digitalWrite(relayD,HIGH);
 
  //################ configure connection to wifi ##################

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  //##################################################################

  dht.begin();
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  humidity = dht.readHumidity(); //air humidity
  air_temp = dht.readTemperature(); //air temperature
  water_temp = sensors.getTempCByIndex(0);//water temperature
  int analogValue = analogRead(LDR);

  

  /* ============ GET READINGS OF ULTRASONIC SENSOR ===================*/

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  water_level = 20 - (duration * SOUND_SPEED / 2);
  water_level = (water_level/20)*100;

  delay(100);

  //Check WiFi connection status

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;    
    WiFiClient client;
    http.begin(client, serverName);
    // Your Domain name with URL path or IP address with path


    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    // Prepare your HTTP POST request data
    String httpRequestData = "api_key=" + apiKeyValue + "&humidity=" + String(humidity)
                             + "&air_temp=" + String(air_temp)
                             + "&water_temp=" + String(water_temp)
                             + "&water_level=" + String(water_level)
                             + "";
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);

    
    int httpResponseCode = http.POST(httpRequestData);

   
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  //Send an HTTP POST request every 15 seconds
  SensorReadings();
  
  delay(2000);
  

  


  
 if (water_level<25 && water_level>4)
 { 
 
  if(pumpON == 0)
  {
  digitalWrite(relayA,LOW);
  digitalWrite(relayB,LOW);
  digitalWrite(relayC,LOW);
 
  pumpOFF++;
  }
  if(pumpOFF == 6)
  {
  digitalWrite(relayC,HIGH);
  pumpON++;
  delay(1000);
  digitalWrite(relayA,HIGH);
  digitalWrite(relayB,HIGH);
  }

  if(pumpOFF == 6 && pumpON == 6)
  {
     pumpON=0;
     pumpOFF=0;
  }
 
 }
 else
 {
  digitalWrite(relayC,HIGH);
 }

  if(analogValue>4090)
  {
    digitalWrite(relayD,LOW);  
  }
  else
  {
    digitalWrite(relayD,HIGH);
  }


  
  delay(10000);
}


//----##### lets first get readings from each sensor ######-----//
void SensorReadings()
{

int  analogValue = analogRead(LDR);
 

  if (isnan(humidity) || isnan(air_temp))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
   
  }


  Serial.print(F(" Humidity: "));
  Serial.print(humidity);
  Serial.print(F("% Air Temperature: "));
  Serial.print(air_temp);
  Serial.print(F("ºC   Water Temperature:"));
  Serial.print(water_temp);
  Serial.println("ºC");

  delay(100);
  
  Serial.print("Water Level: ");
  Serial.println(water_level);
  Serial.print("Lumens: ");
  Serial.print(analogValue);
  
  Serial.println("===========================");
  delay(1000);

}
