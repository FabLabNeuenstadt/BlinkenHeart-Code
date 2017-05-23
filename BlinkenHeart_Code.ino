#include "BlinkenHeartLib.hpp"
#include "KidsCode.hpp"

void setup() {
  lastMillis = millis();
  buttonSetup();
  delay(200);
}
void loop() {
  buttonLoop();

  anim();

  doLeds();
}
