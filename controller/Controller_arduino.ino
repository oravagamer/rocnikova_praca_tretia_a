#include <ArduinoBLE.h>

#define joyX A0
#define joyY A1

BLEService controllerService("17bf9a4a-6d20-454e-9c11-e4580cc74424");

BLEByteCharacteristic joystickCharacteristic("17bf9a4a-6d20-454e-9c11-e4580cc74424", BLEWrite | BLERead);

void setup() {
  Serial.begin(9600);

  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");

    while (1);
  }

  BLE.setLocalName("pong-game-arcade-controller-1");
  BLE.setAdvertisedService(controllerService);

  controllerService.addCharacteristic(joystickCharacteristic);

  BLE.addService(controllerService);

  BLE.advertise();

  Serial.println("BLE LED Peripheral");
}

void loop() {
  BLEDevice central = BLE.central();

  if (central) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());

    while (central.connected()) {
      auto xValue = analogRead(joyX);
      auto yValue = analogRead(joyY);
      joystickCharacteristic.writeValue(char(xValue) ":" char(yValue));
    }

    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
}
