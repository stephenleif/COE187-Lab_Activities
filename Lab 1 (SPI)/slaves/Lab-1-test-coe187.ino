#include <SPI.h>

void setup() {
  Serial.begin(9600);
  
  // Initialize SPI
  SPI.begin();

  // Set MISO pin as OUTPUT
  pinMode(MISO, OUTPUT);
  
  // Enable SPI as Slave
  SPCR |= _BV(SPE);
}

void loop() {
  if (SPI.transfer(0x00)) {  // Check if data is received from master
    // Process received data as needed
    Serial.println("Data received from master!");
  }

  delay(100);  // Add a delay for demonstration purposes
}
