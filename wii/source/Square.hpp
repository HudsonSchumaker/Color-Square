//
// Wii
// Square
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include "Sprite.hpp"

class Square final: public Sprite {
    private:
        bool destroyed;
        int color;

    public:
        enum SquareColor {
            Gray,
            Red,
            Yellow,
            Blue,
            Green
        };

        Square() : Sprite(0, 0), destroyed(false) {};
        Square(int x, int y) : Sprite(x, y), destroyed(false) {};
        Square(int x, int y, int w, int h) : Sprite(x, y, w, h), destroyed(false) {};
        Square(int x, int y, int w, int h, bool d) : Sprite(x, y, w, h), destroyed(d) {};
    
        void draw() override;
        void draw(float d);

        bool isDestroyed() const { return destroyed; };
        void setDestroyed(bool d) { this->destroyed = d; };

        int getColor() const  { return color; };
        void setColor(int c) { this->color = c; };
};