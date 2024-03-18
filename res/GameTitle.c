#include <gb/gb.h>
#include <stdint.h>
#include "../headers/common.h"
#include "../headers/Pond.h"

void GameTitleSetup()
{
    DISPLAY_OFF;
    HIDE_BKG;
    HIDE_SPRITES;
    set_bkg_data(0, Pond_TILE_COUNT, Pond_tiles);
    set_bkg_tiles(0, 0, Pond_WIDTH, Pond_HEIGHT, Pond_map);
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
}

uint8_t GameTitleUpdate()
{
    waitpad(J_START);
    fadeToBlack(30);
    return COREGAMELOOP;
}