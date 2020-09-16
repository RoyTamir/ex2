#include "DIBHeaderParser.hpp"

using namespace BMPClasses;
using std::string;
using std::uint32_t;
using std::uint16_t;

DIBHeaderParser::DIBHeaderParser(const string& str) {
	this->m_str = str;

	uint32_t* bitmapArrayWidth = (uint32_t*) str.substr(LOCATION_OF_BITMAP_ARRAY_WIDTH,
			 NUM_BYTES_OF_THE_OTHER_FIELDS).data();

	uint32_t* bitmapArrayHeight = (uint32_t*) str.substr(LOCATION_OF_BITMAP_ARRAY_HEIGHT,
			NUM_BYTES_OF_THE_OTHER_FIELDS).data();

	uint16_t* bitsPerPixel = (uint16_t*) str.substr(LOCATION_OF__BITS_PER_PIXEL,
			NUM_BYTES_OF_BITS_PER_PIXEL).data();

	uint32_t* numColorsInColorPalette = (uint32_t*) str.substr(LOCATION_OF_NUM_COLORS_IN_COLOR_PALETTE,
			NUM_BYTES_OF_THE_OTHER_FIELDS).data();

	this->m_bitmapArrayWidth = *bitmapArrayWidth;
	this->m_bitmapArrayHeight = *bitmapArrayHeight;
	this->m_bitsPerPixel = *bitsPerPixel;
	this->m_numColorsInColorPalette = *numColorsInColorPalette;
}

const string& DIBHeaderParser::getStr() const {
	return this->m_str;
}

uint32_t DIBHeaderParser::getBitArrayWidth() const {
	return this->m_bitmapArrayWidth;
}

uint32_t DIBHeaderParser::getBitArrayHeight() const {
	return this->m_bitmapArrayHeight;
}

uint32_t DIBHeaderParser::getBitsPerPixel() const {
	return this->m_bitsPerPixel;
}

uint32_t DIBHeaderParser::getNumColorsInColorPalette() const {
	return this->m_numColorsInColorPalette;
}

void DIBHeaderParser::switchHeightAndWidth(){
	string height = this->m_str.substr(LOCATION_OF_BITMAP_ARRAY_HEIGHT,
			NUM_BYTES_OF_THE_OTHER_FIELDS);
	string width = this->m_str.substr(LOCATION_OF_BITMAP_ARRAY_WIDTH,
			 NUM_BYTES_OF_THE_OTHER_FIELDS);

	this->m_str.replace(LOCATION_OF_BITMAP_ARRAY_HEIGHT,
			NUM_BYTES_OF_THE_OTHER_FIELDS, width);
	
	this->m_str.replace(LOCATION_OF_BITMAP_ARRAY_WIDTH,
			 NUM_BYTES_OF_THE_OTHER_FIELDS, height);
}