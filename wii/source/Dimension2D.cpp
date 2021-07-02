//
// Wii
// Dimension2D.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Dimension2D.hpp"

Dimension2D::Dimension2D() : w(0), h(0) {}
Dimension2D::Dimension2D(int w, int h) : w(w), h(h) {}

void Dimension2D::setDimension(Dimension2D d) {
	this->w = d.getWidth();
	this->h = d.getHeight();
}

Dimension2D Dimension2D::getSize() {
	return Dimension2D(this->getWidth(), this->getHeight());
}
