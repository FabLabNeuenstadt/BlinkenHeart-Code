#include "BlinkenHeartLib.hpp"

void Rotation1(){
  if((millis() - lastMillis) > 1000){
    lastMillis = millis();

    clearLeds();
    setLed(frame, true);
    setLed(4+frame, true);
    setLed(8+frame, true);

    frame++;
    if(frame >= 5){
      frame = 1;
    }
  }
}

void Rotation2(){
  if((millis() - lastMillis) > 1000){
    lastMillis = millis();

    clearLeds();
    setLed(frame, true);
    setLed(2+frame, true);
    setLed(4+frame, true);
    setLed(6+frame, true);
    setLed(8+frame, true);
    setLed(10+frame, true);

    frame++;
    if(frame >= 3){
      frame = 1;
    }
  }  
}

void Rotation3(){
  if((millis() - lastMillis) > 200){
    lastMillis = millis();

    clearLeds();
    setLed(frame, true);

    frame++;
    if(frame >= 13){
      frame = 1;
    }
  }
}

void setup() {
  lastMillis = millis();
  buttonSetup();

  Animationen = 3;
}

void loop() {
  buttonLoop();

  switch(curAnim){
    case 1:
    {
      Rotation1();
    }break;
    case 2:
    {
      Rotation2();
    }break;
    case 3:
    {
      Rotation3();
    }break;
    default:
    {
      clearLeds();
      setLed(1,true);  
    }
  }

  doLeds();
}
