#include "Arduino.h"
#include "../components/ESP32-DMX/src/dmx.h"

int readcycle = 0;

void setup(){
  Serial.begin(250000);
  DMX::Initialize(input);
}

void loop(){
  if(millis() - readcycle > 1000)
  {
    readcycle = millis();

    Serial.print(readcycle);
      
    if(DMX::IsHealthy())
    {
      Serial.print(": ok - ");
    }
    else
    {
      Serial.print(": fail - ");
    }
    Serial.print(DMX::Read(1));
    Serial.print(" - ");
    Serial.print(DMX::Read(110));
    Serial.print(" - ");
    Serial.println(DMX::Read(256));
  }
}