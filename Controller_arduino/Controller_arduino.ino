#include <Arduino.h>
#include <BleGamepad.h>

#define GPIO13 13

int currentState;

BleGamepad bleGamepad("Orava's Wireless Gamepad", "Oravagamer", 100);

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleGamepad.begin();
  pinMode(GPIO13, INPUT_PULLUP);
}

void loop() {
  if (bleGamepad.isConnected()) {
    currentState = digitalRead(GPIO13);
    
    if (currentState == HIGH) {
      bleGamepad.setLeftThumb(0, 32767);
    } else if (currentState == LOW) {
      bleGamepad.setLeftThumb(0, 0);
    }

  }
}
