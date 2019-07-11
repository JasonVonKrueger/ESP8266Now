
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

#ifndef STASSID
#define STASSID "AP_ID"
#define STAPSK  "super_secret"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;
const char* host = "dev72113.service-now.com";
const int httpsPort = 443;
const char fingerprint[] PROGMEM = "03 46 c1 6e 3b f2 de eb 07 c3 a1 65 84 fc 65 43 9d a1 9c f8";
const int buttonPin = 0;
int buttonState = 0; 

void setup() {
  Serial.begin(115200);

  pinMode(buttonPin, INPUT_PULLUP);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
}

void createIncident() {
  String url = "/api/159204/espynow";
  
  WiFiClientSecure client;
  client.setFingerprint(fingerprint);
  
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    delay(5000);
    return;
  }
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");   
                
  Serial.println("request sent"); 
   
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
    createIncident();
  }
}
