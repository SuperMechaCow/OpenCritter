# OpenCritter

OpenCritter is an open source digital pet. The software is totally free, and the hardware easy to obtain.

Anyone is invited to work on the project for as long as they stick to the following principles:

- The hardware and software toolchain must be *NEWB FRIENDLY* above all else. A complete novice should be able to obtain and breadboard the hardware easily and upload the firmware without problem. Add-on modules/functionality can be more complex, but any human should be able to have a fully-functional "base game".
- OpenCritter software is all-ages and gender nuetral.
- Mods are encouraged! But too much deviation from the "core experience" should be listed as a new branch.

## Hardware

OpenCritter is currently being developed for ESP-01 and NodeMCU in the Arduino IDE. A branch is being made for Atmega328-based "Lite" versions.

DevKit1 is soon to be released. It features an ESP8266 circuit, an alternative header for an ESP-01 module, an Atmega328 circuit, programming headers, and four i2c bus headers.

All platforms will need an I2C 0.96" OLED screen based on SSD1306. Additonal piezo buzzer, a small vibration motor (optional), a battery circuit, and three tactile switches should be used with the platform or as an additional IOPU device.

## Software

Currently, the software requires Adafruit's GFX and SSD1306 libraries, and ESP8266 core arduino software depending on your platform.

## Objectives

- Finish the main game's functionality (sickness/death, crying for attention, evolution, mini-games, property interactions)
- Add robust "plug-in device" support for modularity.
- Add peer-to-peer wireless communications
- Multi-player games and functions
- OpenCritter "dog house" device or wireless internet functionality.
- OpenCritter database for online multiplayer/scoreboards.
