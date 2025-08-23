#include <Arduino_MKRIoTCarrier.h>

MKRIoTCarrier carrier;
int moistPin;
float temperature, humidity;
int raw_moisture, moisture;
int light;

void setup() 
{
  CARRIER_CASE = true;
  Serial.begin(9600);

  delay(1500);

  if (!carrier.begin())
  {
    Serial.println("Carrier not connected, check connections");
    while (1);
  }

  moistPin = carrier.getBoardRevision() == 1 ? A5 : A0; //assign A0 or A5 based on HW revision
}

void loop() 
{
  temperature = carrier.Env.readTemperature(); 
  humidity = carrier.Env.readHumidity();
  raw_moisture = analogRead(moistPin);
  moisture = map(raw_moisture, 0, 1023, 100, 0);
  while (!carrier.Light.colorAvailable()) {
    delay(5);
  }
  int none; //We dont need RGB colors
  carrier.Light.readColor(none, none, none, light);

  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.print("Raw moisture: ");
  Serial.println(raw_moisture);
  Serial.print("Moisture: ");
  Serial.println(moisture);
  Serial.print("Light: ");
  Serial.println(light);
}
