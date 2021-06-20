// 
// NGC
// Main
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include <fat.h>
#include <gccore.h>
#include <grrlib.h>
#include <asndlib.h>
#include <mp3player.h>

#include "Splash.hpp"

void ini();
void end();

int main(void) {
    ini();
 
    Splash splash = Splash();
       
    end();
    return 0;
}

void ini() {
    ASND_Init();
    MP3Player_Init();
    PAD_Init();
    GRRLIB_Init();
}

void end() {
    GRRLIB_Exit();
}
