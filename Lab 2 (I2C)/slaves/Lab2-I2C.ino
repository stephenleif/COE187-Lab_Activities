#include <Wire.h>

void setup() {
    Wire.begin(10);  // Set a different address for each slave
    Wire.onReceive(receiveEvent);
    Serial.begin(9600);
}

void loop() {
    // Main loop code here
}

void receiveEvent() {
    while (Wire.available()) {
        char data = Wire.read();
        Serial.print("Received data: ");
        Serial.println(data);
    }
}
