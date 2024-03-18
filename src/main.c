#include <gb/gb.h>
#include "../headers/common.h"
#include "../headers/GameTitle.h"
#include "../headers/CoreGameLoop.h"

void main(void)
{
    uint8_t currentGameState = GAMEFIRSTLOAD;
    uint8_t nextGameState = GAMETITLE;

    // Loop forever
    while(1) { 
        /////////////////////////////////////////////////////////////////////
        //                 GAME STATE MACHINE                              //
        /////////////////////////////////////////////////////////////////////
        if (nextGameState != currentGameState)
        {
            currentGameState = nextGameState;

            if (currentGameState == GAMETITLE) GameTitleSetup();
            else if (currentGameState == COREGAMELOOP) CoreGameLoopSetup();
        }
        if (currentGameState == GAMETITLE) nextGameState = GameTitleUpdate();
        else if (currentGameState == COREGAMELOOP) nextGameState = CoreGameLoopUpdate();
        wait_vbl_done();
    }
}
