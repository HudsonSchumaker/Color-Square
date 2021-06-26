// 
// NGC
// Player
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Player.hpp"
#include "Color.hpp"

void Player::moveX(int dx) {
    this->x += dx;
}

void Player::moveY(int dy) {
    this->y += dy;
}

void Player::move(int dx, int dy) {
    this->x += dx;
    this->y += dy;
}

void Player::setPos(int dx, int dy) {
    this->x = dx;
    this->y = dy;
}

void Player::draw() {
    GRRLIB_DrawImg(x, y, sprite, 0, 1, 1, Color::getWhite());
}

void Player::draw(float d) {
    GRRLIB_DrawImg(x, y, sprite, d, 1, 1, Color::getWhite());
}
