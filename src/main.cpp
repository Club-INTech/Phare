//
// Created by SALHI Lamia et Tahar et raphi la malice et renax le renard on 07/03/2020.
//
#include <Arduino.h>
#include "DynamixelManager.h"
#include "XL430.h"

#define Button 13
#define INTER_OP_DELAY 500

#define LED 14

void led(void);

const uint8_t MOTOR0_FINAL_POS[] = {255,255,253,0,0,9,0,3,116,0,196,7,0,0,184,185}; // 175°
const uint8_t MOTOR1_FINAL_POS[] = {255,255,253,0,1,9,0,3,116,0,167,8,0,0,114,101}; // 195°
const uint8_t MOTOR1_MEDIUM_POS_BIS[] = {255,255,253,0,1,9,0,3,116,0,242,5,0,0,142,97};//134°
const uint8_t MOTOR0_MEDIUM_POS[] = {255,255,253,0,0,9,0,3,116,0,254,5,0,0,153,113}; // 135°
const uint8_t MOTOR1_MEDIUM_POS[] = {255,255,253,0,1,9,0,3,116,0,254,3,0,0,246,145}; // 90°
const uint8_t ENABLE_TORQUE[] = {255,255,253,0,254,6,0,3,64,0,1,43,150};
const uint8_t LEDS_ON[] {255,255,253,0,254,6,0,3,65,0,1,60,22};

DynamixelManager* manager;
DynamixelMotor* motor;

void setup() {
    /*
     //Ce code est utilisé pour déterminer les valeurs des paquets à envoyer
    Serial.begin(9600);
    manager = new DynamixelManager(2, -1, &Serial);
    motor = manager ->createMotor(1, XL430GeneratorFunction);
    motor->setGoalAngle(134);
    while (1);
    // */
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
    digitalWrite(LED_BUILTIN, HIGH);

// bouton poussoir
    pinMode(Button, INPUT_PULLUP);

    Serial2.begin(57600, SERIAL_8N1, 16, 17, false, 50);
    Serial2.write(LEDS_ON, sizeof(LEDS_ON));
}

void loop(){
    // bouton poussoir
    if (digitalRead(Button) == LOW ) {
        Serial.print("Allumée");
        led();
    }
}

void led(){
    Serial2.write(ENABLE_TORQUE, sizeof(ENABLE_TORQUE));

    Serial2.write(MOTOR1_MEDIUM_POS, sizeof(MOTOR1_MEDIUM_POS));

    delay(INTER_OP_DELAY);
    Serial2.write(MOTOR0_MEDIUM_POS, sizeof(MOTOR0_MEDIUM_POS));

    delay(2*INTER_OP_DELAY);
    Serial2.write(MOTOR1_MEDIUM_POS, sizeof(MOTOR1_MEDIUM_POS_BIS));

    delay(INTER_OP_DELAY);
    Serial2.write(MOTOR1_FINAL_POS, sizeof(MOTOR1_FINAL_POS));
    delay(INTER_OP_DELAY);
    Serial2.write(MOTOR0_FINAL_POS, sizeof(MOTOR0_FINAL_POS));
    delay(INTER_OP_DELAY);

    while (true) {
        digitalWrite(LED, HIGH);
    }
}