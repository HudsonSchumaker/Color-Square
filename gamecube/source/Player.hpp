// 
// NGC
// Player
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include "Sprite.hpp"

class Player final: public Sprite {
    private:
        bool destroyed;

    public:
        Player() : Sprite(0, 0), destroyed(false) {};
        Player(int x, int y) : Sprite(x, y), destroyed(false) {};
        Player(int x, int y, int w, int h) : Sprite(x, y, w, h), destroyed(false) {};
        Player(int x, int y, int w, int h, bool d) : Sprite(x, y, w, h), destroyed(d) {};
    
        void moveX(int dx);
        void moveY(int dy);
        void move(int dx, int dy);
        void draw() override;
        void draw(float d);

        bool isDestroyed() const { return destroyed; };
        void setDestroyed(bool d) { this->destroyed = d; };
};