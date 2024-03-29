#include "draw.h"
#include "gba.h"
#include <stdio.h>
#include <string.h>

// Include any header files for images generated by nin10kit.
// Example for the provided garbage image:
#include "images/pacmanLeft.h"
#include "images/pacmanRight.h"
#include "images/pacmanUp.h"
#include "images/pacmanDown.h"
#include "images/ghostPowerupBlue.h"
#include "images/ghostPowerupWhite.h"
#include "images/ready.h"
#include "images/maze.h"
#include "images/paused.h"
#include "images/gameover.h"

// This function will be used to draw everything about the app
// including the background and whatnot.
void fullDrawAppState(AppState *state) {
    fillScreenDMA(BLACK);
    drawMap();
    drawAllDots(state);
    drawPacman(state);
    drawGhosts(state);
    drawString(5, 150, "LEVEL:", WHITE);
    drawString(16, 150, "SCORE:", WHITE);
    drawString(148, 150, "LIVES:", WHITE);
    drawLives(state);
    drawLevel(state);
    drawReady();
}

// Undraws the current app state
void undrawAppState(AppState *state) {
    undrawPacman(state);
    undrawGhosts(state);
    drawDots(state);
    drawRectDMA(16, 186, 42, 8, BLACK);
}

// This function will be used to draw things that might have moved in a frame.
void drawAppState(AppState *state) {
    drawPacman(state);
    drawGhosts(state);
    char pos[16];
    sprintf(pos, "%d", state->score);
    drawString(16, 186, pos, WHITE);
}

// Draws the player in the correct orientation
void drawPacman(AppState *state) {
	switch(state->player.direction) {
		case LEFT:
			drawImageDMA(SUB2PIXELR(state->player.rpos) - 1, SUB2PIXELC(state->player.cpos) - 1, 7, 7, pacmanLeft);
			break;
		case RIGHT:
			drawImageDMA(SUB2PIXELR(state->player.rpos) - 1, SUB2PIXELC(state->player.cpos) - 1, 7, 7, pacmanRight);
			break;
		case UP:
			drawImageDMA(SUB2PIXELR(state->player.rpos) - 1, SUB2PIXELC(state->player.cpos) - 1, 7, 7, pacmanUp);
			break;
		case DOWN:
			drawImageDMA(SUB2PIXELR(state->player.rpos) - 1, SUB2PIXELC(state->player.cpos) - 1, 7, 7, pacmanDown);
			break;
	}
}

// Undraws the player
void undrawPacman(AppState *state) {
	drawRectDMA(SUB2PIXELR(state->player.rpos) - 1, SUB2PIXELC(state->player.cpos) - 1, 7, 7, BLACK);
}

// Draws each of the ghosts
void drawGhosts(AppState *state) {
	for (int i = 0; i < 4; i++) {
		if (state->powerup && state->ghosts[i].hasPowerup) {
			if (state->powerup < 50 && state->powerup % 20 < 10) {
				drawImageDMA(SUB2PIXELR(state->ghosts[i].rpos) - 1, SUB2PIXELC(state->ghosts[i].cpos) - 1, 7, 7, ghostPowerupWhite);
			} else {
				drawImageDMA(SUB2PIXELR(state->ghosts[i].rpos) - 1, SUB2PIXELC(state->ghosts[i].cpos) - 1, 7, 7, ghostPowerupBlue);
			}
		} else {
			drawImageDMA(SUB2PIXELR(state->ghosts[i].rpos) - 1, SUB2PIXELC(state->ghosts[i].cpos) - 1, 7, 7, state->ghosts[i].sprite);
		}
	}
}

// Undraws each of the ghosts
void undrawGhosts(AppState *state) {
	for (int i = 0; i < 4; i++) {
		drawRectDMA(SUB2PIXELR(state->ghosts[i].rpos) - 1, SUB2PIXELC(state->ghosts[i].cpos) - 1, 7, 7, BLACK);
	}
}

// Redraws dots that haven't been eaten yet after the player and ghosts move over them
void drawDots(AppState *state) {
	if (state->map[OFFSET(GRIDR(state->player.rpos) + 1, GRIDC(state->player.cpos), MAPWIDTH)] == 2) {
		setPixel(GRID2PIXELR((GRIDR(state->player.rpos) + 1)) + 2, GRID2PIXELC(GRIDC(state->player.cpos)) + 2, WHITE);
	}
	if (state->map[OFFSET(GRIDR(state->player.rpos), GRIDC(state->player.cpos) + 1, MAPWIDTH)] == 2) {
		setPixel(GRID2PIXELR(GRIDR(state->player.rpos)) + 2, GRID2PIXELC((GRIDC(state->player.cpos) + 1)) + 2, WHITE);
	}
	if (state->map[OFFSET(GRIDR(state->player.rpos) + 1, GRIDC(state->player.cpos), MAPWIDTH)] == 3) {
		drawRectDMA(GRID2PIXELR((GRIDR(state->player.rpos) + 1)) + 1, GRID2PIXELC(GRIDC(state->player.cpos)) + 1, 3, 3, WHITE);
	}
	if (state->map[OFFSET(GRIDR(state->player.rpos), GRIDC(state->player.cpos) + 1, MAPWIDTH)] == 3) {
		drawRectDMA(GRID2PIXELR(GRIDR(state->player.rpos)) + 1, GRID2PIXELC((GRIDC(state->player.cpos) + 1)) + 1, 3, 3, WHITE);
	}
	for (int i = 0; i < 4; i++) {
		for (int r = GRIDR(state->ghosts[i].rpos) - 1; r < GRIDR(state->ghosts[i].rpos) + 2; r++) {
			for (int c = GRIDC(state->ghosts[i].cpos) - 1; c < GRIDC(state->ghosts[i].cpos) + 2; c++) {
				if (state->map[OFFSET(r, c, MAPWIDTH)] == 2) {
					setPixel(GRID2PIXELR(r) + 2, GRID2PIXELC(c) + 2, WHITE);
				}
				if (state->map[OFFSET(r, c, MAPWIDTH)] == 3) {
					drawRectDMA(GRID2PIXELR(r) + 1, GRID2PIXELC(c) + 1, 3, 3, WHITE);
				}
			}
		}
	}
}

// Draws the image of the maze on the screen
void drawMap(void) {
	drawImageDMA(0, 0, 145, 160, maze);
}

// Draws all the dots on the map when starting a new level
void drawAllDots(AppState *state) {
	for (int i = 0; i < MAPHEIGHT; i++) {
		for (int j = 0; j < MAPWIDTH; j++) {
			if (state->map[OFFSET(i, j, MAPWIDTH)] == 2) {
				setPixel(GRID2PIXELR(i) + 2, GRID2PIXELC(j) + 2, WHITE);
			}
			if (state->map[OFFSET(i, j, MAPWIDTH)] == 3) {
				drawRectDMA(GRID2PIXELR(i) + 1, GRID2PIXELC(j) + 1, 3, 3, WHITE);
			}
		}
	}
}

// Draws the lives whenever the number of lives change
void drawLives(AppState *state) {
	drawRectDMA(148, 190, 50, 7, BLACK);
	for (int i = 0; i < state->lives + 1; i++) {
		drawImageDMA(148, 10 * i + 190, 7, 7, pacmanRight);
	}
}

// Draws the level number each time a new level is started
void drawLevel(AppState *state) {
	drawRectDMA(5, 187, 30, 8, BLACK);
	char level[4];
	sprintf(level, "%d", state->level);
	drawString(5, 187, level, WHITE);
}

// Draws "READY!" in the middle of the map when starting a new level
void drawReady(void) {
	drawImageDMA(GRID2PIXELR(17) - 1, GRID2PIXELC(12), 25, 7, ready);
}

// Undraws "READY!" once the level starts
void undrawReady(void) {
	drawRectDMA(GRID2PIXELR(17) - 1, GRID2PIXELC(12), 25, 7, BLACK);
}

// Draw "PAUSED" on the screen
void drawPaused(void) {
	drawImageDMA(69, 153, 80, 12, paused);
}

// Undraw "PAUSED" from the screen
void undrawPaused(void) {
	drawRectDMA(69, 153, 80, 12, BLACK);
}

// Draw the gameover screen and display final score
void drawGameover(AppState *state) {
	drawFullScreenImageDMA(gameover);
	drawString(120, 84, "FINAL SCORE:", WHITE);
	char pos[16];
    sprintf(pos, "%d", state->score);
    drawString(135, 120 - (strlen(pos) * 3), pos, WHITE);
}