//
// Created by SALHI Lamia et Tahar et raphi la malice et renax le renard on 07/03/2020.
//
#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
//#include <XL430.h>
//#include "DynamixelManager.h"

int Pin1= 4;
void setup(){
// bouton poussoir
    // initialize serial communication:
Serial.begin(9600);

pinMode(Pin1, INPUT_PULLUP);
// Neopixel
// code XL
}
void loop(){
    // bouton poussoir
    if (digitalRead(Pin1) == LOW )
    {
        Serial.write("Allumée");
    }
    else
    {
        Serial.write("Éteint");
    }
// Neopixel
// code XL
}