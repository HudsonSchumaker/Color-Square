//
// NS
// Dimension2D
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once

class Dimension2D final {
	private:
		int w, h;

	public:
		Dimension2D();
		Dimension2D(int w, int h);

		void setDimension(Dimension2D d);
		Dimension2D getSize();

		void setWidth(int w) { this->w = w; };
		int getWidth() const { return w; };

		void setHeight(int h) { this->h = h; };
		int getHeight() const { return h; };
};
