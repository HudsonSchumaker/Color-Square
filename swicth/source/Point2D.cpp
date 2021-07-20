//
// NS
// Point.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Point2D.hpp"

Point2D::Point2D() : x(0), y(0) {}
Point2D::Point2D(int x, int y) : x(x), y(y) {}

void Point2D::move(int x, int y) {
    this->x = x;
    this->y = y;
}

void Point2D::translate(int d) {
	this->x += d;
	this->y += d;
}

void Point2D::translate(int dx, int dy) {
    this->x += dx;
    this->y += dy;
}
