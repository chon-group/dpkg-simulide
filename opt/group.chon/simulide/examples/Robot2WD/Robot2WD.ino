#include <Javino.h>               //Available at: https://javino.chon.group
#include <HCSR04.h>               //Available at: https://github.com/gamegine/HCSR04-ultrasonic-sensor-lib

#define PinLDR     A0              // LDR sensor
#define PinBatt    A5              // Energy sensor
#define PinBridH1  5               // HBridge IN1
#define PinBridH2  6               // HBridge IN2
#define PinEcho    7               // Ultrasonic sensor ECHO
#define PinTrig    8               // Ultrasonic sensor TRIG
#define PinBridH3  9               // HBridge IN3
#define PinBridH4  10              // HBridge IN4
#define PinBuzzer  11              // Buzzer
Javino javino;
HCSR04 hc(PinTrig, PinEcho);

unsigned long startTime; // Variável para armazenar o tempo inicial em milissegundos
unsigned long uptimeSeconds; // Variável para armazenar o tempo de funcionamento em segundos


void serialEvent(){
  javino.readSerial();
}

void setup() {
  pinMode(PinLDR,	INPUT);
  pinMode(PinBatt,	INPUT);
  pinMode(PinBridH1,  OUTPUT);
  pinMode(PinBridH2,  OUTPUT);
  pinMode(PinEcho,    INPUT);
  pinMode(PinTrig,    OUTPUT);  
  pinMode(PinBridH3,  OUTPUT);
  pinMode(PinBridH4,  OUTPUT);
  pinMode(PinBuzzer,  OUTPUT);  
  javino.perceive(getPerceptions);
  javino.act["buzzerOn"]		= buzzerOn;
  javino.act["buzzerOff"]	= buzzerOff;
  javino.act["goBack"] 		= goBack;
  javino.act["goAhead"]		= goAhead;
  javino.act["stopRightNow"]= stopRightNow;
  javino.act["turnRight"]	= turnRight;
  javino.act["turnLeft"]		= turnLeft;

  javino.start(9600);
  startTime = millis();
}



void loop() {
  javino.run();
}


void getPerceptions(){ 
	getExteroceptions();
	getInteroceptions();
	getProprioceptions();
}

void getExteroceptions(){
	int d = hc.dist();
	javino.addPercept("distance("+String(d)+")");
	javino.addPercept("luminosity("+String(analogRead(PinLDR))+")");
}

void getInteroceptions(){
	float batt = analogRead(PinBatt);
	float result = batt/1024;
	javino.addPercept("battery("+String(result)+")");
	uptimeSeconds = (millis() - startTime) / 1000;
	javino.addPercept("uptime("+String(uptimeSeconds)+")");
	javino.addPercept("device(agentBody)");
}


void getProprioceptions(){
	javino.addPercept(buzzerStatus());
	javino.addPercept(motorStatus());
	
}


void buzzerOn(){buzzer("on");}
void buzzerOff(){buzzer("off");}
void buzzer(String strOpt){
  if(strOpt=="on")analogWrite(PinBuzzer, 191);
  else digitalWrite(PinBuzzer, LOW);
}

String buzzerStatus(){
	if(analogRead(PinBuzzer) > 150){
		return "buzzer(on)";
	}else{
		return "buzzer(off)";
	}
}


void goBack(){
    analogWrite(PinBridH1, 255);
    analogWrite(PinBridH2, 0);
    analogWrite(PinBridH3, 255);
    analogWrite(PinBridH4, 0);
}

void goAhead(){
    analogWrite(PinBridH1, 0);
    analogWrite(PinBridH2, 255);
    analogWrite(PinBridH3, 0);
    analogWrite(PinBridH4, 255);
}


void stopRightNow(){
  analogWrite(PinBridH1, 0);
  analogWrite(PinBridH2, 0);
  analogWrite(PinBridH3, 0);
  analogWrite(PinBridH4, 0);
}

void turnRight(){
  analogWrite(PinBridH1, 255);
  analogWrite(PinBridH2, 0);
  analogWrite(PinBridH3, 0);
  analogWrite(PinBridH4, 255);
}


void turnLeft(){
  analogWrite(PinBridH1, 0);
  analogWrite(PinBridH2, 255);
  analogWrite(PinBridH3, 255);
  analogWrite(PinBridH4, 0);
}

String motorStatus(){
	if(digitalRead(PinBridH1)==HIGH && digitalRead(PinBridH3)==HIGH){
		return "motor(goBack)";
	}else if (digitalRead(PinBridH2)==HIGH && digitalRead(PinBridH4)==HIGH){
		return "motor(goAhead)";
	}else if(digitalRead(PinBridH1)==HIGH && digitalRead(PinBridH4)==HIGH){
		return "motor(turnRight)";
	}else if(digitalRead(PinBridH2)==HIGH && digitalRead(PinBridH3)==HIGH){
		return "motor(turnLeft)";
	}else if(digitalRead(PinBridH1)==LOW && digitalRead(PinBridH2)==LOW){
		return "motor(stop)";
	}
}
