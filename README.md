# Tetris Game in SFML

This project implements the classic Tetris game using the SFML (Simple and Fast Multimedia Library) in C++.

## Features

*   **Classic Tetris Gameplay:**  Standard Tetris rules with seven different tetromino shapes.
*   **Score Tracking:**  Keeps track of the player's score based on lines cleared.
*   **Level Progression:** The game speed increases as the score increases.
*   **Rotation:** Tetrominoes can be rotated to fit into tight spaces.
*   **Movement:** Tetrominoes can be moved left and right.
*   **Soft Drop:** Tetrominoes can be dropped faster by pressing the down key.
*   **Sound Effects:** Includes a sound effect for clearing lines.
*   **Game Over:**  The game ends when a tetromino reaches the top of the playfield.
*   **Visuals:** Simple but clear graphics using SFML's sprite and texture functionalities.

## Dependencies

*   **SFML (Simple and Fast Multimedia Library):**  Version 2.5 or later.  You will need to download and install SFML.  Make sure your compiler knows where to find the SFML headers and libraries.

## Building the Game

1.  **Install SFML:** If you haven't already, download and install SFML from the official website ([https://www.sfml-dev.org/](https://www.sfml-dev.org/)).  Follow the instructions for your operating system and compiler.

2.  **Create a Project:** Create a new C++ project in your IDE (Visual Studio, Code::Blocks, etc.).

3.  **Add Source Files:** Add the following source files to your project:
    *   `Game.h`
    *   `Game.cpp`
    *   `tetris.h`
    *   `tetris.cpp`
    *   `main.cpp`

4.  **Link SFML Libraries:**  You'll need to tell your compiler to link against the SFML libraries. The exact steps depend on your IDE.  Here are some general guidelines:

    *   **Visual Studio:**
        *   Go to Project -> Properties -> Configuration Properties -> Linker -> Input.
        *   Add the following to "Additional Dependencies":
            *   `sfml-graphics.lib`
            *   `sfml-window.lib`
            *   `sfml-system.lib`
            *   `sfml-audio.lib`
        *   In Configuration Properties -> C/C++ -> General, add the path to your SFML include directory in "Additional Include Directories".
        *   In Configuration Properties -> Linker -> General, add the path to your SFML library directory in "Additional Library Directories".

    *   **Code::Blocks:**
        *   Go to Project -> Build Options -> Linker Settings.
        *   Add the following to "Link Libraries":
            *   `sfml-graphics`
            *   `sfml-window`
            *   `sfml-system`
            *   `sfml-audio`
        *   In Search Directories -> Compiler, add the path to your SFML include directory.
        *   In Search Directories -> Linker, add the path to your SFML library directory.

5.  **Copy Assets:** Create an `images` folder and a `Sound` folder in your project directory (next to your source files).  Copy the `tiles.png` image into the `images` folder, `gameover.jpg` image into the `images` folder, and the `beep.wav` sound file into the `Sound` folder.  These files are required for the game to run correctly. Also create a `fonts` folder and add `Ariel.ttf` file for score.

6.  **Build and Run:** Build your project and run the executable.

## Controls

*   **Up Arrow:** Rotate the current piece.
*   **Left Arrow:** Move the current piece left.
*   **Right Arrow:** Move the current piece right.
*   **Down Arrow:** Soft drop (move the current piece down faster).
*   **Close Window:** Clicking the window's close button exits the game.

## Project Structure

*   **`Game.h` / `Game.cpp`:**  Base class for the game, handles window creation and management.
*   **`tetris.h` / `tetris.cpp`:**  Contains the main Tetris game logic, including piece movement, collision detection, scoring, and drawing.
*   **`main.cpp`:**  The entry point of the program.
*   **`images/tiles.png`:** Image file containing the tile sprites for the tetrominoes.
*   **`images/gameover.jpg`:** Image file containing the game over screen.
*   **`Sound/beep.wav`:** Sound file played when a line is cleared.
*   **`fonts/Ariel.ttf`:** Font file used to display the score.

## Code Explanation

*   **Game Class:** The `Game` class is responsible for creating and managing the SFML window.  It also handles basic initialization and event handling.

*   **Tetris Class:** The `tetris` class inherits from the `Game` class and implements the core Tetris game logic.  It manages the game board, tetromino shapes, movement, rotation, collision detection, scoring, and drawing.

*   **`main.cpp`:** The `main` function creates an instance of the `tetris` class and runs the game loop.

## Future Improvements

*   **Hold Piece:** Implement the ability to hold a piece for later use.
*   **Ghost Piece:** Display a ghost piece to show where the current piece will land.
*   **Improved Graphics:** Add more sophisticated graphics and animations.
*   **Menu System:** Implement a menu system for starting the game, configuring options, and viewing high scores.
*   **High Scores:** Save and load high scores.
*   **Difficulty Levels:** Implement different difficulty levels.
*   **Pause Functionality:** Add the ability to pause the game.
*   **Better Sound Design:** Add more sound effects and background music.
*   **Input Handling:** Decouple input from the game loop for more responsive controls.
*   **Refactor Collision Detection:** Improve the efficiency and readability of the collision detection code.
