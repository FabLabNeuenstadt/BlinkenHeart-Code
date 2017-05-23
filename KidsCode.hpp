#include "BlinkenHeartLib.hpp"
#include "Vars.hpp"

void Rotation1();
void Rotation2();

void anim(){
  switch(curAnim){
    case 0:
    {
      Rotation1();
    }break;
    case 1:
    {
      Rotation2();
    }break;
    default:
    {
      clearLeds();
      setLed(1,true);  
    }
  }
}

//Some animations

void Rotation1(){
  if((millis() - lastMillis) > 1000){
    lastMillis = millis();
    count++;
    if(count >= 4){
      count = 0;
    }

    clearLeds();
    setLed(1+count, true);
    setLed(5+count, true);
    setLed(9+count, true);
  }
}

void Rotation2(){
  if((millis() - lastMillis) > 1000){
    lastMillis = millis();
    count++;
    if(count >= 2){
      count = 0;
    }

    clearLeds();
    setLed(1+count, true);
    setLed(3+count, true);
    setLed(5+count, true);
    setLed(7+count, true);
    setLed(9+count, true);
    setLed(11+count, true);
  }  
}

