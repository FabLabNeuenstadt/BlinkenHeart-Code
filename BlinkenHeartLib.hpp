#ifndef BLINKENHEARTLIB_HPP
#define BLINKENHEARTLIB_HPP

#include "Vars.hpp"

#define off 6 //off-time der LED
#define on  36 //on-time der LED
#define ButtonPin 4 //Taster PIN

byte leds[12][2] = {{3,1},{0, 2},{1, 2},{3, 2},{0, 3},{1, 3},{2, 3},{1, 0},{2, 0},{3, 0},{0, 1},{2, 1}}; //Array LEDs

bool states[4][4] = {{false, false, false, false}, {false, false, false, false}, {false, false, false, false}, {false, false, false, false}}; //Alle LEDS aus initialisieren
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
      frame = 1;
      curAnim++;
      if(curAnim >= (Animationen+1))
        curAnim = 1;
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
  for(char i = 0; i < 4; i++){
    
    //Is the pin disabled?
    if(states[i][i] == true){
      pinMode(i, OUTPUT);
      
      //Sub-loop through all pins
      for(char j = 0; j < 4; j++){

        //Is the pin the same pin or is the pin disabled
        if(i != j && states[i][j] == true){
          pinMode(j, OUTPUT);
        }
      }

      digitalWrite(i, HIGH);
      delayMicroseconds(4*on);
      digitalWrite(i, LOW);
      pinMode(i, INPUT);
      delayMicroseconds(4*off);
      
      for(char j = 0; j < 4; j++){
        pinMode(j, INPUT);
      }
      
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
