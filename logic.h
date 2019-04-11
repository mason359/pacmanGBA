#ifndef LOGIC_H
#define LOGIC_H

#include "gba.h"

#define MAPHEIGHT 32
#define MAPWIDTH 29

#define SPACESIZE 5
#define SPEED 3
#define POWERUPSPEED 2

#define GRIDR(row) ((row - 15) / (SPACESIZE * 5))
#define GRIDC(col) ((col - 15) / (SPACESIZE * 5))

#define SUBPIXELR(row) ((row * SPACESIZE * 5) + 15)
#define SUBPIXELC(col) ((col * SPACESIZE * 5) + 15)

#define GRID2PIXELR(row) (row * SPACESIZE) + 3
#define GRID2PIXELC(col) (col * SPACESIZE) + 3

#define SUB2PIXELR(row) (((row - 15) / 5) + 3)
#define SUB2PIXELC(col) (((col - 15) / 5) + 3)

#define TRANSITION_DELAY 800

// Enum to represent the directions for the player and ghost
typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

// Struct that represents the player
typedef struct {
    int rpos;
    int cpos;
    Direction direction;
    Direction next;
} Pacman;

// Struct that represents a ghost
typedef struct {
    int rpos;
    int cpos;
    Direction direction;
    const u16 *sprite;
    int turnDelay;
    int hasPowerup;
    int cage;
} Ghost;

// Struct that contains all the information for the app state
typedef struct {
    int gameOver;
    Pacman player;
    Ghost ghosts[4];
    int *map;
    int *mapReset;
    int dots;
    int powerup;
    int lives;
    int score;
    int scoreMultiplier;
    int died;
    int win;
    int level;
    int difficulty;
} AppState;

void initializeAppState(AppState *appState);

AppState processAppState(AppState *currentAppState, u32 keysPressedNow);

void processPlayer(AppState *state);

void processGhosts(AppState *state);
void turnRandom(AppState *state, int index);
void turnAI(AppState *state, int index);
void resetGhost(AppState *state, int i, int cage);

void checkCollisions(AppState *state);

void processDeath(AppState *state);
void processWin(AppState *state);

void drawReady(void);
void undrawReady(void);

#endif