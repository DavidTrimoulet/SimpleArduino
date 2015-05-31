#define led 4
#define ledOn digitalWrite(led, HIGH)
#define ledOff digitalWrite(led, LOW)
#define court 200
#define along 600
#define between 1200

char sos[3] = {'s','o','s'};
char s[3] = {'.','.','.'};
char o[3] = {'-','-','-'};


void playLetter(char *c){
  byte i;
  for(i=0; i<3; i++){
    if(c[i] == '.'){ ledOn; delay(court); ledOff; }
    if(c[i] == '-'){ ledOn; delay(along); ledOff; }
    if(i != 2){
      delay(court);  
     }
  }
  
}

void pickLetter(char c){
  switch(c){
    case 's':
        playLetter(s);
        break;
    case 'o':
        playLetter(o);
        break;
    default:
        break;
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode (led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte i = 0;
  for(i=0;i < 3 ; i++){
          pickLetter(sos[i]);
          delay(along);  
  }
  delay(between);
}

