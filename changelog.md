### September 12th, 2017 [alpha v0.010] Minor

[Changes]
- WiFi can now be toggled to save power
- Atmega328 IOPU button pins switched due to fix error in DevKit1
- Getting buttons from IOPU over i2c now uses 1 byte instead of 8

### September 6th, 2017 [alpha v0.009] Major
Wifi + Play Update

[Changes]
- ESP-01 and NodeMCU now broadcast a soft Access Point, where users can connect and interact through a web browser!
- Added Ball Catch Minigame
- Food (now Protein, Fat, and Carbs) now complete!
- Games now complete!
- Added Energy. Each time a stat drain Energy charges by one. In the future, this will be used to play games and if left full can be automatically used to find meds and loot
- Protein rolls against Ath to gain 1 weight, charges hun, and drains Ath.
- Fat rolls against Ath to gain 1 weight, adds 1 weight, greatly charges hap, and drains Dis.
- Carbs rolls against Ath to gain 1 weight, adds 1 weight, greatly charges bor, and drains Int.
- Ball Catch charges Ath, and drains/charges weight closer to a healthy weight.
- Card Flip charges hap and Dis.
- Bitshifter charges bor and Int.
- Food and Games menus now show what stats are changed by playing.
- Fixed a bug that allowed muted sounds to play
- Fixed animations in games
- Added animation to bitshifter
- animate() now passes X and Y values for the position of the animation
- Moved location of some critter parameters around (breed and metabolism to Clock menu. Energy and Health bars to Biospecs)

### September 1st, 2017 [alpha v0.008]

[Changes]
- Add KiCad schematics, pcb layout, and gerber files for the upcoming DevKit1
- Started sketch for IOPU based on Attiny
- Seeedstudio Fusion project published for DevKit1, so anyone can easily purchase PCBs for it.
	https://www.seeedstudio.com/undefined-g-1040190

### August 2nd, 2017 [alpha v0.007]

[Changes]
- Added lifestages counter (egg, baby, teen, adult, senior... "ancient?").
- The "sickness threshold" is now calculated by how sick the critter already is, how much poop is on the floor, and what "life stage" the critter is at.
- Critter will now cry for attention if its stats and Dis are low
- Criter will now cry when it is in danger of becoming sick
- Sound alerts for becoming sick or pooping


### August 1st, 2017 [alpha v0.006] Nightly

[Changes]
- Stats will no longer roll around to 255 when reducing past 0.
- Added "sick" feature. If stats are left below an average of 100 there's a chance every X heartbeats to gain an illness.
- Medicine menu now removes one illness (this is to made finite later)
- Critters can now poop. The heavier the critter, the more likely it is to poop.
- Poop menu now removes one poop.
- Each stage of life (egg, baby, teen, adult, senior) has a different metabolism bonus
- Metabolism calculation has changed. Is now the average of the average of stats, the average of traits, and the metabolic bonus.
- Critter now evolves every X heartbeats in a linear list of breeds. Variable evolution will be handled in later versions.
- Fixed eating animations (distorted burger icon).
- Added "Tribbur" and "Snek" breeds back into the game.
- Fixed some issues with food subtracting stats rather than adding.

### July 27th, 2017 [alpha v0.005] Major

[Changes]
- Project is now design for ESP-01 with OLED and an Input/Output Processing Unit ("IOPU" device) or a NodeMCU
- Scope of project became too large to run on an Atmega328, so a branch was made for "OpenCritter Lite"
- heartbeat "rolls" now "pile up" so they can be resolved later. This means delay() can now be used in animations, etc. without skipping important heartbeat events
- Started addding support for hardware modules on the I2C bus. This includes scanning and identification of plugged in devices. However, only hard-coded IOPU works right now.
- Real clock is now adjusted by a single offset parameter, rather than by hour/minute/seconds seperately

[Known Bugs]
- Too much serial data seems to interfere with I2C bus comms. Most serial debugging verbosity commented out to "fix" this.

[Notes]

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
