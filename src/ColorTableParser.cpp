#include "ColorTableParser.hpp"

using namespace BMPClasses;
using std::string;
using std::vector;
using std::uint32_t;
using std::uint16_t;

ColorTableParser::ColorTableParser(string str) {
	this->m_str = std::move(str);
	for (uint32_t i = 0; i < this->m_str.length(); i += BITES_PER_COLOR) {
		uint16_t* r = const_cast<uint16_t*>(reinterpret_cast<const uint16_t*>(this->m_str.substr(i, BIT_SIZE).data()));

		uint16_t* g = const_cast<uint16_t*>(reinterpret_cast<const uint16_t*>(this->m_str.substr(i + 1 * BIT_SIZE, BIT_SIZE).data()));

		uint16_t* b = const_cast<uint16_t*>(reinterpret_cast<const uint16_t*>(this->m_str.substr(i + 2 * BIT_SIZE, BIT_SIZE).data()));

		this->m_colors.push_back(std::make_shared<Color>(*r, *g, *b));
	}
}

string ColorTableParser::getStr() const {
	return this->m_str;
}

uint32_t ColorTableParser::getColorCount() const {
	return this->m_colors.size();
}

Color& ColorTableParser::getColor(uint32_t n) const {
	return *(this->m_colors.at(n));
}

vector<std::shared_ptr<Color>> ColorTableParser::getColors() const {
	return this->m_colors;
}

void ColorTableParser::changeColorToGray(uint32_t colorIndex) {
	this->m_colors.at(colorIndex)->toGray();
	uint16_t color;
    char* c;
   	string s;

 	//then because we did "this->_colors.at(colorIndex)->toGray()"
	// R = 0 G = 0 B = 0 so it's black and no need change
	if(this->m_colors.at(colorIndex)->getR() != 0){
		//each color takes 4 bits that the first 3 are: R G B.
		color = static_cast<uint16_t>(this->m_colors.at(colorIndex)->getR());
    	c = reinterpret_cast<char*>(&color);
   		s = c;
		this->m_str.replace(colorIndex * BITES_PER_COLOR, BIT_SIZE, s); //colorIndex*4 the loction the bit starts from.
		color = static_cast<uint16_t>(this->m_colors.at(colorIndex)->getG());
    	c = reinterpret_cast<char*>(&color);
   		s = c;
		this->m_str.replace(colorIndex * BITES_PER_COLOR + BIT_SIZE, BIT_SIZE, s); //colorIndex*4 the loction the bit starts from.

		color = static_cast<uint16_t>(this->m_colors.at(colorIndex)->getB());
    	c = reinterpret_cast<char*>(&color);
   		s = c;
		this->m_str.replace(colorIndex * BITES_PER_COLOR + 2 * BIT_SIZE, BIT_SIZE, s); //colorIndex*4 the loction the bit starts from.
	}
}