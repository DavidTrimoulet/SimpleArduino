#define led1 4
#define led2 5
#define pous1 2
#define led1On digitalWrite(led1, HIGH)
#define led1Off digitalWrite(led1, LOW)
#define led2On digitalWrite(led2, HIGH)
#define led2Off digitalWrite(led2, LOW)
#define pous1Pressed !digitalRead(pous1)

unsigned long myDelay = 1000;
unsigned long time;
int up;
int periode;
unsigned long tic;
unsigned long lastTic;
//Periode = temps entre 2 flancs montants
//dutyCycle = temps haut durant une période
//Frequence entre 1 et 100 donc des periodes de 1 seconde à 10ms

void pic(){
  periode = tic - lastTic;
  lastTic = tic;
}


void setup() {
  // put your setup code here, to run once:
  sei();
  //enable interruption
  attachInterrupt(0 , pic , RISING); 
  pinMode (pous1, INPUT_PULLUP);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  tic = millis();
  if(!pous1Pressed){
    up++;  
  }
  
  delay(1);
  
  if(time >= periode){
    byte dutyCycle = (up * 100) / periode;
    if(dutyCycle < 40){ led1On; led2Off;
      }else if (dutyCycle > 60 ){ led2On; led1Off;
        }else{ led1Off; led2Off; }
    up=0;
    time = 0;
  }
  time++;
}
