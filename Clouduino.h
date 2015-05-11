/*
  Clouduino.h - Library for Clouduino.io

  Based on the Bill Roy socket.io-arduino-client

  Created by Davey Kropf, April 21, 2015.
  Released into the public domain.
*/

#ifndef Clouduino_h
#define Clouduino_h

#include "Arduino.h"
#include <Ethernet.h>
#include "SPI.h"

class Clouduino
{
  public:
    typedef void (*DataArrivedDelegate)(Clouduino client, char data);
    bool connect(char *UUID);
    bool connected();
    void disconnect();
    void send(char *eventName, char *data);
    void onMessage(DataArrivedDelegate dataArrivedDelegate);
    void setMacAddress(byte macAddress[]);
  private:
    char *UUID;
    EthernetClient httpClient;
    EthernetClient tcpClient;
    DataArrivedDelegate dataArrivedDelegate;
    /*  
    *   Default MAC address for Ethernet shield or Arduino.
    *   If you are using multiple Arduino devices with an Ethernet shield in your network
    *   then you have to set this value. Otherwise you can have some issues with your DNS server.
    *   
    *   You could use the setMacAddress() method for this.
    */
    byte mac[6] = {
      0x90, 0xA2, 0xDA, 0x00, 0x6C, 0xFE
    };
  protected:
    int httpPort = 3000;
    int tcpPort = 1337;
    char *serverUrl = "service.clouduino.nl";
};

#endif