#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "NHQ-Home-Wifi";
const char* password = "gladyear2024";

WebServer server(80);

// HTML or data to host
String fileContent = "Hello from ESP32!";

void handleRoot() {
  server.send(200, "text/plain", fileContent);
}

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}
