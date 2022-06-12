#ifndef declaration_h
#define declaration_h

#include "DHT.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#include <HTTPClient.h>
#include <string.h>

const char* ssid = "Mvelase_Connect";
const char* password = "Sbahle1234"; 
const char* serverName = "http://192.168.1.148/HM_system/esp-data.php";

String apiKeyValue = "hmssystem";


//ip address - 192.168.1.148

#define DHTPIN 5     // Digital pin connected to the DHT sensor
#define LDR 36
#define DHTTYPE DHT11   // DHT 11
#define echoPin 14
#define trigPin 12


#define relayA 32 //pump 1 
#define relayB 33 //pump 2  
#define relayC 22 //pump 3
#define relayD 23 //grow light

 
//get speed of sound through air
#define SOUND_SPEED 0.034

// GPIO where the DS18B20 is connected to
#define oneWireBus  4    

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

long duration;
float water_level;
float water_temp=0.0;
//int lumens;
float humidity;
float air_temp;


DHT dht(DHTPIN, DHTTYPE);

#endif
