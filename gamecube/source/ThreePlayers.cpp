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

    timer = 0;
    while(timer < 1000) {
        input();
        move(); 
        usleep(10 * 100); 
        collision();
        render();
        timer++;
    }

    timer = 0;
    short res = result();
    while(timer < 60) {
        GRRLIB_FillScreen(Color::getBlack()); 
        if (res == 1) {
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 60, Canvas::screenHeight/2 -20, font, "Player 1 Win", 32, Color::getRed());
        } else if (res == 2) {
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 60, Canvas::screenHeight/2 -20, font, "Player 2 Win", 32, Color::getYellow());
        } else if (res == 3) {
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 60, Canvas::screenHeight/2 -20, font, "Player 3 Win", 32, Color::getBlue());
        } else {
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 60, Canvas::screenHeight/2 -20, font, "DRAW", 32, Color::getGray());
        }

        GRRLIB_Render();
        timer++;
    }
    return false;
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

    for (short i = 0; i < NUMBER_SQRT; i++) {
        if (Collider2D::collide(player1.getBounds(), squares[i].getBounds())) {
            squares[i].setTexture(red_img);
            squares[i].setColor((int)Square::Red);
        }

        if (Collider2D::collide(player2.getBounds(), squares[i].getBounds())) {
            squares[i].setTexture(yellow_img);
            squares[i].setColor((int)Square::Yellow);
        }
        
        if (Collider2D::collide(player3.getBounds(), squares[i].getBounds())) {
            squares[i].setTexture(blue_img);
            squares[i].setColor((int)Square::Blue);
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

    for (short i = 0; i < NUMBER_SQRT; i++) {
        if (!squares[i].isDestroyed()) {
            squares[i].draw();
        }
    }
    player1.draw();
    player2.draw();
    player3.draw();

    GRRLIB_Render();           
}

void ThreePlayers::movePlayer1() {
    if (p1dy > 126) {
        if (player1.getY() > 32) {
            player1.moveY(-2);
        } 
        return;
    } 

    if (p1dy < -126) {
        if (player1.getY() < 464) {
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
        if (player2.getY() > 32) {
            player2.moveY(-2);
        } 
        return;
    } 

    if (p2dy < -126) {
        if (player2.getY() < 464) {
            player2.moveY(2);
        }
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
        if (player3.getY() > 32) {
            player3.moveY(-2);
        } 
        return;
    } 

    if (p3dy < -126) {
        if (player3.getY() < 464) {
            player3.moveY(2);
        }
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

    short s = 0;
    for (short l = 0; l < 14; l++) {
        for (short c = 0; c < 14; c++) {
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

short ThreePlayers::result() {
    short p1 = 0;
    short p2 = 0;
    short p3 = 0;
    for (short i = 0; i < NUMBER_SQRT; i++) {
        if (squares[i].getColor() == 1) {
            p1++;
        }

        if (squares[i].getColor() == 2) {
            p2++;
        }

        if (squares[i].getColor() == 3) {
            p3++;
        }
    }

    if (p1 > p2) {
        if (p1 > p3) {
            return 1;
        }
    }
    
    if (p2 > p1) {
        if (p2 > p3) {
            return 2;
        }
    }

    if (p3 > p1) {
        if (p3 > p2) {
            return 3;
        }
    }
  
    return 0;
}