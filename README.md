# so_long

A small 2D game

![so_long](https://media.giphy.com/media/eL9hzVpDFWVjCdL3PS/giphy.gif)

## Game rules

* The player’s goal is to collect every collectible present on the map, then go to the exit.
* The player moves in these 4 directions: up (keyboarde W), down (keyboarde S), left (keyboarde A), right (keyboarde D).

## Requirements:
* [Minilibx](https://github.com/42sp/minilibx-linux) installed (for 42 students using Workspaces the library is already installed)
* Minilibx requires differents libraries depending on the OS as explained [here](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
* For Linux or Mac OS update Makefile as indicated [here](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) in the installation and compilation parts.

### Running the game

If you are using Workspaces just
* run ```./so_long maps/map.ber``` with the specific map of your choice.

Map files are provided in ``maps`` but you can create your own. 
The game only accepts a map in the \*ber format and the characters:
* 1 for walls
* 0 for empty space
* C for colletibles
* E for exit
* P for player

Enjoy and have fun!
