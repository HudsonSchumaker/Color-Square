//
// NGC
// Menu.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include <grrlib.h>

class Menu final {
    public: 
        GRRLIB_ttfFont *font;
        
        Menu();
        ~Menu();
        int loop();

    private:
        bool start;
        int menuPos;
        void load();
        void input();
        void exit();
};
