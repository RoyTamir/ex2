#pragma once

#include <cstdint>
#include <string>

#define NUM_BYTES_OF_BITS_PER_PIXEL 2
#define NUM_BYTES_OF_THE_OTHER_FIELDS 4

#define LOCATION_OF_BITMAP_ARRAY_WIDTH 4
#define LOCATION_OF_BITMAP_ARRAY_HEIGHT 8
#define LOCATION_OF__BITS_PER_PIXEL 14
#define LOCATION_OF_NUM_COLORS_IN_COLOR_PALETTE 32

namespace BMPClasses {
class DIBHeaderParser {

	std::string _str;
	std::uint32_t _bitmapArrayWidth;
	std::uint32_t _bitmapArrayHeight;
	std::uint16_t _bitsPerPixel;
	std::uint32_t _numColorsInColorPalette;


public:
	/**
	 * @brief Construct a new DIBHeaderParser object.
	 * 
	 * @param str the string from the BMP file
	 * that refers to DIBheader.
	 */
	DIBHeaderParser(const std::string& str);
	
	/**
	 * @brief Get the Str object.
	 * 
	 * @return const string& the string from the BMP file
	 *  that refers to DIBheader.
	 */
	const std::string& getStr() const;

	/**
	 * @brief Get the Bit Array Width object.
	 * 
	 * @return uint32_t The bitmap width in pixel.
	 */
	std::uint32_t getBitArrayWidth() const;

	/**
	 * @brief Get the Bit Array Height object.
	 * 
	 * @return uint32_t The bitmap height in pixel.
	 */
	std::uint32_t getBitArrayHeight() const;

	/**
	 * @brief Get the Bits Per Pixel object.
	 * 
	 * @return uint32_t Number of bits per pixel (We assume this number to be
	 * either 8 or 24).
	 */
	std::uint32_t getBitsPerPixel() const;

	/**
	 * @brief Get the Num Colors In Color Palette object.
	 * 
	 * @return uint32_t Number of colors in the color palette (0 indicates the default
	 * 2^n, 𝑤ℎ𝑒𝑟𝑒 𝑛 𝑖𝑠 𝑡ℎ𝑒 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜𝑓 𝑏𝑖𝑡𝑠).
	 */
	std::uint32_t getNumColorsInColorPalette() const;

	/**
	 * @brief swiching bitmapArrayHeight and bitmapArrayWidth.
	 * 
	 * @param newHeight the new height.
	 */
	void switchHeightAndWidth();
};
}