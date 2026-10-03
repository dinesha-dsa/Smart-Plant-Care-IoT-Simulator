#include <DHT.h>
const byte SOIL_PIN=A0,DHT_PIN=2,TANK_PIN=7,RELAY_PIN=8;
const int DRY_ADC=850,WET_ADC=350,PUMP_ON_PERCENT=35,PUMP_OFF_PERCENT=55;
DHT dht(DHT_PIN,DHT11); bool pump=false;
void setup(){Serial.begin(9600);dht.begin();pinMode(TANK_PIN,INPUT_PULLUP);pinMode(RELAY_PIN,OUTPUT);digitalWrite(RELAY_PIN,LOW);}
void loop(){
  int raw=analogRead(SOIL_PIN);
  int moisture=constrain(map(raw,DRY_ADC,WET_ADC,0,100),0,100);
  float temperature=dht.readTemperature();
  bool waterAvailable=digitalRead(TANK_PIN)==LOW;
  if(!waterAvailable)pump=false; else if(moisture<PUMP_ON_PERCENT)pump=true; else if(moisture>=PUMP_OFF_PERCENT)pump=false;
  digitalWrite(RELAY_PIN,pump?HIGH:LOW);
  Serial.print("Moisture: ");Serial.print(moisture);Serial.print("% | Temp: ");Serial.print(temperature);
  Serial.print(" C | Tank: ");Serial.print(waterAvailable?"OK":"EMPTY");Serial.print(" | Pump: ");Serial.println(pump?"ON":"OFF");delay(1000);
}
