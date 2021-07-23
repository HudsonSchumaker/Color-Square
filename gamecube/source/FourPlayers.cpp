//
// NGC
// FourPlayers.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "FourPlayers.hpp"
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
#include "green_square_png.h"
#include "green_player_png.h"
#include "font_ttf.h"
#include <unistd.h>

FourPlayers::FourPlayers() {
    load();
}

FourPlayers::~FourPlayers() {
    unload();
}

bool FourPlayers::loop() {

    short timer = 0;
    while(timer < 60) {
        GRRLIB_FillScreen(Color::getBlack()); 
        GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 60, Canvas::screenHeight/2 -20, font, "4 Players", 32, Color::getOrange());
        GRRLIB_Render();
        timer++;
    }

    timer = 0;
    while(timer < 1000) {
        input();
        move(); 
        usleep(10 * 99); 
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
        } else if (res == 4) {
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 60, Canvas::screenHeight/2 -20, font, "Player 4 Win", 32, Color::getGreen());
        } else {
            GRRLIB_PrintfTTF(Canvas::screenWidth/2 - 60, Canvas::screenHeight/2 -20, font, "DRAW", 32, Color::getGray());
        }

        GRRLIB_Render();
        timer++;
    }
    return false;
}

void FourPlayers::input() {
    PAD_ScanPads();
    p1dx = PAD_StickX(0);
    p2dx = PAD_StickX(1);
    p3dx = PAD_StickX(2);
    p4dx = PAD_StickX(3);

    p1dy = PAD_StickY(0);
    p2dy = PAD_StickY(1);
    p3dy = PAD_StickY(2);
    p4dy = PAD_StickY(3);
}

void FourPlayers::move() {
    movePlayer1();
    movePlayer2();
    movePlayer3();
    movePlayer4();
}

void FourPlayers::collision() {

    for (int i = 0; i < NUMBER_SQRT; i++) {
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

        if (Collider2D::collide(player4.getBounds(), squares[i].getBounds())) {
            squares[i].setTexture(green_img);
            squares[i].setColor((int)Square::Green);
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

    if (Collider2D::collide(player1.getBounds(), player4.getBounds())) {
        player1.setPos(104, 40);
        player4.setPos(520, 456);
    }

    if (Collider2D::collide(player2.getBounds(), player3.getBounds())) {
        player2.setPos(520, 40);
        player3.setPos(104, 456);
    }

    if (Collider2D::collide(player2.getBounds(), player4.getBounds())) {
        player2.setPos(520, 40);
        player4.setPos(520, 456);
    }

    if (Collider2D::collide(player3.getBounds(), player4.getBounds())) {
        player3.setPos(104, 456);
        player4.setPos(520, 456);
    }
}

void FourPlayers::render() {
    GRRLIB_FillScreen(Color::getBlack()); 

    for (int i = 0; i < NUMBER_SQRT; i++) {
        if (!squares[i].isDestroyed()) {
            squares[i].draw();
        }
    }
    player1.draw();
    player2.draw();
    player3.draw();
    player4.draw();

    GRRLIB_Render();           
}

void FourPlayers::movePlayer1() {
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

void FourPlayers::movePlayer2() {
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

void FourPlayers::movePlayer3() {
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

void FourPlayers::movePlayer4() {
    if (p4dy > 126) {
        if (player4.getY() > 32) {
            player4.moveY(-2);
        } 
        return;
    } 

    if (p4dy < -126) {
        if (player4.getY() < 464) {
            player4.moveY(2);
        }
        return;
    }

    if (p4dx > 126) {
        if (player4.getX() < 528) {
            player4.moveX(2);
        } 
        return;
    } 

    if (p4dx < -126) {
        if (player4.getX() > 97) {
            player4.moveX(-2);
        } 
    }
}

void FourPlayers::load() {
    grey_img = GRRLIB_LoadTexture(grey_square_png);
    red_img = GRRLIB_LoadTexture(red_square_png);
    yellow_img = GRRLIB_LoadTexture(yellow_square_png);
    blue_img = GRRLIB_LoadTexture(blue_square_png);
    green_img = GRRLIB_LoadTexture(green_square_png);
    
    font = GRRLIB_LoadTTF(font_ttf, font_ttf_size);
    
    player_1 = GRRLIB_LoadTexture(red_player_png);
    player_2 = GRRLIB_LoadTexture(yellow_player_png);
    player_3 = GRRLIB_LoadTexture(blue_player_png);
    player_4 = GRRLIB_LoadTexture(green_player_png);

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

    player4 = Player(520, 456);
    player4.setTexture(player_4);
}

void FourPlayers::unload() {
    GRRLIB_FreeTexture(grey_img);
    GRRLIB_FreeTexture(red_img);
    GRRLIB_FreeTexture(player_1);
    GRRLIB_FreeTexture(yellow_img);
    GRRLIB_FreeTexture(player_2);
    GRRLIB_FreeTexture(blue_img);
    GRRLIB_FreeTexture(player_3);
    GRRLIB_FreeTexture(green_img);
    GRRLIB_FreeTexture(player_4);
    GRRLIB_FreeTTF(font);
}

short FourPlayers::result() {
    short p1 = 0;
    short p2 = 0;
    short p3 = 0;
    short p4 = 0;
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

        if (squares[i].getColor() == 4) {
            p4++;
        }
    }

    if (p1 > p2) {
        if (p1 > p3) {
            if (p1 > p4) {
                return 1;
            }
        }
    }
    
    if (p2 > p1) {
        if (p2 > p3) {
            if (p2 > p4) {
                return 2;
            }
        }
    }

    if (p3 > p1) {
        if (p3 > p2) {
            if (p3 > p4) {
                return 3;
            }
        }
    }

    if (p4 > p1) {
        if (p4 > p2) {
            if (p4 > p3) {
                return 4;
            }
        }
    }
   
    return 0;
}
