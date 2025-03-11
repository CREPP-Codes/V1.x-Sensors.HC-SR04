/*
 * This program is free software; you can redistribute it and/or
 * modify without any restriction
 */

/*
 *   Libraries
 */
#include <Arduino.h>

#define TRIG_PIN D5  // Broche de déclenchement
#define ECHO_PIN D6  // Broche de réception

void setup() 
{
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = (duration * 0.0343) / 2; // Conversion en cm

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500);
}