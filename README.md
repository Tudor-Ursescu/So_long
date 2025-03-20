# So_long - Graphical 2D game developed using the MinilibX library

## Table of Contents
1.[Overview](#overview)
2.[Core Features](#-core-features)
3.[Game Features](#game-features)
4.[Directory Structure](#-directory-structure)
5.[Directory Descriptions](#-directory-description)
6.[Compilation Instructions](#-compilation-instructions)

## 📌 Overview

The game features a player navigating a maze-like environment with the goal of collecting items and reaching an exit. The game leverages graphical rendering via the MinilibX library, and involves handling user input for player movement and interaction.

## ⚡ Core Features
- Player Movement: Use W, A, S, D (or arrow keys) to move in the four cardinal directions.
- Graphics: Use of images to display walls, collectibles, the player character, enemies and the exit.
- Map Management: Validates and reads maps in the .ber format, ensuring correct structure (walls, collectibles, enemies, and exit).

## 🎮Game Features
- Movement: The player can move up, down, left, and right, but cannot pass through walls.
- Collectibles: The player must collect all items on the map.
- Exit: Once all collectibles are collected, the player must reach the exit, avoiding any colision with enemies.
- Window Handling: Proper window management with MiniLibX, handling events like window closing (Esc key, clicking the cross).
- Movement Display: The current movement count is printed in the shell, and for the bonus, it is also displayed on the window as well.
- Map Validation: The program verifies that maps adhere to the correct format and structure.

## 📂 Directory Structure

```sh
So_long/
│
├── Makefile           # Compilation instructions
├── src/               # Source code files
│
├── includes           # Header files for the project
├── maps               # Map variety for testing in .ber format
│
├── textures           # Texture files for graphics
│
└── dirs/
    ├── libft          # Custom library
    └── mlx.zip        # Minilibx (graphics library) required for rendering the game
```

## 🛠 Directory Descriptions
- mlx.zip/:
This is a zipped version of the MiniLibX library, which is required for graphical rendering. The library includes basic functions to create windows, handle user input (keyboard and mouse), and work with images. To use it, the zip file must be extracted and compiled before linking it with the main project.

## 🚀 Compilation Instructions
To compile and run this program:
```sh
git clone https://github.com/Tudor-Ursescu/So_long.git
cd So_long
```
Now we need to unzip the mlx.zip into dirs/
```sh
unzip dirs/mlx.zip -d dirs/
```
Compile everything:
```sh
make
```
And run the game:
```sh
./so_long `path/to/your/map.ber`
```
Example: `./so_long maps/smal_enemy.ber`
