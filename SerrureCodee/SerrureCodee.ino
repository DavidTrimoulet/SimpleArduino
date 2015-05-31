#define led1 4
#define led2 5
#define pous1 2
#define pous2 3
#define led1On digitalWrite(led1, HIGH)
#define led1Off digitalWrite(led1, LOW)
#define led2On digitalWrite(led2, HIGH)
#define led2Off digitalWrite(led2, LOW)
#define pous1Pressed !digitalRead(pous1)
#define pous2Pressed !digitalRead(pous2)

byte sequence;

void setup() {
  // put your setup code here, to run once:
  pinMode (pous1, INPUT_PULLUP);
  pinMode (pous2, INPUT_PULLUP);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  Serial.begin(9600);
  sequence = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(pous1Pressed && sequence == 0){ sequence = 1; }
  if(pous1Pressed && pous2Pressed && sequence == 1 ){ sequence = 2; }
  if(pous1Pressed && !pous2Pressed && sequence == 2) { sequence = 3; }
  
  if(!pous1Pressed && !pous2Pressed && sequence == 3 ) { sequence = 4; led1On; delay(3000); }
  
  if( sequence == 4 ) { led1Off; sequence =0 ; delay(1000); }
  Serial.println(sequence);
}
