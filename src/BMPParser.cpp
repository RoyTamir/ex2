#include "BMPParser.hpp"

using namespace BMPClasses;
using std::string;
using std::uint32_t;

BMPParser::BMPParser(const string& str) {
	this->m_str = str;
	this->m_BHparser = std::make_shared<BMPHeaderParser>(str.substr(0, 14));
	this->m_DIBparser = std::make_shared<DIBHeaderParser>(str.substr(14, 40));

	uint32_t arrayOffset = this->m_BHparser->getOffset();
	if (this->m_DIBparser->getBitsPerPixel() == 24) { //if 24 bits per pixel
		
		this->m_BMAparser = std::make_shared<BMArrayParserToMatrixes>(str.substr(arrayOffset, str.length() - arrayOffset),
		this->m_DIBparser->getBitArrayWidth(), this->m_DIBparser->getBitArrayHeight());

	} else if (this->m_DIBparser->getBitsPerPixel() == 8) {//if 8 bits per pixel
		this->m_CTparser = std::make_shared<ColorTableParser>(str.substr(54, 1024));//2^8*4=1024

		this->m_BMAColorparser = std::make_shared<BMArrayWithColorPattle>(str.substr(arrayOffset, str.length() - arrayOffset),
		this->m_DIBparser->getBitArrayWidth(), this->m_DIBparser->getBitArrayHeight(), this->m_CTparser);

	} else { 
		throw std::runtime_error("Error: BMPParser Constructor: the bits per pixel arn't 8 or 24");
	}
}

const string& BMPParser::getBMP() const {
	return this->m_str;
}

void BMPParser::imageToGray(){
	
	uint32_t arrayOffset = this->m_BHparser->getOffset();
	if (this->m_DIBparser->getBitsPerPixel() == 24) { //if 24 bits per pixel
		this->m_BMAparser->changeToGray();

		this->m_str.replace(arrayOffset, this->m_str.length() - arrayOffset, this->m_BMAparser->getStr());
	} else if (this->m_DIBparser->getBitsPerPixel() == 8) {//if 8 bits per pixel
		this->m_BMAColorparser->changeToGray();

		this->m_str.replace(54, 1024, this->m_CTparser->getStr());
	} else { 
		throw std::runtime_error("Error: BMPParser imageToGray: the bits per pixel arn't 8 or 24");
	}
}

void BMPParser::rotateImage() {
	uint32_t arrayOffset = this->m_BHparser->getOffset();
	this->m_DIBparser->switchHeightAndWidth();
	this->m_str.replace(14, 40, this->m_DIBparser->getStr());
	if (this->m_DIBparser->getBitsPerPixel() == 24) { //if 24 bits per pixel
		this->m_BMAparser->rotate();

		this->m_str.replace(arrayOffset, this->m_str.length() - arrayOffset, this->m_BMAparser->getStr());
	} else if (this->m_DIBparser->getBitsPerPixel() == 8) {//if 8 bits per pixel
		this->m_BMAColorparser->rotate();

		this->m_str.replace(arrayOffset, this->m_str.length() - arrayOffset, this->m_BMAColorparser->getStr());
	} else {
		throw std::runtime_error("Error: BMPParser rotateImage: the bits per pixel arn't 8 or 24");
	}
}