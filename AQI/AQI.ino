#define BLYNK_TEMPLATE_ID           "TMPL37E-QGw-N"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "rIjO2la_Ak-FTjFtpbpeKi9QUMZDm7cg"

// Include necessary libraries
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi credentials
char ssid[] = "AwakeManish";       // Your WiFi SSID
char pass[] = "radheradhe";        // Your WiFi password

const int MQ135_PIN = A0;          // Analog pin connected to MQ135
float airQuality = 0.0;            // Variable to store air quality reading

void setup() {
  Serial.begin(9600);              // Set baud rate for debugging
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); // Connect to Blynk server
  pinMode(MQ135_PIN, INPUT);       // Set MQ135 pin as input
  Serial.println("NodeMCU with MQ135 is connected to Blynk.");
}

void loop() {
  airQuality = analogRead(MQ135_PIN);  // Read analog value from MQ135
  float ppm = map(airQuality, 0, 1023, 0, 500); // Map sensor value to PPM (example range)

  Serial.print("Air Quality (PPM): ");
  Serial.println(ppm);

  Blynk.virtualWrite(V5, ppm);     // Send the PPM value to Blynk (Virtual Pin V5)
  Blynk.run();                     // Run Blynk
  delay(1000);                     // Update every second
}
