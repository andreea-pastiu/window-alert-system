#include <DHT.h>

#define DHTPIN 3
#define DHTTYPE DHT11
#define TILTPIN 2
#define BUZZPIN 4
#define RAINPIN A0
#define SWITCHPIN 5
#define GRELED 6
#define REDLED 7
#define openWindow true
#define closeWindow false
#define rainLimit 600
#define temperatureLow 18
#define temperatureHigh 30

DHT dht(DHTPIN, DHTTYPE);
bool switchState;
bool switchPrev;

void setup()
{
  Serial.begin(9600);
  dht.begin();
  pinMode(TILTPIN, INPUT);
  pinMode(SWITCHPIN, INPUT);
  pinMode(BUZZPIN,OUTPUT);
  pinMode(GRELED, OUTPUT);
  pinMode(REDLED, OUTPUT);
  switchState = false;
  switchPrev = false;
}

void blink(int LED, int del)
{
  digitalWrite(LED, HIGH);
  delay(del);
  digitalWrite(LED, LOW);
  delay(del);
}

void buzz()
{
  for(int i = 0; i < 100; i++)
  {
    digitalWrite(BUZZPIN,HIGH);
    delay(1);
    digitalWrite(BUZZPIN,LOW);
    delay(1);
  }
  for(int i = 0; i < 100; i++)
  {
    digitalWrite(BUZZPIN,LOW);
    delay(1);
  }
}

void loop()
{
  float temperatureVal = dht.readTemperature() - 2;
  int tiltDetected = digitalRead(TILTPIN);
  int rainVal = analogRead(RAINPIN);
  int switchRead = digitalRead(SWITCHPIN);

  if(switchRead == true && switchPrev == false)
  {
    switchState = not switchState;
    digitalWrite(GRELED, switchState);
  }
  switchPrev = switchRead;
  if(switchState == true)
  {
    if(tiltDetected == openWindow && (rainVal < rainLimit || (temperatureVal < temperatureLow || temperatureVal > temperatureHigh)))
    {
      blink(REDLED, 150);
      buzz();
    }
    else
    {
      digitalWrite(REDLED, LOW);
    }
  }
  else
  {
    digitalWrite(REDLED, LOW);
  }

  
  Serial.print("Temperature = ");
  Serial.println(temperatureVal);
  Serial.print("Tilt = ");
  Serial.println(tiltDetected);
  Serial.print("Rain = ");
  //Serial.print(rainVal/1023.0*100);
  Serial.println(rainVal);
  //Serial.println("%");
}
