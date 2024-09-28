#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>  // Include this library for Wi-Fi connectivity (use ESP32WiFi.h for ESP32)

const char* ssid = "Shubham";         // Replace with your Wi-Fi network name
const char* password = "Shu@813212"; // Replace with your Wi-Fi network password

void setup() {
  Serial.begin(115200);

  // Set the built-in LED pin as an output
  pinMode(LED_BUILTIN, OUTPUT);

  // Start connecting to WiFi
  WiFi.begin(ssid, password);
  
  // Blink the LED until WiFi is connected
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, LOW);  // Turn the LED on (LOW because built-in LED is active LOW)
    delay(500);                      // Wait 500 ms
    digitalWrite(LED_BUILTIN, HIGH); // Turn the LED off
    delay(500);                      // Wait 500 ms
    Serial.println("Connecting to WiFi...");
  }

  // Stop blinking when connected
  digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off (HIGH for active LOW)
  
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());   // Print the IP address

  // OTA setup
  ArduinoOTA.setHostname("esp8266-ota");  // Optional, you can name the device
  ArduinoOTA.setPassword("1234");  // Password for OTA updates (optional)

  ArduinoOTA.onStart([]() {
    Serial.println("Start updating...");
  });

  ArduinoOTA.onEnd([]() {
    Serial.println("\nUpdate complete!");
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });

  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });

  ArduinoOTA.begin();  // Initialize OTA
  Serial.println("Ready for OTA updates");
}

void loop() {
  ArduinoOTA.handle();  // Necessary for OTA to work

  // Your main code (if any) can go here.
}
