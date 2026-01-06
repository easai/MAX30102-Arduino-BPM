#include <Arduino.h>
#include <unity.h>
#include <Wire.h>
#include <MAX30105.h>

MAX30105 sensor;

void test_sensor_detected() {
    bool ok = sensor.begin(Wire);
    TEST_ASSERT_TRUE_MESSAGE(ok, "MAX30102 not detected");
}

void test_read_values() {
    long ir = sensor.getIR();
    long red = sensor.getRed();

    // Print for human inspection
    Serial.print("IR=");
    Serial.print(ir);
    Serial.print("  RED=");
    Serial.println(red);

    // Basic sanity check: values should be >= 0
    TEST_ASSERT_TRUE(ir >= 0);
    TEST_ASSERT_TRUE(red >= 0);
}

void test_temperature() {
    float temp = sensor.readTemperature();
    Serial.print("Temp=");
    Serial.println(temp);

    TEST_ASSERT_TRUE(temp > -40);
    TEST_ASSERT_TRUE(temp < 85);
}

void test_spo2_buffer() {
    const int n = 50;
    uint32_t ir[n];
    uint32_t red[n];

    for (int i = 0; i < n; i++) {
        ir[i] = sensor.getIR();
        red[i] = sensor.getRed();
        delay(20);
    }

    TEST_ASSERT_TRUE(ir[0] >= 0);
    TEST_ASSERT_TRUE(red[0] >= 0);
}

void setup() {
    delay(2000); // allow serial to settle
    Serial.begin(9600);
    Wire.begin();

    UNITY_BEGIN();

    RUN_TEST(test_sensor_detected);
    RUN_TEST(test_temperature);
    RUN_TEST(test_spo2_buffer);

    // Configure sensor only if detected
    if (sensor.begin(Wire)) {
        sensor.setup();
        RUN_TEST(test_read_values);
    }

    UNITY_END();
}

void loop() {
    // not used in tests
}
