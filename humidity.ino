#include <dht.h>



#define DHT22_PIN 3
#define RELAY_1_PIN 4
#define RELAY_2_PIN 4

#define LED_1_PIN 8
#define LED_2_PIN 9
#define LED_3_PIN 10
#define LED_4_PIN 11
#define LED_5_PIN 12

dht DHT;

float humidity = 0;
float tempInC = 0; 

float desiredHumidity = 75;

void setup()
{
    Serial.begin(115200);
    pinMode(RELAY_1_PIN, OUTPUT);
    pinMode(RELAY_2_PIN, OUTPUT);
    
    pinMode(LED_1_PIN, OUTPUT);
    pinMode(LED_2_PIN, OUTPUT);
    pinMode(LED_3_PIN, OUTPUT);
    pinMode(LED_4_PIN, OUTPUT);
    pinMode(LED_5_PIN, OUTPUT);
    
}

void loop()
{

    int chk = DHT.read22(DHT22_PIN);
    
    humidity = DHT.humidity;
    tempInC = DHT.temperature;

    if (humidity < desiredHumidity)
    {
      digitalWrite(RELAY_1_PIN, LOW); //turn on
    }else{
      digitalWrite(RELAY_1_PIN, HIGH); //turn off
    }
    
    writeLEDs();
    
    
}

void writeLEDs() {
  if(humidity > 20){
    digitalWrite(LED_1_PIN, HIGH);
  }else{
    digitalWrite(LED_1_PIN, LOW);
  }
    
  if(humidity > 40){
    digitalWrite(LED_2_PIN, HIGH );
  }else{
    digitalWrite(LED_2_PIN, LOW);
  }
    
  if(humidity > 60){
    digitalWrite(LED_3_PIN, HIGH );
  }else{
    digitalWrite(LED_3_PIN, LOW);
  }
    
  if(humidity > 80){
    digitalWrite(LED_4_PIN, HIGH );
  }else{
    digitalWrite(LED_4_PIN, LOW);
  }
    
  if(humidity >= 100){
    digitalWrite(LED_5_PIN,HIGH );
  }else{
    digitalWrite(LED_5_PIN, LOW);
  }
}
