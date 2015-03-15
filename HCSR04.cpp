/*
  HCSR04.cpp - Library for sensor HCSR04.
  Thierry VIEIL - March, 2015
*/

#include  <Arduino.h>
#include "HCSR04.h"


HCSR04::HCSR04(int Trigger,int Echo){
	
	//We define pins function of the sensor
	
  pinMode(Trigger, OUTPUT);
  _Trigger = Trigger;
  
    pinMode(Echo, INPUT);
  _Echo = Echo;
}

float  HCSR04::ping(int Divider,int shift)
{

	// we wait 60 mS to 
	// prevent the capture
	// of an echo due to reflection
	// of the ultrasonic wave
	
	//Delay 10 mS x 6
	for (int i =0;i<6;i++) {
	delayMicroseconds(10000);
	}
	
  // long  : range  from -2,147,483,648 to 2,147,483,647. 
   long BeginChrono,EndChrono,DeltaChrono =0;
  
  BeginChrono  = micros();
  
  digitalWrite(_Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(_Trigger, LOW);
  
	//if Echo is never received we have
	//to quit with -1 value
  while(digitalRead(_Echo) != true) {
	  unsigned int test = micros();
   if (test - BeginChrono> 60000) {return -1;}	  }  
  
  while(digitalRead(_Echo) == true) { 			//Echo begin wait until echo response end
  EndChrono = micros();
  DeltaChrono = EndChrono - BeginChrono;

  if (DeltaChrono > 60000) {return -2;} 
  if (DeltaChrono < 0) {return -3;}
  }
  
 DeltaChrono = DeltaChrono-shift;
  
  return float(DeltaChrono)/Divider;
  
}

