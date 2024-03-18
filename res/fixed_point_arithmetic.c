/*
    Filename: fixed_point_arithmetic.c
    Purpose: A black box library containing all arithmetic and printing dealing with fixed point
            binary numbers for Gameboy development.
    Author: Leopold Dohmann
    Copyright: 2024 Leopold Dohmann
*/
#include <gb/gb.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// CUSTOM FUNCTION TO PRINT NUMBERS OF A SPECIFIED AMOUNT OF DIGITS
void DrawNumber(uint8_t x, uint8_t y, int16_t number, uint8_t digits)
{
    unsigned char buffer[8]={'0','0','0','0','0','0','0','0',};

    // Convert the number to a decimal string (stored in the buffer char array)
    uitoa(number, buffer, 10);

    // The background address of the first digit
    uint8_t *vramAddr = get_bkg_xy_addr(x,y); 

    // Get the length of the number so we can add leading zeros
    uint8_t len = strlen(buffer);

    // Add some leading zeros
    // uitoa will not do for us
    // Increase the VRAM address each iteration to move to the next tile
    for (uint8_t i=0; i<digits-len;i++)
    {
        set_vram_byte(vramAddr++, 240); // 240 is the tile number with a 0
    }

    // Draw our number
    // Increase the VRAM address each iteration to move to the next tile
    for (uint8_t i=0; i<len; i++)
    {
        set_vram_byte(vramAddr++, (buffer[i] -'0')+240); // 272
    }
}

// CUSTOM FUNCTION TO PRINT NUMBERS OF A SPECIFIED AMOUNT OF DIGITS
void DrawBinary(uint8_t x, uint8_t y, int16_t n, int8_t digits)
{
    // The background address of the first digit
    uint8_t *vramAddr = get_bkg_xy_addr(x,y); 

    uint8_t c, k;
    for (c = digits - 1; c >= 0; c--)
    {
        k = n >> c;
        if (k & 1)
        {
            set_vram_byte(vramAddr++, 241); 
        }
        else 
        {
            set_vram_byte(vramAddr++, 240); 
        }
    }
}