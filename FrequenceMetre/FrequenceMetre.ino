#include "LcDef.h" 
volatile byte cSig; 
void CntSig () { 
  cSig++; 
} 
void setup () { 
  LcSetup (); 
  TCCR2A = 0; 
  TCCR2B = 0b00000111; // clk/1024 16kHz 64us 
  TIMSK2 = 0b00000001; // TOIE2 
  attachInterrupt(0,CntSig,RISING); 
  Serial.begin(9600); 
} 
volatile byte freq; 
ISR (TIMER2_OVF_vect) { 
  TCNT2 = -162; // pour 10ms = 162 x 64 us 
  freq = cSig; 
  cSig = 0; 
} 
void loop () { 
  delay (1000); 
  Serial.println(freq); 
}
