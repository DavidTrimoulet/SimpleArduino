#define led1 4
#define led2 5
#define pota A1
#define led1On digitalWrite(led1, HIGH)
#define led1Off digitalWrite(led1, LOW)
#define led2On digitalWrite(led2, HIGH)
#define led2Off digitalWrite(led2, LOW)
#define AlimValue 1023


void setup() {
  // put your setup code here, to run once:
  pinMode (pota, INPUT);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  int val = analogRead(pota);
  //Serial.println(AlimValue*0.75);
  //Serial.println(val);
  
  if(val > AlimValue*0.75){ led1On; led2On; }
  else { 
      if(val > AlimValue*0.50) { led1Off; led2On; }
      else {
        if(val > AlimValue*0.25) { led1On; led2Off; }
        else { led1Off; led2Off; }
          }
        }
}
