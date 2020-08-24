#pragma once

#include <cstdint>
#include <string>

using std::string;
using std::uint32_t;

class DIBHeaderParser {

	string _str;
	uint32_t _bitmapArrayWidth;
	uint32_t _bitmapArrayHeight;
	uint32_t _bitsPerPixel;
	uint32_t _numColorsInColorPalette;


public:
	DIBHeaderParser(string str);
	string getStr() const;
	uint32_t getBitArrayWidth() const;
	uint32_t getBitArrayHeight() const;
	uint32_t getBitsPerPixel() const;
	uint32_t getNumColorsInColorPalette() const;
};
