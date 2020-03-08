//
// Created by SALHI Lamia et Tahar et raphi la malice et renax le renard on 07/03/2020.
//
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <XL430.h>
#include "DynamixelManager.h"
#include "changementID.h"

#define PIN 25
Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, PIN, NEO_GRB + NEO_KHZ400);
int Pin1 = 26;
float Angle;

DynamixelManager *manager;

DynamixelMotor *motor1;

void setup() {
// bouton poussoir
// initialize serial communication:
    Serial.begin(9600);
    pinMode(Pin1, INPUT_PULLUP);

// Neopixel
    pinMode(OUTPUT, 25);
    strip.begin();
    strip.show(); // Initialise tous les pixels à 'off' (éteint)

// code XL
    Serial2.begin(57600);
    manager = new DynamixelManager(4, -1); // Manageur qui permet de communiquer avec les XL
    //manager = new DynamixelManager(new HardwareSerial(2)); //FIXME: je sais pas laquelle declaration utiliser
    motor1 = manager->createMotor(1 /* ID du XL */, XL430GeneratorFunction); // XL avec l'ID 1
    motor1->changeLED(true); // allume la LED du XL 1
    delay(1000);
    motor1->changeLED(false);
    bool tot;
    motor1->toggleTorque(false);
    while (true) {
        motor1->changeLED(tot);
        float output;
        motor1->getCurrentAngle(output);
        Serial.println(output);
        delay(500);
        tot = !tot;
    }
}
void loop(){}
/*
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

void loop(){
    // bouton poussoir
    if (digitalRead(Pin1) == LOW )
    {
        Serial.print("Allumée");
        led();
    }
    else
    {
        Serial.print("Éteint");
    }
// Neopixel

// code XL
}
*/