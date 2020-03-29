#define BLYNK_ PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h> // including the library of DHT11 temperature and humidity sensor
#include <SimpleTimer.h> //including the 1ibrary or Simplerimer
#define DHTTYPE DHT11
#define dht_dpin D2
DHT dht(dht_dpin, DHTTYPE) ;
SimpleTimer timer;

char auth[] = "";
char ssid[]= "nameofwifi";
char pass[]- "passswordofwifi"; // set password to " for open networks.
float t; // Deeclare the variables
float h;
const int buzzer = D8;
int obstaclePin =D1;
int hasObstacle = HIGH;
int motorPin =D7;

void setup()
{
Serial.begin(9600); // Debug console
Blynk.begin(auth, ssid, pass);
dht.begin();
timer.setInterval(2000,sendUptime);
pinMode(buzzer, OUTPUT) ;
pinMode(obstaclePin, INPUT);
}

void sendUptime()
{
float h = dht.readHumidity();
float t = dht.readTemperature();
Serial.println("Humidity and temperature \n\n");
Serial.print("Current humidity=");
Serial.print(h);
Serial.print("% ");
Serial.print("temperature=");
Serial.print(t);
Blynk.virtualWrite(V0, t);
B1ynk.virtua1Write(V1, h);
}

void loop()
{
Blynk.run();
timer.run();
hasObstacle = digitalRead(obstaclePin); //Reads the output of the obstacle sensor from the
if (hasObstacle == LOW) //LOW means something is ahead, so 1lluminates the 13th Port connected
   {Serial.println("Intruder alert!");
  tone(buzzer, 6000) //Send 1KHz sound signal.
  delay(1000);
  noTone(buzzer) ;
   }
else
{
Serial.println("Path 1s clear")
}
delay(400);
if (t>40) //if temp greater than 40'C wtich on fan
{
digitalWrite(motorPin, HIGH);
}
else
{
  digitalWrite(motor Pin, LOW) ;
}
