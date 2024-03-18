#include <gb/gb.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/player.h"
#include "../headers/fixed_point_arthmetic.h"
#include "../headers/Pond.h"
#include "../headers/Background.h"
#include "../headers/Numbers_Tiles.h"

#define FLOOR_Y 120
#define GRAVITY 10

#define ALICE_RUN_FRAMECOUNT 3

// JOYPAD VARIABLES
uint8_t joypadCurrent=0;
uint8_t joypadPrevious=0;

void main(void)
{
    init_player_gfx(0);
    set_bkg_data(0, Background_TILE_COUNT, Background_tiles);
    set_bkg_data(240, 10, NumberTiles);
    set_bkg_tiles(0, 0, 20, 18, Background_map);
    struct player Alice = {80, 80, 0, 0, FLOOR_Y, FLOOR_Y, 0, 24, 0};
    //DrawBinary(4, 16, (uint8_t) 17, 8); // show subpixel value
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
        //DrawNumber(4, 16, Alice.faceX, 8);
        //DrawBinary(4, 17, joypadCurrent, 8); // show subpixel value

		// Done processing, yield CPU and wait for start of next frame
        wait_vbl_done();
    }
}
