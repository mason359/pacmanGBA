#ifndef DRAW_H
#define DRAW_H

#include "logic.h"

// This function will be used to draw everything about the state of your app
// including the background and whatnot.
void fullDrawAppState(AppState *state);

// This function will be used to undraw (i.e. erase) things that might
// move in a frame. E.g. in a Snake game, erase the Snake, the food & the score.
void undrawAppState(AppState *state);

// This function will be used to draw things that might have moved in a frame.
// For example, in a Snake game, draw the snake, the food, the score.
void drawAppState(AppState *state);

// If you have anything else you need accessible from outside the graphics.c
// file, you can add them here. You likely won't.

void drawPacman(AppState *state);
void undrawPacman(AppState *state);

void drawGhosts(AppState *state);
void undrawGhosts(AppState *state);

void drawMap(void);

void drawAllDots(AppState *state);
void drawDots(AppState *state);

void drawLives(AppState *state);
void drawLevel(AppState *state);

void drawReady(void);
void drawReady(void);

void drawPaused(void);
void undrawPaused(void);

void drawGameover(AppState *state);

#endif