# OpenCritter

OpenCritter is an open source digital pet. The software is totally free, and the hardware easy to obtain.

Anyone is invited to work on the project for as long as they stick to the following principles:

- The hardware and software toolchain must be *NEWB FRIENDLY* above all else. A complete novice should be able to obtain and breadboard the hardware easily and upload the firmware without problem. Add-on modules/functionality can be more complex, but any human should be able to have a fully-functional "base game".
- The core rules of the game do not change in the master branch. There must be at least one "core experience" common amongst all users with unmodified firmware.
- Mods are encouraged! But too much deviation from the "core experience" should be listed as a new branch.
- OpenCritter software is all-ages and gender nuetral.

## Hardware

OpenCritter is currently being developed for Atmega328-based Arduinos and ESP8266 NodeMCU in the Arduino IDE.

Both platforms will need a piezo buzzer, a small vibration motor (optional), a battery circuit, three tactile switches, and an I2C 0.96" OLED screen based on SSD1306.

The Atmega328 platform requires an additional EEPROM, SRAM, 5v to 3.3v level shifter, and an ESP-01 module.

## Software

Currently, the software requires Adafruit's GFX and SSD1306 libraries. May also require the ESP8266 core arduino software depending on your platform.

## Objectives

- Finish the main game's functionality (sickness/death, crying for attention, evolution, mini-games, property interactions)
- Add peer-to-peer wireless communications
- Multi-player games and functions
- OpenCritter "dog house" device or wireless internet functionality.
- OpenCritter database for online multiplayer/scoreboards.
- Robust serial comms for UART "add-on" devices that add gameplay features.
