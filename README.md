# Clouduino library
URL: http://www.clouduino.io

A library for interacting an Arduino with the Clouduino server.

**Includes:**
- Support for the W5100 Ethernet Shield

**Future plans:**
- Support for the WiFi Shields

## Installation instructions
Put the files in a directory called _Clouduino_. Drag the _Clouduino_ folder into your libraries folder. Under Windows, it will likely be called "My Documents\Arduino\libraries". For Mac users, it will likely be called "Documents/Arduino/libraries".

Restart the Arduino IDE application. That's it!

## How to use
Use the following code to start with Clouduino

```c++
/***
    Clouduino.io - Ethernet Library
    Arduino Cloud Service, build for fun
***/

#include "Clouduino.h"
#include "Ethernet.h"
#include "SPI.h"
Clouduino client;

// Enter your own generated Arduino UUID from the Clouduino website.
char *UUID = "f889db47cb0152de057fe16e09996d4a";

void setup() {
  Serial.begin(9600);

  // Connect your shield to Clouduino.io
  if (!client.connect(UUID)) {
    Serial.println(F("Not connected."));
  } else {
    Serial.println(F("Connected."));
  }
}

void loop() {
  client.onMessage(dataArrived);
  
  // .. Your arduino code
}

// Clouduino message handler: do something with data from Clouduino
void dataArrived(Clouduino client, char data) {
  Serial.print("dataArrived: ");
  Serial.println(data);
}
```

## Connect the library to local server
To connect the library to your local node server, you will need to adjust your hostname / ip-address
> File: `Clouduino.h`, linenumber: `45`

```c++
char *_hostname = "192.168.124.45";
```