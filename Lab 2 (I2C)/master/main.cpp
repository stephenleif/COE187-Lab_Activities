#include <Wire.h>
#include <Arduino.h>

void setup() {
    Wire.begin();
    Serial.begin(9600);
}

void sendDataToSlave(int slaveAddress, char data) {
    Wire.beginTransmission(slaveAddress);
    Wire.write(data);
    Wire.endTransmission();

    Serial.print("Sent data to Slave at address ");
    Serial.print(slaveAddress);
    Serial.print(": ");
    Serial.println(data);
}

void loop() {
    sendDataToSlave(9, 'A');   // Send 'A' to Slave 1 (Arduino Uno 1)
    delay(1000);
    sendDataToSlave(10, 'B');  // Send 'B' to Slave 2 (Arduino Uno 2)
    delay(1000);
}


