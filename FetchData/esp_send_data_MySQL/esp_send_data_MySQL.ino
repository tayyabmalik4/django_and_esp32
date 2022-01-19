/* This arduino code is sending data to mysql server every 30 seconds.
Created By Embedotronics Technologies*/

#include "DHT.h"
#include <WiFi.h>
#include <WiFiClient.h>


#define DHTPIN 27

#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);


float humidityData;
float temperatureData;


const char* ssid = "HUNCH_Automation_2";// 
const char* password = "Hunch@786";
//WiFiClient client;
char server[] = "192.168.0.128";   //eg: 192.168.0.222


WiFiClient client;    


void setup()
{
 Serial.begin(115200);
  delay(10);
  dht.begin();
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Not Connected");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
//  server.begin();
  Serial.println("Server started");
  Serial.print(WiFi.localIP());
  delay(1000);
  Serial.println("connecting...");
 }
void loop()
{ 
  humidityData = dht.readHumidity();
  temperatureData = dht.readTemperature(); 
//  Serial.println(temperatureData);
//  Serial.println(humidityData);
  Sending_To_phpmyadmindatabase(); 
  delay(10000); // interval
 }

 void Sending_To_phpmyadmindatabase()   //CONNECTING WITH MYSQL
 {
   if (client.connect(server, 81)) {
    Serial.println("connected");
    // Make a HTTP request:
    Serial.print("http://localhost:81/esp32WithTayyab/Connect.php?temperature=");
    client.print("GET http://localhost:81/esp32WithTayyab/Connect.php?temperature=");     //YOUR URL
    Serial.print(temperatureData);
    client.print(temperatureData);
    client.print("&humidity=");
    Serial.print("&humidity=");
    client.print(humidityData);
    Serial.println(humidityData);
    client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: Your Local IP");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
 }
