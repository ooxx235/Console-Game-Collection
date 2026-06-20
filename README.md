# Console Game Collection

This project is a collection of console-based games developed in C++, featuring Greedy Snake, Minesweeper, and the 1A2B number guessing game[cite: 1]. The objective of this project is to demonstrate proficiency in core algorithms, data structure implementation, and real-time interactive logic.

## Project Overview

All games in this collection are implemented in C++, emphasizing logical modularization and stable game state management. Each game addresses specific programming challenges:

- **Greedy Snake**: Coordinates dynamic memory and real-time user input.
- **Minesweeper**: Utilizes graph search algorithms to handle board expansion logic[cite: 1].
- **1A2B**: Implements input validation mechanisms and random sequence generation algorithms[cite: 1].

## Core Technologies and Features

### Greedy Snake
- **Keyboard Event Handling**: Uses `<conio.h>` to implement non-blocking keyboard input (`_kbhit`, `_getch`) for real-time movement control[cite: 1].
- **Container Management**: Utilizes `std::vector` to manage snake body coordinates, enabling efficient growth and displacement[cite: 1].
- **Collision Detection**: Implements boundary and self-collision checks to ensure strict adherence to game rules[cite: 1].

### Minesweeper
- **Algorithm Implementation**: Employs Breadth-First Search (BFS) with `std::queue` to automatically expand surrounding empty cells[cite: 1].
- **Dynamic Mine Placement**: Designs mine configuration logic to optimize the user experience[cite: 1].
- **State Management**: Defines a `Cell` structure to maintain mine configuration and reveal status[cite: 1].

### 1A2B
- **Randomization**: Integrates `std::shuffle` and random number engines to ensure unique target sequence generation[cite: 1].
- **Logic Matching**: Applies nested loops and flagging methods to accurately determine the count of "A"s and "B"s[cite: 1].
- **Input Validation**: Implements robust string input validation to handle length, type, and character repetition checks[cite: 1].

## Project Structure

- `/greedy snake`: Source code for the Greedy Snake game[cite: 1].
- `/Minesweeper.cpp`: Source code for the Minesweeper game[cite: 1].
- `/1A2B`: Source code for the 1A2B number guessing game[cite: 1].

## Usage Guide

1. **Prerequisites**: Ensure a C++ compiler (such as G++ or Visual Studio) is installed.
2. **Compilation**: Use the following command in your terminal to compile:
```bash
   g++ -o [executable_name] [source_file.cpp]
