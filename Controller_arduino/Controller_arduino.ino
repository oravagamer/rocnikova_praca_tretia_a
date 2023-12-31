#include <Arduino.h>
#include <BleGamepad.h>

#define STICK_L_X_PIN 12
#define STICK_L_Y_PIN 14
#define STICK_R_X_PIN 27
#define STICK_R_Y_PIN 26
#define BLE_LED_PIN 13
#define BLINK_INTERVAL 1000

int passedMillis = 0;
BleGamepad bleGamepad("Orava's Wireless Gamepad", "Oravagamer", 100);
int LStickX = 0;
int LStickY = 0;
int RStickX = 0;
int RStickY = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BLE_LED_PIN, OUTPUT);
  digitalWrite(BLE_LED_PIN, LOW);
  Serial.println("Starting BLE work!");
  bleGamepad.begin();
}

void loop() {
  LStickX = analogRead(STICK_L_X_PIN);
  LStickY = analogRead(STICK_L_Y_PIN);
  RStickX = analogRead(STICK_R_X_PIN);
  RStickY = analogRead(STICK_R_Y_PIN);

  if (bleGamepad.isConnected()) {
    digitalWrite(BLE_LED_PIN, HIGH);
    bleGamepad.setLeftThumb(map(LStickX, 0, 4095, 0, 32767), map(LStickY, 0, 4095, 0, 32767));
    bleGamepad.setRightThumb(map(RStickX, 0, 4095, 0, 32767), map(RStickY, 0, 4095, 0, 32767));
    bleGamepad.setLeftTrigger(map(RStickY, 0, 4095, 0, 32767));

  } else {
    int currentMillis = millis();
    if (currentMillis - passedMillis >= BLINK_INTERVAL) {
      digitalWrite(BLE_LED_PIN, !digitalRead(BLE_LED_PIN));
      passedMillis = currentMillis;
    }
  }
}
