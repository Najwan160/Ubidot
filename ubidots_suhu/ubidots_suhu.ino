#include "DHT.h"
#include "UbidotsMicroESP8266.h"
#define DHTPIN 5

#define TOKEN "BBFF-wD86NnqlN4CUobbx1iuXIoTQcJ12Ml"
#define ssid "NajwanNuha"
#define pswd "blacktrajet"

 DHT dht(DHTPIN,DHT11);
 Ubidots client(TOKEN);
 unsigned long last =0;
 
void setup() {

  Serial.begin(9600);
  dht.begin();
  delay(20);
  client.wifiConnection(ssid,pswd);

}

void loop() {

  if(millis()-last>1000){
    float hum = dht.readHumidity();
    float temp = dht.readTemperature();
    last=millis();
    client.add("kelembaban",hum);
    client.add("Temp",temp);
    client.sendAll(true);

  }
}
