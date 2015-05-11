/*
  Clouduino.cpp - Library for Clouduino.io

  Based on the Bill Roy socket.io-arduino-client

  Created by Davey Kropf, April 21, 2015.
  Released into the public domain.
*/

#include <Clouduino.h>

bool Clouduino::connect(char *theUUID) {
  Ethernet.begin(mac);
  delay(1000);
  Serial.print("IP of Ethernet Shield = ");
  Serial.println(Ethernet.localIP());

  if (tcpClient.connect(serverUrl, tcpPort)) {
    // Send the UUID to the TCP server
    tcpClient.print(theUUID);  

    delay(1000); 

    if (tcpClient.connected()) {
      // Save the UUID
      UUID = theUUID;
      return true;
    } else {
      Serial.println("Incorrect or unkown UUID.");
      return false;
    }    
  } else {
    Serial.println("Cannot connect to Clouduino TCP server.");  
    return false;
  }
}

bool Clouduino::connected() {
  return tcpClient.connected();
}

void Clouduino::disconnect() {
  tcpClient.stop();
}

void Clouduino::onMessage(DataArrivedDelegate newdataArrivedDelegate) {
  dataArrivedDelegate = newdataArrivedDelegate;

  if (!tcpClient.connected()) {
    if (!tcpClient.connect(serverUrl, tcpPort)) return;
  }

  while (tcpClient.available()) {
    char incomingData = tcpClient.read();
    // trigger
    dataArrivedDelegate(*this, incomingData);
  }  
}

void Clouduino::send(char *eventName, char *data) {
  // Close any connection before send a new request.
  httpClient.stop();

  if (httpClient.connect(serverUrl, httpPort)) {
    String getURL = "GET /hooks/";
    getURL += UUID;
    getURL += "/";
    getURL += eventName;
    getURL += "/";
    getURL += data;
    getURL += " HTTP/1.1";

    // Make a HTTP request:
    httpClient.println(getURL);
    httpClient.print(F("Host: "));
    httpClient.println(serverUrl);
    httpClient.println("Connection: close");
    httpClient.println();
    httpClient.println();
  } else {
    Serial.print("Cannot connect to Clouduino HTTP server");
  }
}

void Clouduino::setMacAddress(byte mac_address[]) {
  for (int i = 0; i < 6; ++i)
  {
    mac[i] = mac_address[i];
  }
}