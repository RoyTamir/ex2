#include "ColorTableParser.hpp"

ColorTableParser::ColorTableParser(const string& str) {
	this->_str = str;
	for (uint32_t i = 0; i < str.length(); ++i) {
		uint16_t* r = (uint16_t*) str.substr(i, 1).data();
		++i;
		uint16_t* g = (uint16_t*) str.substr(i, 1).data();
		++i;
		uint16_t* b = (uint16_t*) str.substr(i, 1).data();
		++i;
		this->_colors.push_back(Color(*r, *g, *b));
	}
}

const string& ColorTableParser::getStr() const {
	return this->_str;
}

uint32_t ColorTableParser::getColorCount() const {
	return this->_colors.size();
}

Color ColorTableParser::getColor(uint32_t n) const {
	return this->_colors[n];
}

vector<Color> ColorTableParser::getColors() const {
	return this->_colors;
}
