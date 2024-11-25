#define BLYNK_TEMPLATE_ID           "TMPL37E-QGw-N"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "rIjO2la_Ak-FTjFtpbpeKi9QUMZDm7cg"

// Include necessary libraries
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi credentials
char ssid[] = "AwakeManish";       // Your WiFi SSID
char pass[] = "radheradhe";        // Your WiFi password

void setup() {
  Serial.begin(9600);              // Set baud rate for debugging
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); // Connect to Blynk server
  pinMode(LED_BUILTIN, OUTPUT);    // Initialize the built-in LED as output
  Serial.println("NodeMCU is connected to Blynk and ready.");
}

BLYNK_WRITE(V0) {                  // Triggered when the button widget state changes
  int pinValue = param.asInt();    // Get the value from the widget (0 or 1)
  digitalWrite(LED_BUILTIN, pinValue ? LOW : HIGH); // Turn LED on (LOW) or off (HIGH)
}

void loop() {
  Blynk.run();                     // Run Blynk
}
