//
// Wii
// Square
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Square.hpp"
#include "Color.hpp"

void Square::draw() {
    GRRLIB_DrawImg(x, y, sprite, 0, 1, 1, Color::getWhite());
}

void Square::draw(float d) {
    GRRLIB_DrawImg(x, y, sprite, d, 1, 1, Color::getWhite());
}