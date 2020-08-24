#include "DIBHeaderParser.hpp"

DIBHeaderParser::DIBHeaderParser(const string& str) {
	this->_str = str;

	uint32_t* bitmapArrayWidth = (uint32_t*) str.substr(4,
			4 + 4- 1).data();

	uint32_t* bitmapArrayHeight = (uint32_t*) str.substr(8,
			8 + 4- 1).data();

	uint16_t* bitsPerPixel = (uint16_t*) str.substr(14,
			14 + 2- 1).data();

	uint32_t* numColorsInColorPalette = (uint32_t*) str.substr(32,
			32 + 4- 1).data();

	this->_bitmapArrayWidth = *bitmapArrayWidth;
	this->_bitmapArrayHeight = *bitmapArrayHeight;
	this->_bitsPerPixel = *bitsPerPixel;
	this->_numColorsInColorPalette = *numColorsInColorPalette;
	// this->_bitsPerPixel = str[10];
	// int width = 0, height = 0, horRes = 0, verRes = 0, power = 1;
    // for (int i = 0; i < 4; i++) {
    //     width += str[4 + i] * power;
    //     height += str[8 + i] * power;
	// 	horRes += str[24 + i] * power;
	// 	verRes += str[28 + i] * power;
    //     power *= 256;
    // }
    // this->_bitArrayWidth = width;
    // this->_bitArrayHeight = height;
	// this->_horizontalResolution = horRes;
	// this->_verticalResolution = verRes;
}

const string& DIBHeaderParser::getStr() const {
	return this->_str;
}

uint32_t DIBHeaderParser::getBitArrayWidth() const {
	return this->_bitmapArrayWidth;
}

uint32_t DIBHeaderParser::getBitArrayHeight() const {
	return this->_bitmapArrayHeight;
}

uint32_t DIBHeaderParser::getBitsPerPixel() const {
	return this->_bitsPerPixel;
}

uint32_t DIBHeaderParser::getNumColorsInColorPalette() const {
	return this->_numColorsInColorPalette;
}