#include <Arduino.h>
int LO=8;
int LI=9;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LO,INPUT);
  pinMode(LI,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if((digitalRead(LO)==1)||(digitalRead(LI)==1)){
    Serial.print("!");
    
  }
  else{
    Serial.println(analogRead(0));
  }
  delay(1);
}