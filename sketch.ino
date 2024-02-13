#define red_led 12
#define green_led 7
#define blue_led 5
#define dht_pin 10
#include "DHT.h"
float temp  = 0.0;
float hum= 0.0;
DHT my_dht(dht_pin, DHT22);
void setup() {
  
  my_dht.begin(); // we need to active it. must
  Serial.begin(9600); //must to activate the serial monitor
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(dht_pin, INPUT);


}

void loop() {
  temp = my_dht.readTemperature();
  hum = my_dht.readHumidity();
  Serial.print("Temperature in C: ");
  Serial.println(temp);
  Serial.print("Humidity in %: ");
  Serial.println(hum);
  if (temp<=40)
{
  digitalWrite(blue_led, HIGH);
  digitalWrite(red_led, LOW);
  digitalWrite(green_led, LOW);
}
else if (temp<=60)
{
  digitalWrite(blue_led, LOW);
  digitalWrite(red_led, HIGH);
  digitalWrite(green_led, HIGH);
}
else
{
  digitalWrite(blue_led, LOW);
  digitalWrite(red_led, HIGH);
  digitalWrite(green_led, LOW);
}
  delay(400);

}
