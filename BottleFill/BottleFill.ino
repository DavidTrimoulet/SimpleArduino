#define led1 4
#define pous1 2
#define pous2 3
#define led1On PORTD |= 1<<led1
#define led1Off PORTD &=~ 1<<led1
#define pous1Pressed !(PIND & 1<<pous1)
#define pous2Pressed !(PIND & 1<<pous2)

unsigned long count;
unsigned long time;
byte pressed = 0;
byte alreadypressed = 0;

void setup() {
  // put your setup code here, to run once:
  DDRD = 0b00010000;
  PORTD =0b00001100;
}

void loop() {
  // put your main code here, to run repeatedly:s
  if(alreadypressed && pous1Pressed) { time = 0; }
  while(pous1Pressed){ time++; led1On; delay(1); alreadypressed = 1; }
  led1Off;
  if(pous2Pressed) {  led1On; delay(time); led1Off; }
  
}
