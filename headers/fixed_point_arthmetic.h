#include <gb/gb.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define ABS(x) ((x < 0) ? -x : x)
/**
 * Converts number to binary and prints out the result. NOT IMPLEMENTED!
 * 
 * @param number
 * A fixed point struct number.
*/
void DrawBinary(uint8_t x, uint8_t y, int16_t n, int8_t digits);

/**
 * Prints out a number onto the screen. NEED TO EDIT TO ACTUALLY PRINT NUMBERS
 * 
 * @param x 
 * X position in tiles to print number.
 * @param y
 * Y position in tiles to print number.
 * @param number
 * The number you wanted printed onto the screen
 * @param digits
 * How many digits to print onto the screen, not related to number param.
*/
void DrawNumber(uint8_t x, uint8_t y, uint16_t number, uint8_t digits);