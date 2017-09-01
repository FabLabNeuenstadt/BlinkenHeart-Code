#include "BlinkenHeartLib.hpp"

void Programm1(){
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

void Programm2(){
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

void Programm3(){
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

void Programm4(){
  if((millis() - lastMillis) > 50){
    lastMillis = millis();

    if(frame > 43)
      frame = 1;

    clearLeds();
    if(frame < 22){
      for(byte i = 1; i < 13; i++){
        setLed(i, true, 21-frame);
      }
    }else if(frame < 44){
      for(byte i = 1; i < 13; i++){
        setLed(i, true, frame-22); 
      }
    }

    frame++;
  }
}

void setup() {
  lastMillis = millis();
  buttonSetup();

  Animationen = 4;
}

void loop() {
  buttonLoop();

  switch(curAnim){
    case 1:
    {
      Programm1();
    }break;
    case 2:
    {
      Programm2();
    }break;
    case 3:
    {
      Programm3();
    }break;
    case 4:
    {
      Programm4();
    }break;
    default:
    {
      clearLeds();
      setLed(1,true);  
    }
  }

  doLeds();
}
