#include "logic.h"

#include <stdlib.h>

#include "images/ghostRed.h"
#include "images/ghostPink.h"
#include "images/ghostOrange.h"
#include "images/ghostBlue.h"

void initializeAppState(AppState* appState) {
    // Initialize everything that's part of this AppState struct here.
    // Suppose the struct contains random values, make sure everything gets
    // the value it should have when the app begins.

    int gameMap[] = 
        {
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1,
            1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1,
            1, 3, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3, 1, 1,
            1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1,
            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1,
            1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1,
            1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1,
            1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1,
            1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1,
            0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1,
            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1,
            1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1,
            1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1,
            1, 3, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 3, 1, 1,
            1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1,
            1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1,
            1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1,
            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1,
            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1,
            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
        };

    // Initialize the player
    Pacman newPlayer;
    newPlayer.rpos = SUBPIXELR(23);
    newPlayer.cpos = SUBPIXELC(14) - 12;
    newPlayer.direction = LEFT;
    newPlayer.next = LEFT;

    // Initialize the ghosts
    const u16 *sprites[4] = {ghostRed, ghostBlue, ghostOrange, ghostPink};
    for (int i = 0; i < 4; i++) {
        appState->ghosts[i].rpos = SUBPIXELR(14);
        appState->ghosts[i].cpos = SUBPIXELC((12 + i));
        appState->ghosts[i].direction = UP;
        appState->ghosts[i].turnDelay = 0;
        appState->ghosts[i].sprite = sprites[i];
        appState->ghosts[i].hasPowerup = 0;
        appState->ghosts[i].cage = 200 * i + 1;
    }

    // Initialize the map
    appState->map = malloc(sizeof(int) * MAPWIDTH * MAPHEIGHT);
    appState->mapReset = malloc(sizeof(int) * MAPWIDTH * MAPHEIGHT);

    for (int i = 0; i < MAPHEIGHT * MAPWIDTH; i++) {
        appState->map[i] = gameMap[i];
        appState->mapReset[i] = gameMap[i];
    }


    // Initialize the rest of the app state properties
    appState->dots = 244;
    appState->gameOver = 0;
    appState->player = newPlayer;
    appState->powerup = 0;
    appState->lives = 2;
    appState->score = 0;
    appState->scoreMultiplier = 2;
    appState->died = 0;
    appState->win = 0;
    appState->level = 1;
    appState->difficulty = 50;
}

// This function processes the current app state and returns the new (i.e. next)
// state of your application.
AppState processAppState(AppState *currentAppState, u32 keysPressedNow) {

    AppState nextAppState = *currentAppState;

    // Check for directional input
    if (KEY_DOWN(BUTTON_LEFT, keysPressedNow)) {
        nextAppState.player.next = LEFT;
    }
    if (KEY_DOWN(BUTTON_RIGHT, keysPressedNow)) {
        nextAppState.player.next = RIGHT;
    }
    if (KEY_DOWN(BUTTON_UP, keysPressedNow)) {
        nextAppState.player.next = UP;
    }
    if (KEY_DOWN(BUTTON_DOWN, keysPressedNow)) {
        nextAppState.player.next = DOWN;
    }
    
    // Move the player and the ghosts and check if they collide
    processPlayer(&nextAppState);
    processGhosts(&nextAppState);
    checkCollisions(&nextAppState);

    // Check for the player eating dots, getting powerups, whether they beat the level, etc.
    if (nextAppState.map[OFFSET(GRIDR(nextAppState.player.rpos), GRIDC(nextAppState.player.cpos), MAPWIDTH)] == 2
        || nextAppState.map[OFFSET(GRIDR(nextAppState.player.rpos), GRIDC(nextAppState.player.cpos), MAPWIDTH)] == 3) {
        if (nextAppState.map[OFFSET(GRIDR(nextAppState.player.rpos), GRIDC(nextAppState.player.cpos), MAPWIDTH)] == 3) {
            nextAppState.powerup = 210;
            nextAppState.score += 40;
            nextAppState.scoreMultiplier = 2;
            for (int i = 0; i < 4; i++) {
                if (nextAppState.ghosts[i].cage <= 0) {
                    nextAppState.ghosts[i].hasPowerup = 1;
                }
            }
        }
        nextAppState.score += 10;
        nextAppState.dots--;
        nextAppState.map[OFFSET(GRIDR(nextAppState.player.rpos), GRIDC(nextAppState.player.cpos), MAPWIDTH)] = 0;
    }
    if (nextAppState.dots == 0) {
        nextAppState.win = 1;
    }
    if (nextAppState.powerup && vBlankCounter % 2 == 0) {
        nextAppState.powerup--;
    }

    return nextAppState;
}

// Change player direction and move the player
void processPlayer(AppState *state) {

    // Change direction
    if (state->player.next != state->player.direction) {
        switch (state->player.next) {
            case RIGHT:
                if (state->map[OFFSET(GRIDR(state->player.rpos), GRIDC(state->player.cpos) + 1, MAPWIDTH)] != 1) {
                    state->player.direction = state->player.next;
                    state->player.rpos = SUBPIXELR(GRIDR(state->player.rpos));
                }
                break;
            case LEFT:
                if (state->map[OFFSET(GRIDR(state->player.rpos), GRIDC(state->player.cpos) - 1, MAPWIDTH)] != 1) {
                    state->player.direction = state->player.next;
                    state->player.rpos = SUBPIXELR(GRIDR(state->player.rpos));
                }
                break;
            case UP:
                if (state->map[OFFSET(GRIDR(state->player.rpos) - 1, GRIDC(state->player.cpos), MAPWIDTH)] != 1) {
                    state->player.direction = state->player.next;
                    state->player.cpos = SUBPIXELC(GRIDC(state->player.cpos));
                }
                break;
            case DOWN:
                if (state->map[OFFSET(GRIDR(state->player.rpos) + 1, GRIDC(state->player.cpos), MAPWIDTH)] != 1) {
                    state->player.direction = state->player.next;
                    state->player.cpos = SUBPIXELC(GRIDC(state->player.cpos));
                }
                break;
        }
    }

    // Move the player
    switch (state->player.direction) {
        case RIGHT:
            if (state->map[OFFSET(GRIDR(state->player.rpos), GRIDC(state->player.cpos) + 1, MAPWIDTH)] != 1) {
                state->player.cpos += SPEED;
            }
            break;
        case LEFT:
            state->player.cpos -= SPEED;
            if (state->map[OFFSET(GRIDR(state->player.rpos), GRIDC(state->player.cpos), MAPWIDTH)] == 1) {
                state->player.cpos += SPEED;
            }
            break;
        case UP:
            state->player.rpos -= SPEED;
            if (state->map[OFFSET(GRIDR(state->player.rpos), GRIDC(state->player.cpos), MAPWIDTH)] == 1) {
                state->player.rpos += SPEED;
            }
            break;
        case DOWN:
            if (state->map[OFFSET(GRIDR(state->player.rpos) + 1, GRIDC(state->player.cpos), MAPWIDTH)] != 1) {
                state->player.rpos += SPEED;
            }
            break;
    }

    // Teleport player to opposite side for paths going off the side of the map
    if (state->player.cpos < SUBPIXELC(0)) {
        state->player.cpos = SUBPIXELC(28) - 5;
    } else if (state->player.cpos > SUBPIXELC(28) - 4) {
        state->player.cpos = SUBPIXELC(0);
    } 
}

// Change direction of ghosts and move them
void processGhosts(AppState *state) {

    // Change direction of each ghost
    for (int i = 0; i < 4; i++) {
        if (state->powerup <= 0) {
            state->ghosts[i].hasPowerup = 0;
        }
        state->ghosts[i].cage--;
        if (state->ghosts[i].cage <= 0) {
            if (state->ghosts[i].cage == 0) {
                state->ghosts[i].rpos = SUBPIXELR(11);
                state->ghosts[i].cpos = SUBPIXELC(14);
            }
            if (state->ghosts[i].turnDelay-- == 0) {
                int chance = randint(0, 100);
                if (chance > state->difficulty) {
                    turnAI(state, i);
                } else {
                    turnRandom(state, i);
                }
                if (state->ghosts[i].direction == UP || state->ghosts[i].direction == DOWN) {
                    state->ghosts[i].cpos = SUBPIXELC(GRIDC(state->ghosts[i].cpos));
                }
                if (state->ghosts[i].direction == LEFT || state->ghosts[i].direction == RIGHT) {
                    state->ghosts[i].rpos = SUBPIXELR(GRIDR(state->ghosts[i].rpos));
                }
                state->ghosts[i].turnDelay = 20;
            }

            // Move each ghost
            int speed = 3;
            if (state->ghosts[i].hasPowerup) {
                speed = 2;
            }
            switch (state->ghosts[i].direction) {
                case RIGHT:
                    if (state->map[OFFSET(GRIDR(state->ghosts[i].rpos), GRIDC(state->ghosts[i].cpos) + 1, MAPWIDTH)] != 1) {
                        state->ghosts[i].cpos += speed;
                    }
                    break;
                case LEFT:
                    state->ghosts[i].cpos -= speed;
                    if (state->map[OFFSET(GRIDR(state->ghosts[i].rpos), GRIDC(state->ghosts[i].cpos), MAPWIDTH)] == 1) {
                        state->ghosts[i].cpos += speed;
                    }
                    break;
                case UP:
                    state->ghosts[i].rpos -= speed;
                    if (state->map[OFFSET(GRIDR(state->ghosts[i].rpos), GRIDC(state->ghosts[i].cpos), MAPWIDTH)] == 1) {
                        state->ghosts[i].rpos += speed;
                    }
                    break;
                case DOWN:
                    if (state->map[OFFSET(GRIDR(state->ghosts[i].rpos) + 1, GRIDC(state->ghosts[i].cpos), MAPWIDTH)] != 1) {
                        state->ghosts[i].rpos += speed;
                    }
                    break;
            }

            // Teleport each ghost to the opposite side if the go through the path leading off the side
            if (state->ghosts[i].cpos < SUBPIXELC(0)) {
                state->ghosts[i].cpos = SUBPIXELC(28) - 5;
            } else if (state->ghosts[i].cpos > SUBPIXELC(28) - 4) {
                state->ghosts[i].cpos = SUBPIXELC(0);
            } 
        }
    }
}

// Turns the ghost in a random direction
void turnRandom(AppState *state, int index) {
    Direction possibleTurns[5];
    int i = 1;
    if (state->ghosts[index].direction != LEFT && state->map[OFFSET(GRIDR(state->ghosts[index].rpos), GRIDC(state->ghosts[index].cpos) + 1, MAPWIDTH)] != 1) {
        possibleTurns[i++] = RIGHT;
    }
    if (state->ghosts[index].direction != RIGHT && state->map[OFFSET(GRIDR(state->ghosts[index].rpos), GRIDC(state->ghosts[index].cpos) - 1, MAPWIDTH)] != 1) {
        possibleTurns[i++] = LEFT;
    }
    if (state->ghosts[index].direction != UP && state->map[OFFSET(GRIDR(state->ghosts[index].rpos) + 1, GRIDC(state->ghosts[index].cpos), MAPWIDTH)] != 1) {
        possibleTurns[i++] = DOWN;
    }
    if (state->ghosts[index].direction != DOWN && state->map[OFFSET(GRIDR(state->ghosts[index].rpos) - 1, GRIDC(state->ghosts[index].cpos), MAPWIDTH)] != 1) {
        possibleTurns[i++] = UP;
    }
    possibleTurns[0] = i;
    state->ghosts[index].direction = possibleTurns[randint(1, possibleTurns[0])];
}

// Turns the ghost towards the player (or away if the player has a powerup)
void turnAI(AppState *state, int index) {
    int possibleTurns[4] = {0, 0, 0, 0};
    if (state->ghosts[index].direction != LEFT && state->map[OFFSET(GRIDR(state->ghosts[index].rpos), GRIDC(state->ghosts[index].cpos) + 1, MAPWIDTH)] != 1) {
        possibleTurns[0] = 1; // RIGHT
    }
    if (state->ghosts[index].direction != RIGHT && state->map[OFFSET(GRIDR(state->ghosts[index].rpos), GRIDC(state->ghosts[index].cpos) - 1, MAPWIDTH)] != 1) {
        possibleTurns[1] = 1; // LEFT
    }
    if (state->ghosts[index].direction != UP && state->map[OFFSET(GRIDR(state->ghosts[index].rpos) + 1, GRIDC(state->ghosts[index].cpos), MAPWIDTH)] != 1) {
        possibleTurns[2] = 1; // DOWN
    }
    if (state->ghosts[index].direction != DOWN && state->map[OFFSET(GRIDR(state->ghosts[index].rpos) - 1, GRIDC(state->ghosts[index].cpos), MAPWIDTH)] != 1) {
        possibleTurns[3] = 1; // UP
    }
    if (state->ghosts[index].direction == RIGHT || state->ghosts[index].direction == LEFT) {
        if (state->ghosts[index].rpos - state->player.rpos < 0) {
            if (state->ghosts[index].hasPowerup && possibleTurns[3]) {
                state->ghosts[index].direction = UP;
            } else if (possibleTurns[2]) {
                state->ghosts[index].direction = DOWN;
            } else {
                turnRandom(state, index);
            }
        } else if (state->ghosts[index].rpos - state->player.rpos > 0 && possibleTurns[3]) {
            if (state->ghosts[index].hasPowerup && possibleTurns[2]) {
                state->ghosts[index].direction = DOWN;
            } else if (possibleTurns[3]) {
                state->ghosts[index].direction = UP;
            } else {
                turnRandom(state, index);
            }
        } else {
            turnRandom(state, index);
        }
    } else {
        if (state->ghosts[index].cpos - state->player.cpos < 0 && possibleTurns[0]) {
            if (state->ghosts[index].hasPowerup && possibleTurns[1]) {
                state->ghosts[index].direction = LEFT;
            } else if (possibleTurns[0]) {
                state->ghosts[index].direction = RIGHT;
            } else {
                turnRandom(state, index);
            }
        } else if (state->ghosts[index].cpos - state->player.cpos > 0 && possibleTurns[1]) {
            if (state->ghosts[index].hasPowerup && possibleTurns[0]) {
                state->ghosts[index].direction = RIGHT;
            } else if (possibleTurns[1]) {
                state->ghosts[index].direction = LEFT;
            } else {
                turnRandom(state, index);
            }
        } else {
            turnRandom(state, index);
        }
    }
}

// Check if the player hits a ghost and acts accordingly based on whether they have a powerup or not
void checkCollisions(AppState *state) {
    for (int i = 0; i < 4; i++) {
        int rdist = state->player.rpos - state->ghosts[i].rpos;
        int cdist = state->player.cpos - state->ghosts[i].cpos;
        if ((rdist > -20 && rdist < 20) && (cdist > -20 && cdist < 20)) {
            if (state->powerup && state->ghosts[i].hasPowerup) {
                resetGhost(state, i, 400);
                state->score += (100 * state->scoreMultiplier);
                state->scoreMultiplier *= 2;
            } else {
                state->gameOver = 1;
            }
        }
    }
}

// Puts the ghosts back in their starting states
void resetGhost(AppState *state, int i, int cage) {
    state->ghosts[i].rpos = SUBPIXELR(14);
    state->ghosts[i].cpos = SUBPIXELC((12 + i));
    state->ghosts[i].direction = RIGHT;
    state->ghosts[i].cage = cage;
    state->ghosts[i].hasPowerup = 0;
}

// Resets the map in cases where the player dies or beats the level
void resetMap(AppState *state) {
    state->player.rpos = SUBPIXELR(23);
    state->player.cpos = SUBPIXELC(14) - 12;
    state->player.direction = LEFT;
    state->player.next = LEFT;
    for (int i = 0; i < 4; i++) {
        resetGhost(state, i, 200 * i + 1);
    }
}

// Resets the map and takes away a life if the player dies
void processDeath(AppState *state) {
    resetMap(state);
    state->lives--;
    state->gameOver = 0;
}

// Resets the map including the dots, and increments the lives every third level, level count, and the difficulty
// when the player beats the level
void processWin(AppState *state) {
    resetMap(state);
    state->win = 0;
    state->level++;
    state->difficulty += 5;
    if (state->level % 3 == 1) {
        state->lives++;
    }
    for (int i = 0; i < MAPHEIGHT * MAPWIDTH; i++) {
        state->map[i] = state->mapReset[i];
    }
    state->dots = 244;
}