#include <ArduinoBLE.h>

#define joyX A0
#define joyY A1

BLEService controllerService("19B10000-E8F2-537E-4F6C-D104768A1214");

BLEByteCharacteristic joystickCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLEWrite | BLERead);

void setup() {
  Serial.begin(9600);

  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");

    while (1);
  }

  BLE.setLocalName("Controller 1");
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
