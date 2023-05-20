
# cub3D

3D RayCasting Engine made with libmlx and C.



![App Screenshot](https://github.com/Higlix/cub3D/blob/master/docs/unnamed.png)


## Installation/Compiling

```bash
$ git clone https://github.com/Higlix/cub3d

$ cd cub3d

$ make
```


## After Compiling

The program requiers a map file in order to run.

- Inside the /config file you can see a folder called maps. 
#### Example map file

```bash
NO ./config/res/greystone.xpm 
SO ./config/res/bluestone.xpm
WE ./config/res/mossy.xpm
EA ./config/res/wood.xpm

F 96,96,96
C 75,190,255

11111111111111111111111111111111111111111111111111
10000001000000000000000000000000000000000000000001
10000000000001000000000000000000000000000000000001
10000001000001000000000000000000000000000000000001
10000001000000000010000000000000000000000000000001
10000001000000000000000000000000000000000000000001
101001010000000000000000000000S0000000000000000001
10000001000000000000000000000000000000000000000001
10000001000000000000000000000000000000000000000001
11111111111111111111111111111111111111111111111111
```
#### About Maps (Format)
```bash
NO = North side of walls.
SO = South side of walls.
WE = West side of walls.
EA = East side of walls.

F = Folor color
C = Celling color

*MAP*
1 = WALL
0 = EMPTY

S = This represents the player and the direction it spawns in.

// S begin South is can also be N, W or E.
```
- One small thing to note. If you want to create your own maps you can do so in this format and with the file extension ".cub".
## Execution
```bash
$ ./bin/cub3d config/maps/test_map01.cub
```
- ONLY WORKS ON MACOS BY DEFAULT

## Authors

- [@Higlix](https://github.com/Higlix) Lead Developer
- [@Martini](https://github.com/alpardayalman) Texture Designer

