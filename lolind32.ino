#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define buttonPin 2

const char* ssid = "ssid";
const char* password = "password";
const char* serverAddress = "http://localhost/";

// Inizializza il sensore BME280
Adafruit_BME280 bme;

void setup() {
  Serial.begin(115200);

  // Connessione WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Inizializza il sensore
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  // Imposta il pin del bottone come input
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Leggi lo stato del bottone
  int buttonState = digitalRead(buttonPin);

  // Se il bottone è premuto
  if (buttonState == HIGH) {
    float temperature = bme.readTemperature();
    float humidity = bme.readHumidity();

    // Crea il JSON con i dati
    String jsonData = "{\"NomeScheda\":\"LOLIN D32\",\"Temperatura\":\"" + String(temperature) + "\",\"Umidita\":\"" + String(humidity) + "\"}";

    // Invia il JSON al server PHP
    sendJsonData(jsonData);
  }

  delay(5000);
}

void sendJsonData(String data) {
  HTTPClient http;

  // Invia il JSON al server
  http.begin(serverAddress + "/api.php");
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.POST(data);

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
  } else {
    Serial.print("HTTP Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}