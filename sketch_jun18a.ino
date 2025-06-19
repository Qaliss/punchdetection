#include <Wire.h>
#include <MPU6050.h>
#include <EEPROM.h>

MPU6050 mpu;

const int maxRecords = 80;  // 80 records × 6 bytes = 480 bytes
int addr = 1;               // Start after flag at address 0

void setup() {
  Wire.begin();
  Serial.begin(115200);
  mpu.initialize();

  bool shouldDump = EEPROM.read(0);  // Flag at address 0

  if (shouldDump) {
    delay(3000);  // Give you time to open Serial Monitor
    Serial.println("=== Dumping EEPROM Data ===");
    for (int i = 0; i < maxRecords; i++) {
      int ax = EEPROM.read(addr++) - 128;
      int ay = EEPROM.read(addr++) - 128;
      int az = EEPROM.read(addr++) - 128;
      Serial.print("Accel "); Serial.print(i);
      Serial.print(" | X: "); Serial.print(ax);
      Serial.print(" | Y: "); Serial.print(ay);
      Serial.print(" | Z: "); Serial.println(az);
    }

    EEPROM.write(0, 0);  // Reset flag after dump
  } else {
    Serial.println("=== Recording Motion ===");
    delay(1000);  // Give user time to unplug and punch
    for (int i = 0; i < maxRecords; i++) {
      int16_t ax, ay, az;
      mpu.getAcceleration(&ax, &ay, &az);

      // Scale down for 1-byte storage (±2g = ±16384 → -128 to 127)
      EEPROM.write(addr++, constrain(ax / 128 + 128, 0, 255));
      EEPROM.write(addr++, constrain(ay / 128 + 128, 0, 255));
      EEPROM.write(addr++, constrain(az / 128 + 128, 0, 255));

      delay(50);  // 20 Hz sampling (~4 seconds total)
    }

    EEPROM.write(0, 1);  // Set flag to indicate data is recorded
    Serial.println("Recording done. Unplug or reset to dump.");
  }
}

void loop() {
  // Nothing here
}
