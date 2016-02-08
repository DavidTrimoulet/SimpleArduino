#define p1 2
#define p2 3
#define led1 4
#define led2 5
#define led3 6
#define led4 7
#define p1Pressed !(PIND&1<<p1)
#define p2Pressed !(PIND&1<<p2)

void recule(){
  PORTD = 0b10010000;
    //Serial.println("recule");
  }
  
void avance(){
  PORTD = 0b01100000;
  //Serial.println("avance");
}

void tourneDroite(){
  PORTD = 0b01010000;
    //Serial.println("tourneDroite");
}

void tourneGauche(){
  PORTD = 0b10100000;
    //Serial.println("tourneGauche");
}
  
void setup() {
  // put your setup code here, to run on.ce:
  DDRD |= 0b11110000;
  PORTD |= 1<<p1;
  PORTD |= 1<<p2;
  //Serial.begin(9600);
}

void loop(){
  // put your main code here, to run repeatedly:
   if(!p1Pressed && !p2Pressed){ avance();} 
    else{ 
      if(p1Pressed){ recule(); delay(1000); tourneGauche(); delay(500); 
    //Serial.println("P1 à gauche"); 
  }
      if(p2Pressed){ recule(); delay(1000); tourneDroite(); delay(500); 
  //  Serial.println("P2 à droite"); 
  }
   
   } 
}
