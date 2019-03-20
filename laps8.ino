#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
int buzzer = 14;  //D5
int LED1 = 13;  //D7
int LED2 = 15;  //D8
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(115200);
  pinMode(buzzer, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  dht.begin(); 
}
void loop() 
{
  
  float t = dht.readTemperature();
 if (isnan(t)){

     Serial.println("Failed to read from DHT sensor!");

      return;

   }
  if (t>26)
  {
    digitalWrite(buzzer, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
  }
  else
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  }

  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.println(" *C ");
  delay(1000);
}
