#include <Wire.h>
#include <MAX30105.h>
#include "heartRate.h"

MAX30105 sensor;

void setup() {
    Serial.begin(9600);
    Serial.println("Serial OK");

    if (!sensor.begin(Wire, I2C_SPEED_FAST)) {
        Serial.println("MAX30102 not found.");
        while (1);
    }

    Serial.println("Sensor OK");
    sensor.setup();
    sensor.setPulseAmplitudeRed(0x0A);
    sensor.setPulseAmplitudeGreen(0);
}

void loop() { 
  long irValue = sensor.getIR();

    if (checkForBeat(irValue)) {
        static long lastBeat = 0;
        long delta = millis() - lastBeat;
        lastBeat = millis();
        float bpm = 60.0 / (delta / 1000.0);
        Serial.print("BPM=");
        Serial.println(bpm);
    }
}
