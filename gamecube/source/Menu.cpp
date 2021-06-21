//
// NGC
// Menu.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include <string>
#include "font_ttf.h"
#include "Menu.hpp"
#include "Color.hpp"
#include "Canvas.hpp"

#define pressA() PAD_ButtonsDown(0) & PAD_BUTTON_A

Menu::Menu() {
    start = false;
    menuPos = 0;
    load();
}

Menu::~Menu() {
}

void Menu::load() {
    font = GRRLIB_LoadTTF(font_ttf, font_ttf_size);
}

void Menu::input() {
    PAD_ScanPads();

    int dy = PAD_StickY(0);
    if (dy > 18) {
        if (menuPos > 0) {
            menuPos--;
        }
    } 

    if (dy < -18) {
        if (menuPos >= 0 && menuPos < 2) {
            menuPos++;
        }
    }
		
	if (pressA()) {
		start = true;
	}
}

int Menu::loop() {
    
    while (!start) {
        input();
       
        GRRLIB_FillScreen(Color::getBlack()); 
        GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 150, Canvas::screenHeight/2 - 150, font, "Color Square", 72, Color::getBlue());
    
        if (menuPos == 0) {
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 66, Canvas::screenHeight/2 + 64, font, "- 2 players - ", 16, Color::getOrange());
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 66, Canvas::screenHeight/2 + 96, font, "- 3 players - ", 16, Color::getGray());
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 66, Canvas::screenHeight/2 + 128, font, "- 4 players - ", 16, Color::getGray());
        }

        if (menuPos == 1) {
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 66, Canvas::screenHeight/2 + 64, font, "- 2 players - ", 16, Color::getGray());
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 66, Canvas::screenHeight/2 + 96, font, "- 3 players - ", 16, Color::getOrange());
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 66, Canvas::screenHeight/2 + 128, font, "- 4 players - ", 16, Color::getGray());
 
        }

        if (menuPos == 2) {
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 66, Canvas::screenHeight/2 + 64, font, "- 2 players - ", 16, Color::getGray());
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 66, Canvas::screenHeight/2 + 96, font, "- 3 players - ", 16, Color::getGray());
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 66, Canvas::screenHeight/2 + 128, font, "- 4 players - ", 16, Color::getOrange());
        }

        GRRLIB_Render();
    }
    exit();
    return menuPos;
}

void Menu::exit() {
    GRRLIB_FreeTTF(font);
}