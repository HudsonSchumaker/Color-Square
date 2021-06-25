//
// NGC
// ThreePlayers
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "ThreePlayers.hpp"
#include "Color.hpp"
#include "Point2D.hpp"
#include "Collider2D.hpp"
#include <mp3player.h>

#include "grey_square_png.h"
#include "red_square_png.h"
#include "red_player_png.h"
#include "yellow_square_png.h"
#include "yellow_player_png.h"
#include "blue_square_png.h"
#include "blue_player_png.h"
#include "beep_mp3.h"
#include "font_ttf.h"
#include <unistd.h>

ThreePlayers::ThreePlayers() {
    load();
}

ThreePlayers::~ThreePlayers() {
    unload();
}

bool ThreePlayers::loop() {

    short timer = 0;
    while(timer < 60) {
        GRRLIB_FillScreen(Color::getBlack()); 
        GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 60, Canvas::screenHeight/2 -20, font, "3 Players", 32, Color::getOrange());
        GRRLIB_Render();
        timer++;
    }

    while(!levelOver && !levelWon) {
          
        input();
        move(); 
        usleep(10 * 100); 
        collision();
        render();
    }
    return levelWon;
}

void ThreePlayers::input() {
    PAD_ScanPads();
    p1dx = PAD_StickX(0);
    p2dx = PAD_StickX(1);
    p3dx = PAD_StickX(2);

    p1dy = PAD_StickY(0);
    p2dy = PAD_StickY(1);
    p3dy = PAD_StickY(2);
}

void ThreePlayers::move() {
    movePlayer1();
    movePlayer2();
    movePlayer3();
}

void ThreePlayers::collision() {

    for (int i = 0; i < NUMBER_SQRT; i++) {
        if (Collider2D::collide(player1.getBounds(), squares[i].getBounds())) {
            squares[i].setTexture(red_img);
        }

        if (Collider2D::collide(player2.getBounds(), squares[i].getBounds())) {
            squares[i].setTexture(yellow_img);
        }
        
        if (Collider2D::collide(player3.getBounds(), squares[i].getBounds())) {
            squares[i].setTexture(blue_img);
        }
    }

    if (Collider2D::collide(player1.getBounds(), player2.getBounds())) {
        player1.setPos(104, 40);
        player2.setPos(520, 40);
    }

    if (Collider2D::collide(player1.getBounds(), player3.getBounds())) {
        player1.setPos(104, 40);
        player3.setPos(104, 456);
    }

    if (Collider2D::collide(player2.getBounds(), player3.getBounds())) {
        player2.setPos(520, 40);
        player3.setPos(104, 456);
    }
}

void ThreePlayers::render() {
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
    player3.draw();

    GRRLIB_Render();           
}

void ThreePlayers::movePlayer1() {
    if (p1dy > 126) {
        if (player1.getY < 34) {
            player1.moveY(-2);
        } 
        return;
    } 

    if (p1dy < -126) {
        if (player1.getY < 462) {
            player1.moveY(2);
        }
        return;
    }

    if (p1dx > 126) {
        if (player1.getX() < 528) {
            player1.moveX(2);
        } 
        return;
    } 

    if (p1dx < -126) {
        if (player1.getX() > 97) {
            player1.moveX(-2);
        } 
    }
}

void ThreePlayers::movePlayer2() {
    if (p2dy > 126) {
        player2.moveY(-2);
        return;
    } 

    if (p2dy < -126) {
        player2.moveY(2);
        return;
    }

    if (p2dx > 126) {
        if (player2.getX() < 528) {
            player2.moveX(2);
        } 
        return;
    } 

    if (p2dx < -126) {
        if (player2.getX() > 97) {
            player2.moveX(-2);
        } 
    }
}

void ThreePlayers::movePlayer3() {
    if (p3dy > 126) {
        player3.moveY(-2);
        return;
    } 

    if (p3dy < -126) {
        player3.moveY(2);
        return;
    }

    if (p3dx > 126) {
        if (player3.getX() < 528) {
            player3.moveX(2);
        } 
        return;
    } 

    if (p3dx < -126) {
        if (player3.getX() > 97) {
            player3.moveX(-2);
        } 
    }
}

void ThreePlayers::load() {
    grey_img = GRRLIB_LoadTexture(grey_square_png);
    red_img = GRRLIB_LoadTexture(red_square_png);
    yellow_img = GRRLIB_LoadTexture(yellow_square_png);
    blue_img = GRRLIB_LoadTexture(blue_square_png);
    
    font = GRRLIB_LoadTTF(font_ttf, font_ttf_size);
    
    player_1 = GRRLIB_LoadTexture(red_player_png);
    player_2 = GRRLIB_LoadTexture(yellow_player_png);
    player_3 = GRRLIB_LoadTexture(blue_player_png);

    int s = 0;
    for (int l = 0; l < 14; l++) {
        for (int c = 0; c < 14; c++) {
            squares[s] = Square(c * grey_img->w + 96, l * grey_img->h + 32);
            squares[s].setTexture(grey_img);
            s++;
        }
    }

    player1 = Player(104, 40);
    player1.setTexture(player_1);

    player2 = Player(520, 40);
    player2.setTexture(player_2);

    player3 = Player(104, 456);
    player3.setTexture(player_3);
}

void ThreePlayers::unload() {
    GRRLIB_FreeTexture(grey_img);
    GRRLIB_FreeTexture(red_img);
    GRRLIB_FreeTexture(player_1);
    GRRLIB_FreeTexture(yellow_img);
    GRRLIB_FreeTexture(player_2);
    GRRLIB_FreeTexture(blue_img);
    GRRLIB_FreeTexture(player_3);
    GRRLIB_FreeTTF(font);
}