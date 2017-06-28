### June 28th, 2017 [alpha v0.003]

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

### June 27th, 2017 [alpha v0.002]

[Changes]
- Added clock set in configuration menu
- Clock Menu now shows lifespan and current time seperate
- Added cardflip game.
- Games are handled like menus with selMenu, but functions are seperated into games tab.
- Updated README.MD

[Known Bugs]
- Atmega328 has unusual behavior when changing from gameStage 3 to 4 in cardflip. Changes gameVal[nextcard] to incrementing semi-random number that seems to depend on time.
- Master (real time) clock doesn't change other units (hours, minutes) when rolling over current unit 

### June 26th, 2017 [alpha v0.001]

- Started github project
