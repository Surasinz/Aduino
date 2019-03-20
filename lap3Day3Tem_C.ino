#include "DHT.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1
#include <Adafruit_NeoPixel.h>
#define NUMSLEDs 2
#define PINSLEDs 10
Adafruit_NeoPixel SLEDs=Adafruit_NeoPixel(NUMSLEDs,PINSLEDs,NEO_RGB + NEO_KHZ800);
Adafruit_SSD1306 OLED(OLED_RESET);
#define DHTTYPE DHT22
#define DHTPIN D4
#define ledPin1 D0 
#define ledPin2 D7
#define ledPin3 D5
DHT dht (DHTPIN,DHTTYPE,15);
const int buzzer = D8;
void setup() 
{
   pinMode(PINSLEDs,OUTPUT);
   SLEDs.begin();
   SLEDs.show();
   Serial.begin(115200); 
   OLED.begin(SSD1306_SWITCHCAPVCC,0x3c);
   pinMode(buzzer, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT); 
}
void loop() 
  {
   float h = dht.readHumidity();
   float t = dht.readTemperature();
   float f = dht.readTemperature(true);
   Serial.println(t);
    OLED.clearDisplay();
    OLED.setTextColor(WHITE);
    OLED.setCursor(0,0);
    OLED.setTextSize(2);
    OLED.println(h);
    OLED.setCursor(0,30);
    OLED.println(t);
    OLED.display();
   if (t>30) 
   {
    digitalWrite(ledPin1, 1); 
    digitalWrite(ledPin2, 0);
    digitalWrite(ledPin3, 0);
    SLEDs.setPixelColor(0,SLEDs.Color(0,  250,  0));
    SLEDs.setPixelColor(1,SLEDs.Color(0,  250,  0));
    SLEDs.show();
    tone(buzzer,350);
   }
  else  if ((t<30)&&(t>27)) 
   {
    digitalWrite(ledPin1, 0); 
    digitalWrite(ledPin2, 1);
    digitalWrite(ledPin3, 0);
    SLEDs.setPixelColor(0,SLEDs.Color(0,  0,  0));
    SLEDs.setPixelColor(1,SLEDs.Color(0,  0,  0));
    SLEDs.show();
    tone(buzzer, 0);
   }
   else if(t<27)
   {
    digitalWrite(ledPin1, 0); 
    digitalWrite(ledPin2, 0);
    digitalWrite(ledPin3, 1);
    SLEDs.setPixelColor(0,SLEDs.Color(0,  0,  250));
    SLEDs.setPixelColor(1,SLEDs.Color(0,  0,  250));
    SLEDs.show();
    tone(buzzer, 0);
   }
  }

   
