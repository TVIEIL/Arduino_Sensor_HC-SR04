/*
  HCSR04.h - Library  for sensor HCSR04
*/

#ifndef HCSR04_h
#define HCSR04_h

#include <Arduino.h>

class HCSR04
{
  public:
  HCSR04(int Trigger,int Echo);
     
   /*!
    @method
    @abstract   Sets all the pins of the device.
    @discussion This method sets all the pins of the device Trigger
    and Echo. 
    
    @param       Trigger[in] device pin to send pulses. Range (0..12).
    @param       Echo[out] to set the pin of answer device (0..12).
    */   
	
  float ping(int Divider, int shift);
     
   /*!
    @method
    @abstract   Starts calculating a distance.
    @discussion This method use this Formula: delay in uS / 58 = centimeters.
    
    @param      Divider[integer] divider of the formula (0..32,767).
    @para       shift[integer] offset at distance null.
    @result     Divider = 58; offset = 0 answer distance in centimeters
    */   
	
  private:
    int _Trigger;
    int _Echo;
};

#endif

