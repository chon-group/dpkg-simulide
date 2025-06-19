#include <Javino.h>   /* https://javino.chon.group */
#include <DHT12.h>    /* https://www.arduino.cc/reference/en/libraries/dht12-sensor-library/ */ 

#define PinDHT12  4 
#define PinMQ02   2
#define LedRed    5 
#define LedGreen  3 
#define PinBuzzer 11 

Javino javino;      
DHT12 dht12(PinDHT12, true);

void setup() {
 javino.act["alert"]  = alertFunction;      
 javino.act["standby"] = standbyFunction;
 javino.perceive(getExogenousPerceptions);
 javino.start(9600);
 pinMode(PinDHT12,INPUT); 
 pinMode(PinMQ02,INPUT); 
 pinMode(PinBuzzer,OUTPUT);  
 pinMode(LedRed,OUTPUT); 
 pinMode(LedGreen,OUTPUT); 
}

void serialEvent(){ 
  javino.readSerial(); 
}

void loop() {  
  javino.run(); 
}

void alertFunction(){ 
  digitalWrite(LedRed,HIGH); 
  digitalWrite(LedGreen,LOW);  
  tone(PinBuzzer, 1000); 
}

void standbyFunction(){ 
  digitalWrite(LedRed,LOW); 
  digitalWrite(LedGreen,HIGH);  
  noTone(PinBuzzer); 
}

void getExogenousPerceptions(){
	javino.addPercept("device(smokeAndTemperatureDetector)");
  if(digitalRead(PinMQ02) == 0){ 
    javino.addPercept("smoke(false)");
  } else{ 
    javino.addPercept("smoke(true)"); 
  }
  
  float temperature = dht12.readTemperature();  
  javino.addPercept("temperature("+String(temperature)+")");

  float humidity = dht12.readHumidity();
  javino.addPercept("humidity("+String(humidity)+")");
}
