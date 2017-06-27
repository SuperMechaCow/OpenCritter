### June 27th, 2017 [alpha v0.002]

[Changes]
- Added cardflip game.
- Games are handled like menus with selMenu, but functions are seperated into games tab.
- Updated README.MD

[Known Bugs]
- Atmega328 has unusual behavior when changing from gameStage 3 to 4 in cardflip. Changes gameVal[nextcard] to incrementing semi-random number that seems to depend on time.

### June 26th, 2017 [alpha v0.001]

- Started github project
