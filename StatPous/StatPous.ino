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

int compteur1;
int compteur2;

void setup() {
  // put your setup code here, to run once:
  pinMode (pous1, INPUT_PULLUP);
  pinMode (pous2, INPUT_PULLUP);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  //Serial.begin(9600);
  compteur1 = 0;
  compteur2 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(pous1Pressed){ compteur1++; }
  if(pous2Pressed){ compteur2++; }
  
  //Serial.println(compteur1);
  //Serial.println(compteur2);
  
  if(compteur1 == compteur2)
  {
    led1Off;
    led2Off;
  }
  else if(compteur1 > compteur2)
  {
    led1On;
    led2Off;
  }
  else
  {
    led1Off;
    led2On;
  }
  delay(200);
}
