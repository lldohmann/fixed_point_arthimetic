#include <gb/gb.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gb/metasprites.h>
#include "Alice.h"
#include "Hud.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define ABS(x) ((x < 0) ? -x : x)

#define FLOOR_Y 100

#define ALICE_RUN_FRAMECOUNT 3

// PLAYER VARIABLES
uint16_t aliceX = 80; // FACE VALUE (HOLDS FRACTIONAL PART)
uint16_t aliceDrawX = 80; // TRUE VALUE
uint8_t aliceFrame = 0; // FACE VALUE (HOLDS FRACTIONAL PART)
uint16_t aliceDrawFrame; // TRUE VALUE
uint8_t aliceDirection;
int8_t speed = 24;
int8_t currentSpeed=0;
// JOYPAD VARIABLES
uint8_t joypadCurrent=0;
uint8_t joypadPrevious=0;
// TEST VARIABLES
uint16_t answer = 8738;

// DEFINE ALICE METASPRITES
const metasprite_t alice_metasprite0[] = {
    {.dy=-16, .dx=-8, .dtile=0, .props=0},
    {.dy=0, .dx=8, .dtile=2, .props=0},
    {.dy=16, .dx=-8, .dtile=8, .props=0},
    {.dy=0, .dx=8, .dtile=10, .props=0},
    METASPR_TERM
};
const metasprite_t alice_metasprite1[] = {
    {.dy=-16, .dx=-8, .dtile=0, .props=0},
    {.dy=0, .dx=8, .dtile=2, .props=0},
    {.dy=16, .dx=-8, .dtile=12, .props=0},
    {.dy=0, .dx=8, .dtile=14, .props=0},
    METASPR_TERM
};
const metasprite_t alice_metasprite2[] = {
    {.dy=-16, .dx=-8, .dtile=0, .props=0},
    {.dy=0, .dx=8, .dtile=2, .props=0},
    {.dy=16, .dx=-8, .dtile=16, .props=0},
    {.dy=0, .dx=8, .dtile=18, .props=0},
    METASPR_TERM
};
const metasprite_t* const alice_metasprites[3] = {
    alice_metasprite0, alice_metasprite1, alice_metasprite2
};

int8_t HandleInput()
{
    int8_t movement = 0;
    if(joypadCurrent & J_LEFT)
    {
        movement = -1;
        aliceDirection=0;
        if (currentSpeed > -speed)
        {
            currentSpeed-=2;
        }
    }
    else if (joypadCurrent & J_RIGHT)
    {
        movement = 1;
        aliceDirection = 1;
        if (currentSpeed < speed)
        {
            currentSpeed+=2;
        }
    }
    else if (joypadCurrent & J_UP)
    {
        speed++;
    }
    else if (joypadCurrent & J_DOWN)
    {
        speed--;
    }
    else{
        if (currentSpeed!=0)
        {
            currentSpeed-=2;
        }
    }
    return movement;
}
/**
void printFloat16(uint16_t num)
{
    sprintf("\nFloating #: %d.%d \n", num>>8, (num&0xFF)*1000/(1<<8));
}
**/

void main(void)
{
    set_sprite_data(0, 40, AliceTileLabel); // put alice tiles in VRAM
    // INIT graphics
    SHOW_BKG;
    SHOW_SPRITES;
    SPRITES_8x16;
    DISPLAY_ON;

    aliceX = 80;
    aliceDrawX = aliceX;
    aliceDrawFrame = aliceFrame;

    //uint8_t startingSprite=0;
    //startingSprite+=move_metasprite(alice_metasprite, 0, startingSprite, aliceDrawX, FLOOR_Y);
    //hide_sprites_range(startingSprite, 40);

    // Loop forever
    while(1) { 
        // GET INPUT
        joypadPrevious=joypadCurrent;
        joypadCurrent=joypad();
        int16_t movement= HandleInput();

        /////////////////////////////////////////
        //           MOVEMENT CODE             //
        ////////////////////////////////////////
        // SUBPIXEL RESOLUTION
        // Increase / decrease the "face" value
        aliceX+=movement*speed; // this is alice's velocity we're calculating
        // Draw Alice at the true value
        aliceDrawX=aliceX>>4;

        if (movement!=0)
        {
            aliceFrame +=2;
            // Increase Alice's frame
            // Loop background after 3
            // Shift right 4 bits to get it's true value
            if ((aliceFrame>>4)>=ALICE_RUN_FRAMECOUNT)aliceFrame=0;
            // Frame 0 is or standing
            // Increase by onr for running frames
            // shift right 4 bits to get it's true value
            aliceDrawFrame=1+aliceFrame>>4;
        }
        else 
        {
            // draw with our standing frame 0
            aliceFrame=0;
            aliceDrawFrame=0;
        }

		// Game main loop processing goes here
        // DRAW ALICE LOGIC AT THE END OF ALL CODE
        if (aliceDirection==1)move_metasprite(alice_metasprites[aliceDrawFrame], 0, 0,aliceDrawX, FLOOR_Y);
        else move_metasprite_vflip(alice_metasprites[aliceDrawFrame], 0, 0, aliceDrawX,FLOOR_Y);

		// Done processing, yield CPU and wait for start of next frame
        wait_vbl_done();
    }
}
