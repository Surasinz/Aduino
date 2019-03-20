#define ledPin1 D0    // Define pin name
#define swl D5
int st_swl = 0;
void setup() 
{
  pinMode(swl, INPUT);
  pinMode(ledPin1, OUTPUT);
}

void loop() 
{
  st_swl = digitalRead(swl);
  digitalWrite(ledPin1,not(st_swl)); 
}
