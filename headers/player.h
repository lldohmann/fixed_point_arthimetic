#pragma once

/**
 * A player object that represents the player's avatar. 
 * a 2D side scrolling character
*/

typedef struct player {
    uint16_t faceX; // FACE VALUE (HOLDS THE FRACTIONAL PART)
    uint16_t drawX; // TRUE VALUE
    uint8_t faceFrame;
    uint16_t drawFrame;
    uint16_t faceY;
    uint16_t drawY;
    uint8_t direction;
    uint8_t speed;
    uint8_t currentSpeed;
};

/**
 * Handles the loading of all Alice tiles into VRAM.
 * 
 * @param first_tile
 * The position in VRAM where all the tiles are to be loaded.
*/
void init_player_gfx(uint8_t first_tile);

/**
 * Handles user input that affects the speed and direction the player is going.
 * 
 * @param ptr
 * A pointer to the player character.
 * @param joypadCurrent
 * A reference to the current state of the joypad.
*/
int8_t HandleInput(struct player *ptr, uint8_t joypadCurrent);

/**
 * Handles internal logic of the player that is to be updated every tick
 * 
 * @param ptr
 * A pointer to the player character
*/
void PlayerUpdate(struct player *ptr);

/**
 * Handles the logic for drawing the player onto the screen
 * 
 * @param ptr
 * A pointer to the player character
*/
void PlayerDraw(struct player *ptr);