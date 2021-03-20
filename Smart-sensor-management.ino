#include <Adafruit_CircuitPlayground.h>
#include "Light.h"
#include "Button1.h"
#include "LightSensor.h"

bool rightButtonPressed;
int neoPixel = 0;
Light* light = new Light(neoPixel);
Button1* button_1 = new Button1();
LightSensor* lightSensor = new LightSensor();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:  
  int colorCode[] = {255, lightSensor->retrieveSensorData(), lightSensor->retrieveSensorData()};

  rightButtonPressed = CircuitPlayground.rightButton();

  if(button_1->retrieveSensorData()) {
    light->turnOn(colorCode);
  } else if(rightButtonPressed) {
    light->turnOff();
  }
}
