//
// Created by SALHI Lamia et Tahar et raphi la malice et renax le renard on 07/03/2020.
//

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
//#include <XL430.h>
//#include "DynamixelManager.h"
#define PIN 25
Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, PIN, NEO_GRB + NEO_KHZ400);

void setup(){
// bouton poussoir
    // initialize serial communication:
Serial.begin(9600);
pinMode(4, INPUT_PULLUP);
// Neopixel
    pinMode(OUTPUT,25);
    strip.begin();
    strip.show(); // Initialise tous les pixels à 'off' (éteint)
// code XL
}
void loop(){
    // bouton poussoir
    if (digitalRead (4)== LOW)
    {
        Serial.write("Allumée");
        led();
    }
    else
    {
        Serial.write("Éteint");
    }
// Neopixel

// code XL
}

void led(){
    while (true) {
        for (int i = 0; i<3; i++) {
            strip.setPixelColor(i, 255, 255, 255);
            strip.show();
            delay(100);
            strip.setPixelColor(i, 0, 0, 0);
            strip.show();
        }
    }
}