#define serialLine 1<<4
#define vitesse 300
#define between 1000
#define S 0x53
#define O 0x4F



char sos[3] = {'s','o','s'};

void sendLetter(byte c){
  byte i;
  PORTD &=~ serialLine;
  delay(3);
  for(i=0; i<8; i++){
    if(c & 0x01){ PORTD |= serialLine ; }
    else{ PORTD &=~serialLine; }
    c>>=1;
    delay(3);
  }
  PORTD |= serialLine;
  delay(7);
  
}

void pickLetter(char c){
  switch(c){
    case 's':
        sendLetter(S);
        break;
    case 'o':
        sendLetter(O);
        break;
    default:
        break;
  }
}

void setup() {
  // put your setup code here, to run once:
  DDRD |= serialLine;
  PORTD |= serialLine;
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte i = 0;
  for(i=0; i < 3 ; i++){
          pickLetter(sos[i]);
  }
  PORTD |= serialLine;
  delay(1000);
  //Serial.println("");
}

