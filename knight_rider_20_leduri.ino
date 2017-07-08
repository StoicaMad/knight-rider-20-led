int pinArray[] = {A6,A6,A5,A4,A3,A2,A1,A0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,A6,A6};
 
int pinCount = 24;
int activePin = 1;
int dx = 1;
 int mintime = 0;
 
 void setup() {
 
  for (int i=0; i< pinCount; i++) {
    if (pinArray[i] != -1) {
      pinMode(pinArray[i], OUTPUT);
    }
  }
}
 
void loop() {
 
 for (int i=0; i<pinCount; i++) {
    digitalWriteNot(pinArray[i], LOW);
  }
 
  if (activePin == (pinCount-1)) {
    activePin = (pinCount - 2);
    dx = -1;
  }
 
 if (activePin == 0) {
    activePin = 1;
    dx = 1;
  }
 
   activePin += dx;
 

 
  
    digitalWriteNot(pinArray[activePin], HIGH);
     digitalWriteNot(pinArray[activePin-dx], HIGH);
    digitalWriteNot(pinArray[activePin-2*dx], HIGH);


 
  delay(20);
 
}
 
void digitalWriteNot(int pin, boolean state) {
  if (pin > -1) {
    digitalWrite(pin, state);
  }
}
