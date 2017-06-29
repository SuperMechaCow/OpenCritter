### June 29th, 2017 [alpha v0.004] Nightly

[Changes]
- Change data types of Stats and Traits to save bytes
- Metabolism is the average percent of your stats and traits + the deviation from "healthy" weight
- Stats roll to drain every X hearbeats, depending on corresponding trait. The higher the trait, the slower it drains.
- Now rolls to see if you will gain weight each time you feed it, depending on Ath
- Added EEPROM writer tool to dump the gfx arrays header file into on-board EEPROM. Temporary solution until external EEPROM is added.
- Bitmaps are now pulled from EEPROM using the getGFX() function.

[Known Bugs]
- No known bugs fixed from alpha v0.002
- CRITTER BITMAPS ARE ALL BORKED! PANIC!
- This version not updated for ESP8266 platform.

[Notes]
- Disabled buzzer code to make room on the Atmega328

### June 28th, 2017 [alpha v0.003] Nightly

[Changes]
- Added playMenu functionality
- Added bitshifter minigame
- Changed Stats from 0.00 - 100.00 (float) to 0 - 10000 (int)
- Changed Traits from 0.00 - 1.00 (float) to 0 - 100 (byte)

[Known Bugs]
- No known bugs fixed from alpha v0.002
- Stats and Traits changes are untested!!! 

[Notes]
- Atmega328 version is at 98% flash usage! Yikes!
- Some unused icons and gfx disabled to fit program onto Atmega328
- Time offset should be a single modifier to the baseCLK instead of multiple variables

### June 27th, 2017 [alpha v0.002] Nightly

[Changes]
- Added clock set in configuration menu
- Clock Menu now shows lifespan and current time seperate
- Added cardflip game.
- Games are handled like menus with selMenu, but functions are seperated into games tab.
- Updated README.MD

[Known Bugs]
- Atmega328 has unusual behavior when changing from gameStage 3 to 4 in cardflip. Changes gameVal[nextcard] to incrementing semi-random number that seems to depend on time.
- Master (real time) clock doesn't change other units (hours, minutes) when rolling over current unit 

### June 26th, 2017 [alpha v0.001] Nightly

- Started github project
