#pragma once

#include "BMPHeaderParser.hpp"
#include "DIBHeaderParser.hpp"
#include "ColorTableParser.hpp"
#include "BMArrayParserToMatrixes.hpp"
#include "BMArrayWithColorPattle.hpp"
#include "BMPParser.hpp"
#include "Color.hpp"

#include <cstdint>
#include <iostream>
#include <string>

namespace BMPClasses {
class BMPParser {

	std::string _str;
	BMPHeaderParser* _BHparser = nullptr;
	DIBHeaderParser* _DIBparser = nullptr;
	ColorTableParser* _CTparser = nullptr;//for 8 bits per pixel
	BMArrayParserToMatrixes* _BMAparser = nullptr;//for 24 bits per pixel
	BMArrayWithColorPattle* _BMAColorparser = nullptr;//for 8 bits per pixel

public:
	BMPParser(const std::string& str);
	const std::string& getBMP() const;
	void imageToGray();
	void rotateImage();
};
}
