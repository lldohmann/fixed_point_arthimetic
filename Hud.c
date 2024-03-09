#include <gb/gb.h>
#include <stdlib.h>
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
        set_vram_byte(vramAddr++, 272);
    }

    // Draw our number
    // Increase the VRAM address each iteration to move to the next tile
    for (uint8_t i=0; i<len; i++)
    {
        set_vram_byte(vramAddr++, (buffer[i] -'0')+272);
    }
}