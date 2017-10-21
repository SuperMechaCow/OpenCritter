# OpenCritter

OpenCritter is an open source digital pet. The software is totally free, and the hardware easy to obtain.

Anyone is invited to work on the project for as long as they stick to the following principles:

- OpenCritter is for all levels of skill and expertise. Novices should be able to build their own from scratch, and experts can lead the project development.
- OpenCritter is all-ages and gender nuetral.
- OpenCritter is for makers *and* hackers. Create and destroy!
- Mods are encouraged! But anything that conflicts with the "core experience" of the game should be listed as a new branch.

## Community

**Main GitHub:**
https://github.com/SuperMechaCow/OpenCritter

**Subreddit:**
https://www.reddit.com/r/OpenCritter/

**Discord Channel:**
https://discord.gg/VW9fjV9

## Community

**Main GitHub:**
https://github.com/SuperMechaCow/OpenCritter

**Subreddit:**
https://www.reddit.com/r/OpenCritter/

**Discord Channel:**
https://discord.gg/VW9fjV9


## Hardware

OpenCritter is currently being developed for ESP-01 and NodeMCU in the Arduino IDE. A branch is being made for Atmega328p-based "Lite" versions.

**DevKit1** has been released. It features an ESP8266 circuit, an alternative header for an ESP-01 module, an Atmega328p circuit, programming headers, and four i2c bus headers.

All platforms will need an I2C 0.96" OLED screen based on SSD1306. Additonal piezo buzzer, a small vibration motor (optional), a battery circuit, and three tactile switches should be used with the platform or as an additional IOPU device.

## Software

Currently, the software requires Adafruit's GFX and SSD1306 libraries, and ESP8266 core arduino software depending on your platform.

## Objectives

- Finish the main game's functionality (sickness/death, crying for attention, evolution, mini-games, game rules)
- Add robust "plug-in device" support for modularity.
- Add peer-to-peer wireless communications
- Multi-player games and functions
- OpenCritter "dog house" device or wireless internet functionality.
- OpenCritter database for online multiplayer/scoreboards.

## How can I contribute?

- Graphic designer? We need sprites and animations for 30 different critters!
- Web front-end developer? We need a more robust and pretty webapp to be hosted by the device itself!
- Web back-end developer? We need a database / highscore table for the pets to connect to/register/sync with!
- 3D CAD? DevKit1 could benefit from some open-source cases!
- Electronics Engineer? We need new i2c modules to add plug-and-play functions to the device!
- Software/Embedded Engineer? The device is always in need of optimization, improved i2c module API, and power-saving features!
- Stickler for details? Documentation constantly needs updated!
