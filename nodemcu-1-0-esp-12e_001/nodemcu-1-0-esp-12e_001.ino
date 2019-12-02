#define BLYNK_PRINT Serial
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>

char auth[] = “pjgFEzrZ2-q1bCsfNxD2vwhwz4gaWLY6”;

char ssid[] = “NADTAWOOT 1”;
char pass[] = “0640968245”;

#define DHTPIN 2

#define DHTTYPE DHT22 // DHT 22, AM2302, AM2321

DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;

void sendSensor()
{
float h = dht.readHumidity();
float t = dht.readTemperature();
}
if (isnan(h) || isnan(t)) {
Serial.println(“Failed to read from DHT sensor!”);
return;
}

Blynk.virtualWrite(V5, h);
Blynk.virtualWrite(V6, t);

void setup()
{
Serial.begin(9600); 
Blynk.begin(auth, ssid, pass);

dht.begin();

timer.setInterval(1000L, sendSensor);
}

void loop()
{
Blynk.run();
timer.run();
}
