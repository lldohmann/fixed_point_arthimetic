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

/*
* A class that contains the 16 bit fixed point number, it's scale (decimal place), & true int value
*/
typedef struct {
    uint16_t face, true;
    uint8_t scale;
} fixed_point;
/*
void printFixedPoint(fixed_point number, int x, int y)
{
    sprintf("\nFloating #: %d.%d \n", num>>8, (num&0xFF)*1000/(1<<8));
}
*/
void printBinary(fixed_point number)
{
    unsigned char buffer[16] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
    for (uint8_t i = 15; i >= 0; i--)
    {
        *buffer-- = (number.true & 1) + '0';
        number.true >>=1;
    }
    printf(buffer);
}