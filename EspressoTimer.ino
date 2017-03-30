
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
boolean ausgeloest = false ;
unsigned long time;

void setup() {
pinMode (3, INPUT_PULLUP);
  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);
  
}

void loop() {
if ( digitalRead(3) == false && ausgeloest == false ) {
  mySwitch.switchOn("11000", "10000");
  delay(6500); //mahlgrad 4
  mySwitch.switchOff("11000", "10000");
  ausgeloest = 1;
  time = millis();
}
if ( digitalRead(3) == false && ausgeloest == true ) {
  mySwitch.switchOn("11000", "10000");
  delay(500); //mahlgrad 4
  mySwitch.switchOff("11000", "10000");
  ausgeloest = true;
  time = millis();
}

if ( millis() - time > 20000 &&  ausgeloest == true ) {
  ausgeloest = false ;
  }
 Serial.print ( millis() - time);
 Serial.print ( ":");
 Serial.println ( ausgeloest);
}
