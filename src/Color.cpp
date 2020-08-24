#include "Color.hpp"

Color::Color(int R, int G, int B) {
	this->_R = R;
	this->_G = G;
	this->_B = B;
}

int Color::getR() const {
	return this->_R;
}

int Color::getG() const {
	return this->_G;
}

int Color::getB() const {
	return this->_B;
}

Color Color::toGray() const {
	int gray = (int) (0.2126 * this->_R + 0.7152 * this->_G + 0.0722 * this->_B);
	return *(new Color(gray, gray, gray));
}
