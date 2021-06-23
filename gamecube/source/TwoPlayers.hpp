// 
// NGC
// Sprite
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include <grrlib.h>
#include "Canvas.hpp"
#include "Square.hpp"
#include "Player.hpp"

class TwoPlayers final : public Canvas {

    public:
        const static int NUMBER_SQRT = 156;
        
        TwoPlayers();
        ~TwoPlayers();

        bool loop() override;
        void input() override; 
        void move() override;
        void collision() override;
        void render() override;
        void load() override;
        void unload() override;

    private:
        bool levelOver = false;
        bool levelWon = false;

        int p1dx = 0;
        int p2dx = 0;

        int p1dy = 0;
        int p2dy = 0;

        Square squares[NUMBER_SQRT];
        Player player1;
        Player player2;

        GRRLIB_texImg *red_img;
        GRRLIB_texImg *grey_img;
        GRRLIB_texImg *yellow_img;
        GRRLIB_texImg *player_1;
        GRRLIB_ttfFont *font;
        
        void movePlayer1();
        void movePlayer2();
};