//
// NGC
// TwoPlayers
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "TwoPlayers.hpp"
#include "Color.hpp"
#include "Point2D.hpp"
#include <mp3player.h>

#include "red_square_png.h"
#include "grey_square_png.h"
#include "yellow_square_png.h"
#include "beep_mp3.h"
#include "font_ttf.h"

TwoPlayers::TwoPlayers() {
    load();
}

TwoPlayers::~TwoPlayers() {
    unload();
}

bool TwoPlayers::loop() {

    int timer = 0;
    while(timer < 60) {
        GRRLIB_FillScreen(Color::getBlack()); 
        GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 60, Canvas::screenHeight/2 -20, font, "2 Players", 32, Color::getOrange());
        GRRLIB_Render();
        timer++;
    }

    while(!levelOver && !levelWon) {
        input(); 
        move();
        collision();
        render(); 
    }
    return levelWon;
}

void TwoPlayers::input() {
    PAD_ScanPads();
    p1dx = PAD_StickX(0);
    p2dx = PAD_StickX(1);

    p1dy = PAD_StickY(0);
    p2dy = PAD_StickY(1);
}

void TwoPlayers::move() {

    if (p1dy > 18) {
        player1.moveY(-3);
        return;
    } 
    if (p1dy < -18) {
        player1.moveY(3);
        return;
    }

    if (p1dx > 18) {
        player1.moveX(3);
        return;
    } 
    else if (p1dx < -18) {
        player1.moveX(-3);
    }

    if (p2dy > 18) {
        player2.moveY(-5);
    } 
    if (p2dy < -18) {
        player2.moveY(5);
    }

    if (p2dx > 18) {
        player2.moveX(5);
    } 
    if (p2dx < -18) {
        player2.moveX(-5);
    }

}

void TwoPlayers::collision() {

}

void TwoPlayers::render() {
    GRRLIB_FillScreen(Color::getBlack()); 
    // GRRLIB_DrawImg(128, 0, back_img, 0, 1, 1, Color::getWhite());

    for (int i = 0; i < NUMBER_SQRT; i++) {
        if (!squares[i].isDestroyed()) {
            squares[i].draw();
            // Draw bricks colliders
            // GRRLIB_Rectangle(bricks[i].getX(),  bricks[i].getY(),  bricks[i].getWidth(),  bricks[i].getHeight(),  Color::getWhite(), false);
        }
    }
    player1.draw();
    player2.draw();

    GRRLIB_Render();           
}

void TwoPlayers::load() {
    red_img = GRRLIB_LoadTexture(red_square_png);
    grey_img = GRRLIB_LoadTexture(grey_square_png);
    yellow_img = GRRLIB_LoadTexture(yellow_square_png);
    font = GRRLIB_LoadTTF(font_ttf, font_ttf_size);

    int s = 0;
    for (int l = 0; l < 12; l++) {
        for (int c = 0; c < 12; c++) {
            squares[s] = Square(c * grey_img->w + 128, l * grey_img->h + 64);
            squares[s].setTexture(grey_img);
            s++;
        }
    }

    player1 = Player(0, 0);
    player1.setTexture(red_img);

    player2 = Player(448, 0);
    player2.setTexture(yellow_img);
}

void TwoPlayers::unload() {
    GRRLIB_FreeTexture(red_img);
    GRRLIB_FreeTexture(grey_img);
    GRRLIB_FreeTexture(yellow_img);
    GRRLIB_FreeTTF(font);
}