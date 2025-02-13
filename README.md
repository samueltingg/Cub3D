# cub3D

## Project Description
cub3D is a 3D graphics project inspired by the classic game Wolfenstein 3D. It serves as an introduction to raycasting and graphics rendering in C using the MiniLibX library. The project renders a first-person view of a maze-like environment and allows player movement and rotation.

### Compilation
To build the program, navigate to the project directory and run:
```sh
make
```
This will generate the executable `cub3D`.

### Running the Program
To start the game, use the following command:
```sh
./cub3D maps/map.cub
```
Replace `maps/map.cub` with the actual path to your map file.

## Controls
### Movement
- `W` - Move forward
- `A` - Move left
- `S` - Move backward
- `D` - Move right

### Rotation
- `Left Arrow` - Rotate left
- `Right Arrow` - Rotate right
- `Mouse Movement` - Rotate the view smoothly

### Exiting
- `ESC` - Close the game

## Features
- Real-time raycasting for 3D rendering
- Collision detection
- Smooth player movement and rotation
- Basic texture rendering (walls, floors, ceilings)
- Configurable map system

