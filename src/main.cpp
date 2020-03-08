//
// Created by SALHI Lamia et Tahar et raphi la malice et renax le renard on 07/03/2020.
//

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define PIN 25
Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, PIN, NEO_GRB + NEO_KHZ400);

void setup(){
// bouton poussoir
// Neopixel
    pinMode(OUTPUT,25);
    strip.begin();
    strip.show(); // Initialise tous les pixels à 'off' (éteint)
// code XL
}
void loop(){
// bouton poussoir
// Neopixel
for (int i = 0; i<3; i++) {
    strip.setPixelColor(i, 255, 255, 255);
    strip.show();
    delay(100);
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
}

// code XL
}