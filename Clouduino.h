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
    void monitor();
    void onData(DataArrivedDelegate dataArrivedDelegate);
  private:
    char *UUID;
    EthernetClient httpClient;
    EthernetClient tcpClient;
    DataArrivedDelegate dataArrivedDelegate;
  protected:
    int httpPort = 3000;
    int tcpPort = 1337;
    char *serverUrl = "192.168.178.21";
};

#endif