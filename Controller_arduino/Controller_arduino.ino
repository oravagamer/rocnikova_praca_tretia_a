#include <Arduino.h>
#include <BleGamepad.h>

#define STICK_PIN 13
#define BLE_LED_PIN 12
#define BLINK_INTERVAL 1000

int passedMillis = 0;
BleGamepad bleGamepad("Orava's Wireless Gamepad", "Oravagamer", 100);

void setup() {
  Serial.begin(115200);
  pinMode(BLE_LED_PIN, OUTPUT);
  digitalWrite(BLE_LED_PIN, LOW);
  Serial.println("Starting BLE work!");
  bleGamepad.begin();
}

void loop() {
  if (bleGamepad.isConnected()) {
    digitalWrite(BLE_LED_PIN, HIGH);
//    bleGamepad.setLeftThumb(0, 32767);
  } else {
    auto currentMillis = millis();
    if (currentMillis - passedMillis >= BLINK_INTERVAL) {
      digitalWrite(BLE_LED_PIN, !digitalRead(BLE_LED_PIN));
      passedMillis = currentMillis;
    }
  }
}
