#include <gb/gb.h>

void CoreGameLoopSetup()
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
}