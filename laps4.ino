/*
ขา VCC -> 3.3-5V
ขา Gnd-> Gnd
ขา I/O -> 13
*/
int LED1= 13;  //D7
void setup() {
pinMode(LED1, OUTPUT);
}
void loop() {
digitalWrite(LED1, HIGH);
delay(1000);
digitalWrite(LED1, LOW);
delay(1000);
}
