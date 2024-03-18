#define GAMEFIRSTLOAD 0
#define GAMETITLE 1
#define COREGAMELOOP 2

extern uint8_t joypadPrevious, joypadCurrent;

/**
 * Stalls the game a specified number of frames.
 * 
 * @param numloops
 * The number of frames to wait.
*/
void performantdelay(uint8_t numloops);

/**
 * Slowly causes the background pallet to turn black.
 * 
 * @param frames
 * The time it takes to change background pallet to black in frames. 
*/
void fadeToBlack(uint8_t frames);

/**
 * Slowly causes the background pallet to return to normal from a black screen.
 * 
 * @param frames
 * The time it takes to change background pallet in frames. 
*/
void fadeFromBlack(uint8_t frames);