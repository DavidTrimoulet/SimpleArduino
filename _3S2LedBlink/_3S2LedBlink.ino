#define led1 4
#define led2 5
#define pous1 2
#define pous2 3
#define led1Toggle digitalWrite(led1, !digitalRead(led1))
#define led2Toggle digitalWrite(led2, !digitalRead(led2))
#define pous1Pressed !digitalRead(pous1)
#define pous2Pressed !digitalRead(pous2)


void setup() {
  // put your setup code here, to run once:
  pinMode (pous1, INPUT_PULLUP);
  pinMode (pous2, INPUT_PULLUP);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(pous1Pressed){
    led1Toggle;
    delay(1000);
    led2Toggle;
    delay(1000);
    led1Toggle;
    delay(1000);
    led2Toggle;
  }
  
}
