//
// Wii
// Collider2D.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
// 

#pragma once
#include "Point2D.hpp"
#include "Dimension2D.hpp"

class Collider2D final {

    private:
        int x, y, w, h;

    public:
        Collider2D();
        Collider2D(int w, int h);
        Collider2D(int x, int y, int w, int h);
        Collider2D(Point2D p);
        Collider2D(Dimension2D d);
        Collider2D(Point2D p, Dimension2D d);

        static bool collide(const Collider2D& a, const Collider2D& b);

        Collider2D getBounds();
        Point2D getLocation();
        Dimension2D getSize();

        bool inside(int X, int Y);
        bool contains(Point2D p);
	bool contains(Collider2D c);
	bool contains(int x, int y);
	bool contains(int X, int Y, int W, int H);
	bool intersects(Collider2D c);

        void setX(int x) { this->x = x; };
	int getX() const { return x; };

	void setY(int y) { this->y = y; };
	int getY() const { return y; };

	void setWidth(int w) { this->w = w; };
		int getWidth() const { return w; };

		void setHeight(int h) { this->h = h; };
		int getHeight() const { return h; };
};
