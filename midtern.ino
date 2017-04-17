#include "SevSeg.h"
SevSeg sevseg;
void setup() 
{
  Serial.begin(9600);
  Serial.println("11 04050060 04050521");
  byte numDigits = 4;
  byte digitPins[] = {8,4,3,7};
  byte segmentPins[] = {6,5,10,12,13,2,9,11};
 
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins,segmentPins);
}
void loop()
{
  int val;
   if(Serial.available() )
  {
      val=Serial.parseInt();
      
      if(val>=0 && val<=9999)
      {
        sevseg.setNumber(val);
        sevseg.refreshDisplay();
      }
     else
      {
         Serial.println("range error");
         sevseg.refreshDisplay();
      }
     
   }
   else
    {
        sevseg.refreshDisplay();
    }
}
