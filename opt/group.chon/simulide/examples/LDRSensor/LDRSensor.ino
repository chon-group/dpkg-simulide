#include <Javino.h> // https://javino.chon.group/
#define pinLDR A0
Javino javino;

void serialEvent(){
  javino.readSerial();
}

void setup() {
  pinMode(pinLDR, INPUT);
  javino.perceive(getExogenousPerceptions);
  javino.start(9600);
}



void loop() {
  javino.run();
}


void getExogenousPerceptions(){ 
	javino.addPercept("device(arduinoLightSensor)");
	javino.addPercept("lightSensor("+String(analogRead(pinLDR))+")");
}