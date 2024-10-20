# Turtix Game Implementation

This project is an implementation of the **Turtix** game using the **Simple and Fast Multimedia Library (SFML)**. The game features a platformer style where players control the main character, Turtix, navigating through various levels and solving puzzles to rescue young turtles and restore peace.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [How to Play](#how-to-play)
- [File Structure](#file-structure)
- [License](#license)

## Introduction
Turtix is a classic 2D platformer where the player controls Turtix, a turtle hero who embarks on a mission to save captured baby turtles. The game is known for its vibrant levels, interesting challenges, and simple controls.

This project is a modern implementation of the game using **SFML** to handle graphics, sound, and game mechanics.

## Features
- Classic Turtix gameplay with multiple levels.
- 2D platformer with vibrant graphics and sound.
- Event-driven game mechanics using SFML.
- Support for keyboard controls.
- Multiple enemy types and obstacles.

## Requirements
To run this project, you will need:
- **SFML 2.5.1** or later installed. You can download SFML from [here](https://www.sfml-dev.org/).
- A C++ compiler that supports C++11 or later (e.g., GCC, Clang, Visual Studio).
- Make (if using the provided `Makefile`).

## Installation
1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/turtix-game.git
   cd turtix-game
   ```
2. **Compile the game:** You can compile the project using the provided Makefile:
   ```bash
   make
   ```
3. **Run the game:** After compilation, you can run the game by executing:
   ```bash
   ./turtix.out
   ```
   
## How to Play
- Use the W, A, and D keys to move Turtix.
- Jump over obstacles and avoid enemies.
- Rescue all baby turtles to complete each level.
- Collect bonuses and power-ups along the way to help you on your mission.


## File Structure
- main.cpp - Contains the main game loop and initialization of game objects.
- map.txt - Defines the layout of levels.
- makefile - A script to compile the project.
- assets/ - Contains game assets like images and sounds.

