#include <gb/gb.h>
#include "../headers/player.h"
#include "../headers/Background.h"
#include "../headers/Numbers_Tiles.h"
#include "../headers/common.h"

#define FLOOR_Y 120

struct player Alice = {80, 80, 0, 0, FLOOR_Y, FLOOR_Y, 0, 24, 0};

void CoreGameLoopSetup()
{
    init_player_gfx(0);
    set_bkg_data(0, Background_TILE_COUNT, Background_tiles);
    set_bkg_data(240, 10, NumberTiles);
    set_bkg_tiles(0, 0, 20, 18, Background_map);
    SPRITES_8x16;
    fadeFromBlack(30);
}

uint8_t CoreGameLoopUpdate()
{
    // GET INPUT
        joypadPrevious=joypadCurrent;
        joypadCurrent=joypad();
        int16_t movement= HandleInput(&Alice, joypadCurrent);

        /////////////////////////////////////////
        //           MOVEMENT CODE             //
        ////////////////////////////////////////
        PlayerUpdate(&Alice);
        PlayerDraw(&Alice);

		// Done processing, yield CPU and wait for start of next frame
        wait_vbl_done();
        return COREGAMELOOP;
}