#include <gb/gb.h>

uint8_t joypadCurrent;
uint8_t joypadPrevious;

void performantdelay(uint8_t numloops)
{
    for (uint8_t i = 0; i < numloops; i++)
    {
        wait_vbl_done();
    }
}

void fadeToBlack(uint8_t frames)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        switch(i) 
        {
            case 0: 
                BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK);
                break;
            case 1: 
                BGP_REG = DMG_PALETTE(DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK, DMG_BLACK);
                break;
            case 2:
                BGP_REG = DMG_PALETTE(DMG_DARK_GRAY, DMG_BLACK, DMG_BLACK, DMG_BLACK);
                break;
            case 3:
                BGP_REG = DMG_PALETTE(DMG_BLACK, DMG_BLACK, DMG_BLACK, DMG_BLACK);
                break;
        }
        performantdelay(frames);
    }
}

void fadeFromBlack(uint8_t frames)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        switch(i) 
        {
            case 0: 
                BGP_REG = DMG_PALETTE(DMG_DARK_GRAY, DMG_BLACK, DMG_BLACK, DMG_BLACK);
                break;
            case 1: 
                BGP_REG = DMG_PALETTE(DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK, DMG_BLACK);
                break;
            case 2:
                BGP_REG = DMG_PALETTE(DMG_LITE_GRAY, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK);
                break;
            case 3:
                BGP_REG = DMG_PALETTE(DMG_WHITE, DMG_LITE_GRAY, DMG_DARK_GRAY, DMG_BLACK);
                break;
        }
        performantdelay(frames);
    }
}