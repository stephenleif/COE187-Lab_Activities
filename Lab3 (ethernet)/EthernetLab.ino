#include <SPI.h>
#include <Ethernet.h>

// Replace these with your network settings
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 177);
EthernetServer server(80);

// Replace with the pin your LED is connected to
const int ledPin = 2;

void setup() {
  // Start the Ethernet connection and the server
  Ethernet.begin(mac, ip);
  server.begin();

  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Listen for incoming clients
  EthernetClient client = server.available();

  if (client) {
    Serial.println("New client");
    // Read the first line of the request
    String request = client.readStringUntil('\r');
    Serial.println(request);

    // Check if the request is to turn the LED on or off
    if (request.indexOf("GET /on") != -1) {
      digitalWrite(ledPin, HIGH);
    } else if (request.indexOf("GET /off") != -1) {
      digitalWrite(ledPin, LOW);
    }

    // Send a standard HTTP response header
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<html><body>");
    client.println("<h1>Arduino LED Control</h1>");
    client.println("<p><a href='/on'>Turn On</a></p>");
    client.println("<p><a href='/off'>Turn Off</a></p>");
    client.println("</body></html>");

    // The client will disconnect after sending the response
    delay(1);
    client.stop();
    Serial.println("Client disconnected");
  }
}
