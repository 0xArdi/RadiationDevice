#include <ESP8266HTTPClient.h>

#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>

//Started SoftwareSerial at RX and TX pin of ESP8266/NodeMCU

int data;
const char* URL = "http://skopje.ml/api/device/sendData?deviceSecret=YOUR_DEVICE_SECRET";
const char* ssid = "Test";
const char* password = "12345678";
 
void setup () {
 
  Serial.begin(9600);
  
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting..");
  }
 
}

void loop() {
  // read data from arduino

  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;  //Declare an object of class HTTPClient

    while (Serial.available() == 0);

    data = Serial.parseInt();
    
    http.begin(URL);  //Specify request destination
    http.addHeader("Content-Type", "application/x-www-form-urlencoded"); 
    int httpCode = http.POST(String("measurement=" + String(data))); //Send the request
 
    if (httpCode > 0) { //Check the returning code
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);                     //Print the response payload
    }
    
    http.end();   //Close connection
 }
}
  
 
