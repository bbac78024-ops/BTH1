#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4        // chân DATA
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("DHT11 start");
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h)) {
    Serial.println("Read DHT11 failed!");
    delay(2000);
    return;
  }

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print(" C | Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  delay(2000);
}
