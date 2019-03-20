/*
ขา VCC -> 3.3-5V
ขา Gnd-> Gnd
ขา I/O -> 13
*/
int buzzer = 14;  //D5
void setup() {
pinMode(buzzer, OUTPUT);
}
void loop() {
digitalWrite(buzzer, HIGH);
delay(1000);
digitalWrite(buzzer, LOW);
delay(1000);
}
