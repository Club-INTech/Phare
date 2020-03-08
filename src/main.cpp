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
float Angle = 0;
int Pin1= 26;
void setup(){
// bouton poussoir
// initialize serial communication:
Serial.begin(9600);

pinMode(Pin1, INPUT_PULLUP);
// Neopixel
    pinMode(OUTPUT,25);
    strip.begin();
    strip.show(); // Initialise tous les pixels à 'off' (éteint)
// code XL
    DynamixelManager* manager = new DynamixelManager(33, 33); // Manageur qui permet de communiquer avec les XL
    changeID(manager);
    DynamixelMotor* motor1 = manager->createMotor(1 /* ID du XL */, XL430GeneratorFunction); // XL avec l'ID 1
    DynamixelMotor* motor2 = manager->createMotor(2 /* ID du XL */, XL430GeneratorFunction); // XL avec l'ID 2

    motor1->changeLED(true); // allume la LED du XL 1
    motor2->changeLED(true); // allume la LED du XL 2
    motor1->toggleTorque(false);
    motor1->getCurrentAngle((float &) Angle);
    Serial.print(Angle);
// répète à l'infini
    /*while(true) {
        motor1->setGoalAngle(90.0f); // fais aller le moteur 1 à 90°
        //motor2->setGoalAngle(270.0f); // fais aller le moteur 2 à 270°
        delay(500); // 500ms d'attente
        motor1->setGoalAngle(180.0f); // fais aller le moteur 1 à 180° (milieu)
        //motor2->setGoalAngle(180.0f); // fais aller le moteur 2 à 180° (milieu)
        delay(500); // 500ms d'attente
        motor1->setGoalAngle(270.0f); // fais aller le moteur 1 à 270°
        //motor2->setGoalAngle(90.0f); // fais aller le moteur 2 à 90°
        delay(500); // 500ms d'attente
    }
     */
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

void loop(){
    // bouton poussoir
    if (digitalRead(Pin1) == LOW )
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
