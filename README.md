# MAX30102 Arduino BPM

This project documents a clear and reliable method for measuring heart rate using the MAX30102 optical sensor with an Arduino Uno. It focuses on stable initialization, consistent sampling, and readable serial output of detected beats per minute. The implementation uses the SparkFun MAX3010x library within a PlatformIO environment.

## Purpose

The project provides a focused BPM workflow using the MAX30102. It is intended for users who want a dependable heart rate measurement setup without additional features such as SpO2 calculation or extended signal processing.

## Hardware

Arduino Uno  
MAX30102 sensor module  
Jumper wires  
USB connection for serial output  

## Wiring

The MAX30102 communicates over I2C. On the Arduino Uno, SDA is on A4 and SCL is on A5.

VIN to 5V  
GND to GND  
SDA to A4  
SCL to A5  
INT is not required  

The sensor surface must remain unobstructed. Header pins placed too close to the sensing area can interfere with finger contact.

## PlatformIO Setup

The project uses the Arduino framework and the SparkFun MAX3010x library. The configuration includes the Uno board definition and a 9600 baud serial monitor setting. No additional flags or speed adjustments are required.

## How It Works

The firmware initializes the MAX30102, enables the onboard LEDs, and reads infrared values. A beat detection algorithm analyzes the incoming signal and identifies rising edges that correspond to heartbeats. When a beat is detected, the time between beats is used to calculate BPM, which is printed to the serial monitor.

## Usage

Connect the MAX30102 to the Arduino Uno.  
Upload the firmware through PlatformIO.  
Open the serial monitor at 9600 baud.  
Place a finger firmly on the sensor surface.  
BPM values appear when beats are detected.  

Stable contact is required for consistent readings. Movement or loose placement can reduce signal quality.

## Notes

The MAX30102 requires firm and consistent pressure for accurate readings.  
The Uno has limited memory, so this project focuses on BPM only.  
The sensor may take a moment to stabilize before beats are detected.

## License

MIT License
