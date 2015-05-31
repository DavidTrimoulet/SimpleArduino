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

byte compteur = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (pous1, INPUT_PULLUP);
  pinMode (pous2, INPUT_PULLUP);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(pous1Pressed && compteur < 255){
    compteur++;
  }  
  
  if(pous2Pressed && compteur > 0){
    compteur--;
  }
  
  if(compteur > 4){
    led1On;
  }
  else{
    led1Off;
  }
  
  if(compteur == 0){
    led2On;  
  }
  else{
    led2Off;
   }
   
   delay(20);
}
