#include "DIBHeaderParser.hpp"

using namespace BMPClasses;
using std::string;
using std::uint32_t;
using std::uint16_t;

DIBHeaderParser::DIBHeaderParser(string str) {
	this->m_str = std::move(str);

	uint32_t* bitmapArrayWidth = const_cast<uint32_t*>(reinterpret_cast<const uint32_t*>(str.substr(BMP_ARRAY_WIDTH_LOCATION,
			 BYTES_FOR_OTHER_FIELDS).data()));

	uint32_t* bitmapArrayHeight = const_cast<uint32_t*>(reinterpret_cast<const uint32_t*>(str.substr(BMP_ARRAY_HEIGHT_LOCATION,
			BYTES_FOR_OTHER_FIELDS).data()));

	uint16_t* bitsPerPixel = const_cast<uint16_t*>(reinterpret_cast<const uint16_t*>(str.substr(BITS_PER_PIXEL_LOCATION,
			BYTES_PER_PIXEL).data()));

	uint32_t* numColorsInColorPalette = const_cast<uint32_t*>(reinterpret_cast<const uint32_t*>(str.substr(NUM_COLORS_IN_COLOR_PALETTE_LOCATION,
			BYTES_FOR_OTHER_FIELDS).data()));

	this->m_bitmapArrayWidth = *bitmapArrayWidth;
	this->m_bitmapArrayHeight = *bitmapArrayHeight;
	this->m_bitsPerPixel = *bitsPerPixel;
	this->m_numColorsInColorPalette = *numColorsInColorPalette;
}

string DIBHeaderParser::getStr() const {
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
	string height = this->m_str.substr(BMP_ARRAY_HEIGHT_LOCATION,
			BYTES_FOR_OTHER_FIELDS);
	string width = this->m_str.substr(BMP_ARRAY_WIDTH_LOCATION,
			 BYTES_FOR_OTHER_FIELDS);

	this->m_str.replace(BMP_ARRAY_HEIGHT_LOCATION,
			BYTES_FOR_OTHER_FIELDS, width);
	
	this->m_str.replace(BMP_ARRAY_WIDTH_LOCATION,
			 BYTES_FOR_OTHER_FIELDS, height);
}