#define led1 4
#define led2 5
#define entry A1

int time = 1023;
int minVal = 1023;
int maxVal = 0;
int val;

void avanceLentement(){
  PORTD = 0b00010000;
  delayMicroseconds(250);
  PORTD = 0b00000000;
  delayMicroseconds(750);
  }
  
void recule(int val){
    PORTD = 0b00100000;
    //digitalWrite(led2, HIGH);
    delayMicroseconds(val);
    PORTD = 0b00000000;
    //digitalWrite(led2, LOW);
    if(val < 0){ val =0; }
    delayMicroseconds(time-val);
}

void setup() {
  // put your setup code here, to run once:
  DDRD = 0b00110000;
  PORTD = 0b00000000;
  DDRC = 0b000000;
  PORTC = 0b000000;/*
  while(millis() < 5000){
    val = analogRead(entry);
    if(val > maxVal){ maxVal = val;}
    if(val < minVal){ minVal = val;}
  }
  Serial.begin(9600);
  */
}

void loop() {
  
  // put your main code here, to run repeatedly:
   val = analogRead(entry);
   val = map(val, minVal, maxVal, 0, 1023);
   Serial.println(val);
   if(val < (1023/2)){ avanceLentement();}
   else{ recule(val); }
   
}
