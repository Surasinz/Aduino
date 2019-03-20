#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
int LED1 = 13;  //D7
int LED2 = 15;  //D8
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  dht.begin(); 
}
void loop() 
 {
  float t = dht.readTemperature();
  if (t>26)
  {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
  }
  else
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  }
}
