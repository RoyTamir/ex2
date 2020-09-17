#pragma once

#include <cstdint>
#include <string>

namespace BMPClasses {
class DIBHeaderParser {

	std::string m_str;
	std::uint32_t m_bitmapArrayWidth;
	std::uint32_t m_bitmapArrayHeight;
	std::uint16_t m_bitsPerPixel;
	std::uint32_t m_numColorsInColorPalette;


public:

	static constexpr int BYTES_PER_PIXEL = 2;
	static constexpr int BYTES_FOR_OTHER_FIELDS = 4;

	static constexpr int BMP_ARRAY_WIDTH_LOCATION = 4;
	static constexpr int BMP_ARRAY_HEIGHT_LOCATION = 8;
	static constexpr int BITS_PER_PIXEL_LOCATION = 14;
	static constexpr int NUM_COLORS_IN_COLOR_PALETTE_LOCATION = 32;

	/**
	 * @brief Construct a new DIBHeaderParser object.
	 * 
	 * @param str the string from the BMP file
	 * that refers to DIBheader.
	 */
	DIBHeaderParser(std::string str);
	
	/**
	 * @brief Get the Str object.
	 * 
	 * @return string the string from the BMP file
	 *  that refers to DIBheader.
	 */
	std::string getStr() const;

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