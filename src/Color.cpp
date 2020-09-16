#include "Color.hpp"

using namespace BMPClasses;
using std::uint16_t;

Color::Color(uint16_t R, uint16_t G, uint16_t B) {
	this->m_R = R;
	this->m_G = G;
	this->m_B = B;
}

uint16_t Color::getR() const {
	return this->m_R;
}

uint16_t Color::getG() const {
	return this->m_G;
}

uint16_t Color::getB() const {
	return this->m_B;
}

void Color::toGray() {
	uint16_t gray = static_cast<uint16_t>(0.2126 * this->m_R + 0.7152 * this->m_G + 0.0722 * this->m_B);

	this->m_R = gray;
	this->m_G = gray;
	this->m_B = gray;
}
