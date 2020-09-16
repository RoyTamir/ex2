#include "BMPParser.hpp"

using namespace BMPClasses;
using std::string;
using std::cout;
using std::endl;
using std::uint32_t;

BMPParser::BMPParser(const string& str) {
	this->m_str = str;
	this->m_BHparser = new BMPHeaderParser(str.substr(0, 14));
	this->m_DIBparser = new DIBHeaderParser(str.substr(14, 40));

	uint32_t arrayOffset = this->m_BHparser->getOffset();
	if (this->m_DIBparser->getBitsPerPixel() == 24) { //if 24 bits per pixel
		
		this->m_BMAparser = new BMArrayParserToMatrixes(str.substr(arrayOffset, str.length() - arrayOffset),
		this->m_DIBparser->getBitArrayWidth(), this->m_DIBparser->getBitArrayHeight());

	} else if (this->m_DIBparser->getBitsPerPixel() == 8) {//if 8 bits per pixel
		this->m_CTparser = new ColorTableParser(str.substr(54, 1024));//2^8*4=1024

		this->m_BMAColorparser = new BMArrayWithColorPattle(str.substr(arrayOffset, str.length() - arrayOffset),
		this->m_DIBparser->getBitArrayWidth(), this->m_DIBparser->getBitArrayHeight(), this->m_CTparser);

	} else { 
		cout<<"Error: BMPParser Constructor: the bits per pixel arn't 8 or 24"<<endl;
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
		cout<<"Error: BMPParser Constructor: the bits per pixel arn't 8 or 24"<<endl;
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
		cout<<"Error: BMPParser Constructor: the bits per pixel arn't 8 or 24"<<endl;
	}
}