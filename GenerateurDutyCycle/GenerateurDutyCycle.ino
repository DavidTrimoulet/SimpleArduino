#define sortie 9
#define freq 100
#define dutyCycle 5 // 100/dutycycle 10 pour 10%, 20 pour 5%

void setup() {
  // put your setup code here, to run once:
  pinMode(sortie, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int period = 1000/freq;
  int time = period / dutyCycle;
  digitalWrite(sortie, HIGH);
  delay(time);
  digitalWrite(sortie, LOW);
  delay(period - time);
}
