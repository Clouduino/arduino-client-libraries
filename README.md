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

## Connect the library to local server
To connect the library to your local node server, you will need to adjust your hostname / ip-address
File: `Clouduino.h`
At linenumber: `46`
`char *_hostname = "192.168.124.45";`