#define button 4
#define led1 5
#define led2 6 
#define buttonPress digitalRead(button)
#define led1On digitalWrite(led1, HIGH)
#define led1Off digitalWrite(led1, LOW)
#define led2On digitalWrite(led2, HIGH)
#define led2Off digitalWrite(led2, LOW)
#define led1State digitalRead(led1)
#define led2State digitalRead(led2)

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(buttonPress)
    if(led1State){
      led1Off;
      led2On;
      delay(1000);
      }
     else {
       led2Off;
       led1On;
       delay(1000);
       }
}
