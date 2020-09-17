#pragma once

#include "BMPHeaderParser.hpp"
#include "DIBHeaderParser.hpp"
#include "ColorTableParser.hpp"
#include "BMArrayParserToMatrixes.hpp"
#include "BMArrayWithColorPattle.hpp"
#include "BMPParser.hpp"
#include "Color.hpp"

#include <memory>
#include <cstdint>
#include <iostream>
#include <string>

namespace BMPClasses {
class BMPParser {

	std::string m_str;
	std::shared_ptr<BMPHeaderParser> m_BHparser = nullptr;
	std::shared_ptr<DIBHeaderParser> m_DIBparser = nullptr;
	std::shared_ptr<ColorTableParser> m_CTparser = nullptr;//for 8 bits per pixel
	std::shared_ptr<BMArrayParserToMatrixes> m_BMAparser = nullptr;//for 24 bits per pixel
	std::shared_ptr<BMArrayWithColorPattle> m_BMAColorparser = nullptr;//for 8 bits per pixel

public:
	/**
	 * @brief Construct a new BMPParser object.
	 * 
	 * @param str the string that represent the image.
	 */
	BMPParser(std::string str);

	/**
	 * @brief Returns the string that represent the image.
	 * 
	 * @return const std::string the string that represent the image.
	 */
	std::string getBMP() const;

	/**
	 * @brief convert the image pixels to gray.
	 * 
	 */
	void imageToGray();

	/**
	 * @brief rotatting the image color.
	 * 
	 */
	void rotateImage();
};
}
