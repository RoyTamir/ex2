#pragma once

#include "Color.hpp"

#include <memory>
#include <cstdint>
#include <string>
#include <vector>

namespace BMPClasses {
class ColorTableParser {

	std::string m_str;
	std::vector<std::shared_ptr<Color>> m_colors;

public:
	/**
	 * @brief Construct a new Color Table Parser object.
	 * 
	 * @param str the string from the BMP file
	 *  that refers to Color Palette.
	 */
	ColorTableParser(const std::string& str);

	/**
	 * @brief Get the Str object.
	 * 
	 * @return const string& the string from the BMP file
	 *  that refers to Color Palette.
	 */
	const std::string& getStr() const;

	/**
	 * @brief Get the Color Count object.
	 * 
	 * @return uint32_t the size of the Color Palette
	 *  (num of colors).
	 */
	std::uint32_t getColorCount() const;

	/**
	 * @brief Get the Color object.
	 * 
	 * @param n the index of the color in the vector<Color>. 
	 * @return Color the color in the n location.
	 */
	Color& getColor(std::uint32_t n) const;

	/**
	 * @brief Get the Colors object.
	 * 
	 * @return vector<Color> the vector that represents the
	 * Color Palette.
	 */
	std::vector<std::shared_ptr<Color>> getColors() const;

	/**
	 * @brief changing the specific color to gray.
	 * 
	 * @param n the index of the color in the vector<Color>. 
	 */
	void changeColorToGray(std::uint32_t n);
};
}