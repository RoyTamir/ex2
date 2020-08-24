#pragma once

#include <cstdint>
#include <string>

using std::string;
using std::uint32_t;
using std::uint16_t;

class DIBHeaderParser {

	string _str;
	uint32_t _bitmapArrayWidth;
	uint32_t _bitmapArrayHeight;
	uint16_t _bitsPerPixel;
	uint32_t _numColorsInColorPalette;


public:
	/**
	 * @brief Construct a new DIBHeaderParser object.
	 * 
	 * @param str the string from the BMP file.
	 */
	DIBHeaderParser(const string& str);
	
	/**
	 * @brief Get the Str object.
	 * 
	 * @return const string& the string from the BMP file.
	 */
	const string& getStr() const;

	/**
	 * @brief Get the Bit Array Width object.
	 * 
	 * @return uint32_t The bitmap width in pixel.
	 */
	uint32_t getBitArrayWidth() const;

	/**
	 * @brief Get the Bit Array Height object.
	 * 
	 * @return uint32_t The bitmap height in pixel.
	 */
	uint32_t getBitArrayHeight() const;

	/**
	 * @brief Get the Bits Per Pixel object.
	 * 
	 * @return uint32_t Number of bits per pixel (We assume this number to be
	 * either 8 or 24).
	 */
	uint32_t getBitsPerPixel() const;

	/**
	 * @brief Get the Num Colors In Color Palette object.
	 * 
	 * @return uint32_t Number of colors in the color palette.
	 */
	uint32_t getNumColorsInColorPalette() const;
};
