#define button 4
#define led 5
#define buttonPress digitalRead(button)
#define ledOn digitalWrite(led, HIGH)
#define ledOff digitalWrite(led, LOW)


void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(buttonPress) { ledOn; delay(2000); ledOff;}
}
