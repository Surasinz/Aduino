#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1
Adafruit_SSD1306 OLED(OLED_RESET);
void setup()
{
  Serial.begin(9600);
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
void loop() {
  OLED.clearDisplay();
  OLED.setTextColor(WHITE);
  OLED.setCursor(15,5);
  OLED.setTextSize(2);
  OLED.println("LOVE");
  OLED.setCursor(35,30);
  OLED.setTextSize(2);
  OLED.println("YOU!!");
  OLED.display();
}
