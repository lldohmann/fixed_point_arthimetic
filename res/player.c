#include <gb/gb.h>
#include <stdint.h>
#include <gb/metasprites.h>
#include "../headers/Alice_Tiles.h"
#include "../headers/player.h"

// DEFINE ALICE METASPRITES
const metasprite_t alice_run0[] = {
    {.dy=-16, .dx=-8, .dtile=0, .props=0},
    {.dy=0, .dx=8, .dtile=2, .props=0},
    {.dy=16, .dx=-8, .dtile=8, .props=0},
    {.dy=0, .dx=8, .dtile=10, .props=0},
    METASPR_TERM
};
const metasprite_t alice_run1[] = {
    {.dy=-16, .dx=-8, .dtile=0, .props=0},
    {.dy=0, .dx=8, .dtile=2, .props=0},
    {.dy=16, .dx=-8, .dtile=12, .props=0},
    {.dy=0, .dx=8, .dtile=14, .props=0},
    METASPR_TERM
};
const metasprite_t alice_run2[] = {
    {.dy=-16, .dx=-8, .dtile=0, .props=0},
    {.dy=0, .dx=8, .dtile=2, .props=0},
    {.dy=16, .dx=-8, .dtile=16, .props=0},
    {.dy=0, .dx=8, .dtile=18, .props=0},
    METASPR_TERM
};
const metasprite_t alice_crouch[] = {
    {.dy=16, .dx = -8, .dtile=20, .props=0},
    {.dy=0, .dx=8, .dtile=22, .props=0},
    METASPR_TERM
};
const metasprite_t* const alice_metasprites[4] = {
    alice_run0, alice_run1, alice_run2, alice_crouch
};

void init_player_gfx(uint8_t first_tile)
{
    set_sprite_data(first_tile, 40, AliceTileLabel);
}

int8_t HandleInput(struct player *ptr, uint8_t joypadCurrent)
{
    int8_t movement = 0;
    if (joypadCurrent & J_LEFT)
    {
        movement = -1;
        ptr->direction = 0;
        if (ptr->currentSpeed > ptr->speed)
        {
            ptr->currentSpeed -= 2;
        }
    }
    else if (joypadCurrent & J_RIGHT)
    {
        movement = 1;
        ptr->direction = 1;
        if (ptr->currentSpeed < ptr->speed)
        {
            ptr->currentSpeed+=2;
        }
    }
    return movement;
}

void PlayerUpdate(struct player *ptr)
{
    int8_t movement = HandleInput(ptr, joypad());
    // MOVEMENT CODE - SUBPIXEL RESOLUTION
    // Increase / decrease the 'face' value
    ptr->faceX += movement * ptr->speed; // this is alice's velocity we're calculating
    ptr->drawX = ptr->faceX>>4;
    if (movement != 0)
    {
        ptr->faceFrame += 2;
        // Increase Alice's frame
        // Loop background after 3
        // shift right 4 bits to get it's true value
        if ((ptr->faceFrame>>4) >= 3) ptr->faceFrame = 0;
        // Frame 0 is or standing
        // Increase by one for running frames
        // shift right 4 bits to get it's true value
        ptr->drawFrame = 1 + ptr->faceFrame>>4;
    }
    else
    {   /**
        if (joypadCurrent & J_DOWN) // CROUTCHING
        {
            ptr->drawFrame = 3;
        }
        else
        {
            ptr->faceFrame = 0;
            ptr->drawFrame = 0;
        } */
        ptr->faceFrame = 0;
        ptr->drawFrame = 0;
    }
}

void PlayerDraw(struct player *ptr)
{
    // DRAW ALICE LOGIC AT THE END OF ALL CODE
    if (ptr->direction == 1) 
    {
        move_metasprite(alice_metasprites[ptr->drawFrame], 0, 0, ptr->drawX, ptr->drawY); 
    }
    else {
        move_metasprite_vflip(alice_metasprites[ptr->drawFrame], 0, 0, ptr->drawX, ptr->drawY);
    }
}