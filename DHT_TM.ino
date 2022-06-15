#include <TimerOne.h>
#include <TM1637.h>
#include "DHT.h"
#define DHTPIN 2     
#define DHTTYPE DHT11  
#define CLK 10
#define DIO 9
DHT dht(DHTPIN, DHTTYPE);
TM1637 tm1637(CLK,DIO);
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT-18-17211186 test!"));
  dht.begin();  
  tm1637.init();
  tm1637.set(2);     
}
void loop() { 
  delay(2000);
  float t = dht.readTemperature();
  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("  Temperature: "));
  Serial.print(t);

  int d = (int)t;

  tm1637.display(0,1);
  tm1637.display(1,8);
  tm1637.display(2,d/10);
  tm1637.display(3,d%10);
 }
  

 

     
