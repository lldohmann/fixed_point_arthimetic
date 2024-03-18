#include <gb/gb.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/player.h"
#include "../headers/fixed_point_arthmetic.h"
#include "../headers/Pond.h"
#include "../headers/Background.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define ABS(x) ((x < 0) ? -x : x)

#define FLOOR_Y 100
#define GRAVITY 10

#define ALICE_RUN_FRAMECOUNT 3

// JOYPAD VARIABLES
uint8_t joypadCurrent=0;
uint8_t joypadPrevious=0;

void main(void)
{
    init_player_gfx(0);
    set_bkg_data(0, Background_TILE_COUNT, Background_tiles);
    set_bkg_tiles(0, 0, 20, 18, Background_map);
    struct player Alice = {80, 80, 0, 0, 100, 100, 0, 24, 0};
    //printBinary(number);
    // INIT graphics
    SHOW_BKG;
    SHOW_SPRITES;
    SPRITES_8x16;
    DISPLAY_ON;

    // Loop forever
    while(1) { 
        // GET INPUT
        joypadPrevious=joypadCurrent;
        joypadCurrent=joypad();
        int16_t movement= HandleInput(&Alice, joypadCurrent);

        /////////////////////////////////////////
        //           MOVEMENT CODE             //
        ////////////////////////////////////////
        PlayerUpdate(&Alice);

		// Game main loop processing goes here
        // DRAW ALICE LOGIC AT THE END OF ALL CODE
        PlayerDraw(&Alice);
        DrawNumber(4, 16, Alice.faceX, 8);

		// Done processing, yield CPU and wait for start of next frame
        wait_vbl_done();
    }
}
