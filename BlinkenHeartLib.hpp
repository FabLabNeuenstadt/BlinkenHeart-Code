#ifndef BLINKENHEARTLIB_HPP
#define BLINKENHEARTLIB_HPP

#include "Vars.hpp"

#define off 20
#define on  60
#define ButtonPin 4

byte leds[12][2] = {{3,1},{0, 2},{1, 2},{3, 2},{0, 3},{1, 3},{2, 3},{1, 0},{2, 0},{3, 0},{0, 1},{2, 1}};

bool states[4][4] = {{false, false, false, false}, {false, false, false, false}, {false, false, false, false}, {false, false, false, false}};
long lastRead = 0;
long lastChange = 0;


//Button functions
void buttonSetup(){
  pinMode(ButtonPin, INPUT);
  digitalWrite(ButtonPin, HIGH);
}

void buttonLoop(){
  if(millis() - lastRead >= 50){
    lastRead = millis();
    if(!digitalRead(ButtonPin) && lastChange == 0){
      lastChange = lastRead;
      count = 0;
      curAnim++;
      if(curAnim >= 3)
        curAnim = 0;
    }
  }

  if(lastChange > 0){
    if(millis() - lastChange > 500){
      lastChange = 0;
    }
  }
}


//Set the leds for each cyle
void doLeds(){

  //Loop through all pins?
  for(int i = 0; i < 4; i++){
    
    //Is the pin disabled?
    if(states[i][i] == true){
      pinMode(i, OUTPUT);
      
      //Sub-loop through all pins
      for(int j = 0; j < 4; j++){

        //Is the pin the same pin or is the pin disabled
        if(i != j && states[i][j] == true){
          pinMode(j, OUTPUT);
          digitalWrite(i, HIGH);
          delayMicroseconds(on);
          digitalWrite(i, LOW);
          delayMicroseconds(off);
          pinMode(j, INPUT);
        }else{
          delayMicroseconds(off + on);
        }
      }
      pinMode(i, INPUT);
    }else{
      delayMicroseconds(4 * (on + off));
    }
  }
}

bool setLed(byte led, bool state){
  if(0 < led < 13){
    byte pin1 = leds[led-1][0];
    byte pin2 = leds[led-1][1];  
    states[pin1][pin2] = state;
    if(state == true){
      states[pin1][pin1] = state;
    }
  }
}

void clearLeds(){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      states[i][j] = false;
    }
  }
}


#endif
