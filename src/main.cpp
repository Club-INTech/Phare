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
int Pin1= 26;
float Angle;

DynamixelManager* manager ;



DynamixelMotor* motor1;
//DynamixelMotor* motor2 = manager->createMotor(2 /* ID du XL */, XL430GeneratorFunction); // XL avec l'ID 2

void setup(){
// bouton poussoir
// initialize serial communication:
Serial.begin(9600);
manager = new DynamixelManager(2,2); // Manageur qui permet de communiquer avec les XL
    motor1 = manager->createMotor(1 /* ID du XL */, XL430GeneratorFunction); // XL avec l'ID 1
pinMode(Pin1, INPUT_PULLUP);
// Neopixel
    pinMode(OUTPUT,25);
    strip.begin();
    strip.show(); // Initialise tous les pixels à 'off' (éteint)
// code XL
    motor1->changeLED(true); // allume la LED du XL 1
//    motor2->changeLED(true); // allume la LED du XL 2
delay(1000);
motor1->changeLED(false);
bool tot;
    motor1->toggleTorque(false);
    while(true){
        motor1->changeLED(tot);
        delay(500);
        tot = !tot;
    }
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
void loop() {
    boolean recu=motor1->getCurrentAngle(Angle);
    Serial.print("Bien recu:");
    Serial.println((recu?"oui":"non"));
    Serial.println(Angle);
    delay(500);
}