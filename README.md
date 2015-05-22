# Arduino-and-ESP8266-wifi-setup
Wireless network setup through Arduino serial port to ESP8266

**REQUISITES:**

- ESP8266 flashed with [NodeMCU firmware](https://github.com/nodemcu/nodemcu-firmware)
- [ESPlorer](http://esp8266.ru/esplorer/) or [Lua Loader](http://benlo.com/esp8266/) downloaded
- Arduino Leonardo

This example shows how to join a wireless network with the ESP8266. Sending the credentials of the network from an Arduino through serial port to ESP8266. Once the nertwork is joined the ESP8266 returns to Arduino the IP and MAC Address of the ESP8266 through serial port.