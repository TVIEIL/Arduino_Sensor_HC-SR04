#include "HCSR04.h"


/*
	Use HC-SR04 with Arduino Uno
	Digital 8 is the trigger pin
	Digital 9 is the Echo pin

	8 <-> Trig
	9 <-> Ech
	GND <-> GND
	5V  <-> Vcc 
	
	I made test with HC-SR04 and US-015
*/

HCSR04 Sensor1(8,9);

float DistanceCm = 0;

void setup()
{
 Serial.begin(9600);
}

void loop()
{
    
 DistanceCm = Sensor1.ping(58,500);   // Formula: uS / 58 = centimeters ; 500 = offset HC-SR0; 615 = offset US-015
 Serial.println(DistanceCm);          // View value of distance in cm with the serial
  
  /* Error Values
   -1 : Echo never received
   -2 : Echo time has a value too big
   -3 : Echo has a negative value
   */
  
}


