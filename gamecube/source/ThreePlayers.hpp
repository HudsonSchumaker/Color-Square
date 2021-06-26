// 
// NGC
// ThreePlayers
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include <grrlib.h>
#include "Canvas.hpp"
#include "Square.hpp"
#include "Player.hpp"

class ThreePlayers final : public Canvas {

    public:
        const static int NUMBER_SQRT = 196;
        
        ThreePlayers();
        ~ThreePlayers();

        bool loop() override;
        void input() override; 
        void move() override;
        void collision() override;
        void render() override;
        void load() override;
        void unload() override;
        short result();

    private:
        int p1dx = 0;
        int p2dx = 0;
        int p3dx = 0;

        int p1dy = 0;
        int p2dy = 0;
        int p3dy = 0;

        Square squares[NUMBER_SQRT];
        Player player1;
        Player player2;
        Player player3;

        GRRLIB_texImg *grey_img;
        GRRLIB_texImg *red_img;
        GRRLIB_texImg *yellow_img;
        GRRLIB_texImg *blue_img;
        GRRLIB_texImg *player_1;
        GRRLIB_texImg *player_2;
        GRRLIB_texImg *player_3;
        GRRLIB_ttfFont *font;
        
        void movePlayer1();
        void movePlayer2();
        void movePlayer3();
};