#include <SPI.h>

// Define slave select pins
const int slaveSelectPin1 = 4;  // GPIO4 for Arduino Uno 1
const int slaveSelectPin2 = 5;  // GPIO5 for Arduino Uno 2

void setup() {
  Serial.begin(9600);

  // Initialize SPI
  SPI.begin();
  
  // Set slave select pins as outputs
  pinMode(slaveSelectPin1, OUTPUT);
  pinMode(slaveSelectPin2, OUTPUT);
  
  // Deselect both slaves
  digitalWrite(slaveSelectPin1, HIGH);
  digitalWrite(slaveSelectPin2, HIGH);
}

void loop() {
  // Select first slave
  digitalWrite(slaveSelectPin1, LOW);
  
  // Send data to first slave
  SPI.transfer(0x01);  // Example data, change as needed
  
  // Deselect first slave
  digitalWrite(slaveSelectPin1, HIGH);

  delay(1000);  // Add a delay for demonstration purposes

  // Select second slave
  digitalWrite(slaveSelectPin2, LOW);
  
  // Send data to second slave
  SPI.transfer(0x02);  // Example data, change as needed
  
  // Deselect second slave
  digitalWrite(slaveSelectPin2, HIGH);

  delay(1000);  // Add a delay for demonstration purposes
}
