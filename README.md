# Programming Assignment #6

**Due:2024/5/28 23:59:59**

NCCU OOP 112 spring

author: @organic_san at 2024/4/29

---

## Topic: Create a Console RPG Game (Part 2)
## Objective: Familiar with OOP concepts and connections between multiple files

## Description

### Game Objective
Create a small RPG game using the console, including processes such as entering the game, moving, switching rooms, battling, and ending.

Upon entering the game, the player will enter a room constructed of grid units of 35 * 20, which represents the map in the game. The player can use WASD keys for up, down, left, and right movements respectively. The player icon, labeled as "PL," will move within the room accordingly and will be obstructed by walls.

Rooms can be switched by moving to the left or right side of the current room. For this assignment, only horizontal room switching is considered, and vertical room switching is not. Rooms are connected horizontally via an id parameter. The room with the id of 0 is the leftmost room, and as you move right, the id increases by 1. Conversely, as you move left, the id decreases by 1. However, it's not possible to move to a room that does not exist.

Enemies with self-moving capabilities will appear in the game, requiring the design of monster movement patterns. Upon encountering a monster, the game will enter battle process. At this point, the player can choose from four options in a menu: Attack, Defend, Force Attack, and Heal. Detailed differences will be explained in subsequent assignments.

If the player is defeated by a monster, the game enters a game over state. Monsters can be set as final boss, and defeating an enemy marked as the final boss will lead to a game clear state.

A full version of the game can be played by executing this program:<br>
`./example/rpg-game-full-example`

### Assignment Objectives

The goal of this assignment is to implement room switching between left and right rooms, and to create a enemy movement system. When the player "PL" reaches the left or right edge of a room, if it's not the far left or far right edge, the player should move to the left or right room respectively, and the player's position should switch to the opposite side of the room. Enemies inherit from a new class: Enemy, each having different methods of movement. There won't be any combat mechanics introduced in this assignment.

Details regarding enemy design are as follows:

- Slime:
  - Moves randomly in up, down, left, or right directions each frame.
  - Avoids moving onto non-walkable tiles (defined in Room::walkable()).
  - Has 5 health points and deals 1 damage.
- Dragon:
  - Does not move.
  - Has 30 health points and deals 3 damage.

This assignment primarily focuses on object inheritance, class and function design.

Render function is already included in the assignment files, so there's no need to handle output formatting.

### Content to be Completed
- Please update your completed version of assign5 based on the differences between the commit for `'assign 5 code'` (dbcf521f) and the commit for `'assign 6 code'` (931e42ef) in this git record.
  Specifically, please compare based on the differences highlighted in [this link](https://github.com/oopnccucs/assign6/commit/931e42efd53d95a5db1edb9f5411fad3b266d392) on GitHub, or utilize `$git checkout <commit-hash>` to switch between commits and compare.

- Implement `Enemy` class, `Slime` class, and `Dragon` class, managing their relationship with `GameObject` class using inheritance
- Implement handling of `Enemy` in `room`
- Implement logic for player movement and room transition in `controller`
- Add logic for active movement of monsters in `controller`


## Sample Output
Please refer to the execution result of `./example/rpg-game-part2-example`, if successful, the following image will appear: 

![pic](https://i.imgur.com/lhKgeVc.png)

Where `WW` represents grass, `██` represents walls, `DR` represents doors, `PL` represents the player.

The names and types of terrain objects are recorded in `./src/gameobjects/room/roomstate.h`.

Moving to the right edge of the room will transition to the second room. Upon entering the second room, the following result will appear: 

![pic](https://i.imgur.com/9By0Wzi.png)

Where `WW` represents grass, `▲▲` represents rocks, `==` represents slimes, `PL` represents the player.

Slimes will move one grid in a random direction each frame, unaffected by grass but blocked by rocks. Currently, no action is taken when the player overlaps with a slime.

Upon entering the third room, the following result will appear: 

![pic](https://i.imgur.com/vpGXOVT.png)

Where `██` represents walls, `▲▲` represents rocks, `DR` represents doors, `Dn` represents dragons, `PL` represents the player, `~~` or `……` represents water.

Dragons do not move. Currently, no action is taken when the player overlaps with a dragon.


## Grading Criteria
| Grading Criteria | Score |
| - | - |
| File Upload | 20 pt |
| Compilation Successful | 15 pt |
| Character (PL) Can Switch Rooms | 15 pt |
| No Issues with Character (PL) During Room Switching | 10 pt |
| Enemy Appears in the Room | 10 pt |
| Slime Moves Autonomously | 15 pt |
| Slime's Movement is Impacted by Terrain Obstacles | 15 pt |
| **total** | **100 pt** |


## Assignment Directory
`/usr/local/class/oop/assign/assign6`


## Submission Instructions
In the OOP host, navigate to the assign6 directory and enter the following command:
```
/usr/local/class/oop/bin/submit 6
```
to submit this assignment.


## Files in the Assignment Directory

- `./src/main.cpp`: <br>
  Handles switching to console mode upon entering the game, captures keyboard input, and calls `game.lifeCycle(action)` periodically to create the game loop. The processed input becomes the entry point of each frame in the game.

- `./src/gamecore`: <br>
  Handles external operations received by the game.

- `./src/functions`:<br>
  Includes `AnsiPrint` and `position`.

- `./src/controller`:<br>
  Handles in-game responses. The `run()` function, called by `gamecore`, is the main loop of the game, executed once per frame.<br>
  In this assignment, room switching and monster movement need to be completed.

  - `enviroment`:<br>
    Stores environmental variables of the game. `SPEED` represents frames per second (s).

- `./src/gameobjects`:<br>
  Primarily handles game objects, including `player`, `room`, and `gameobject`.

  - `player`:<br>
    Inherits from the `GameObject` class.

  - `enemy`:<br>
    Inherits from the `GameObject` class, requires completion of relevant functions.

  - `slime` and `dragon`:<br>
    Inherits from the `Enemy` class, requires completion of relevant functions.

  - `room`:<br>
    Contains room contents and related behavior handling. The `Room` class represents a single room. Please complete the part related to `Enemy`.

  - `gameobject`:<br>
    Contains basic definitions of game objects.

- `./src/gameprocess`:<br>
  Currently records information about game process states, which will be gradually expanded in subsequent assignments.

## Implementation Notes

Compile: `$make`

Run: `$make run`

The completion of the assignment does not necessarily have to adhere to the provided methods. As long as similar results can be obtained, it's fine. However, the inheritance relationships and calls of objects need to be handled according to the provided methods.