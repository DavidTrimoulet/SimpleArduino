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

byte stepCount = 0;

void moveToNextStep(){
  switch(stepCount){
    
    case 0 :
      led1Off;
      led2Off;
      
      break;
    
    case 1 :
      led1On;
      led2Off;
             
      break;
      
    case 2 :
      led1On;
      led2On;
      
      break;
      
    case 3 :
      led1Off;
      led2On;
      
      break;
      
    default:
      break;
    }
  
}

void setup() {
  // put your setup code here, to run once:
  pinMode (pous1, INPUT_PULLUP);
  pinMode (pous2, INPUT_PULLUP);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(pous1Pressed){
      stepCount++;    
  }
  if(pous2Pressed){
    stepCount--;
  }
  if(stepCount == 4){ stepCount = 0; }
  if(stepCount == 255){ stepCount = 3; }
  //Serial.println(stepCount);
  moveToNextStep();
  delay(200);
}
