#define button1 4
#define button2 5
#define led 6
#define button1Press digitalRead(button1)
#define button2Press digitalRead(button2)
#define ledOn digitalWrite(led, HIGH)
#define ledOff digitalWrite(led, LOW)

byte compteur = B000;


void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  Serial.println(compteur);
  // put your main code here, to run repeatedly:
  if(button1Press && compteur < B111 ){
    compteur++;  
  }
  
  if(button2Press && compteur > B000 ){
    compteur--;  
  }
  
  if(compteur % 2 == 0){
     ledOn;
  }
  else{
     ledOff;
  }
  delay(200);
}
