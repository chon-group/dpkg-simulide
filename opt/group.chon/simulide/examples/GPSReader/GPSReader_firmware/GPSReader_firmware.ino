#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <Javino.h>

Javino javino;
SoftwareSerial gpsSerial(10, 11); // RX 10, TX 11
TinyGPSPlus gps;

void setup() {
 gpsSerial.begin(9600);
 javino.perceive(getGPSInfo);
 javino.start(9600);
}

void loop(){javino.run(); gpsReader();}

void serialEvent(){javino.readSerial();}

void gpsReader() {
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }
}

void getGPSInfo(){
	javino.addPercept("device(gpsReader)");
	if(gps.location.isValid()) {
		javino.addPercept("latitude("+String(gps.location.lat(), 6)+")");
		javino.addPercept("longitude("+String(gps.location.lng(), 6)+")");
	}
	if(gps.date.isValid()) {
		javino.addPercept("date("+String(gps.date.year())+","+String(gps.date.month())+","+String(gps.date.day())+")");
	}
	if(gps.time.isValid()) {
		javino.addPercept("time("+String(gps.time.hour())+","+String(gps.time.minute())+","+String(gps.time.second())+")");
    } 
	if(gps.altitude.isValid()) {
		javino.addPercept("altitude(meters,"+String(gps.altitude.meters())+")");
    }
    if(gps.speed.isValid()) {
		javino.addPercept("speed(kmph,"+String(gps.speed.kmph())+")");
    }
    if (gps.course.isValid()) {
		javino.addPercept("course("+String(gps.course.deg())+")");
    }
    javino.addPercept("satellites("+String(gps.satellites.value())+")");
    javino.addPercept("hdop("+String(gps.hdop.hdop())+")");
}