// 
// NGC
// Main.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include <fat.h>
#include <gccore.h>
#include <grrlib.h>
#include <asndlib.h>
#include <mp3player.h>

#include "Menu.hpp"
#include "Splash.hpp"
#include "TwoPlayers.hpp"
#include "ThreePlayers.hpp"
#include "FourPlayers.hpp"

void ini();
void end();

int main(void) {
    ini();
 
    Splash splash = Splash();
    
    for (;;) {
        Menu menu = Menu();
        int players = menu.loop();

        if (players == 0) {
            TwoPlayers two = TwoPlayers();
            two.loop();
        } 

        if (players == 1) {
            ThreePlayers three = ThreePlayers();
            three.loop();
        }

        if (players == 2) {
            FourPlayers four = FourPlayers();
            four.loop();
        }
    }
    
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
