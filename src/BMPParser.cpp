#include "BMPParser.hpp"

#include <string>
using std::string;

BMPParser::BMPParser(const string& str) {
	this->_str = str;
	this->_BHparser = new BMPHeaderParser(str.substr(0, 14));
	this->_DIBparser = new DIBHeaderParser(str.substr(14, 40));

	if (this->_DIBparser->getBitsPerPixel() == 24) { //if 24 bits per pixel
		uint32_t arrayOffset = this->_BHparser->getOffset();
		this->_BMAparser = new BMArrayParserToMatrixes(str.substr(arrayOffset, str.length() - arrayOffset),
		 this->_DIBparser->getBitArrayWidth(), this->_DIBparser->getBitArrayHeight());
	} else if (this->_DIBparser->getBitsPerPixel() == 8) {//if 8 bits per pixel

	} else { 
		cout<<"Error: BMPParser Constructor: the bits per pixel arn't 8 or 24"<<endl;
	}
}

const string& BMPParser::getBMP() const {
	return this->_str;
}

void BMPParser::imageToGray(){
	if (this->_DIBparser->getBitsPerPixel() == 24) { //if 24 bits per pixel
	this->_BMAparser->changeToGray();

	uint32_t arrayOffset = this->_BHparser->getOffset();
	this->_str.replace(arrayOffset, this->_str.length() - arrayOffset, this->_BMAparser->getStr());
	} else if (this->_DIBparser->getBitsPerPixel() == 8) {//if 8 bits per pixel

	} else { 
		cout<<"Error: BMPParser Constructor: the bits per pixel arn't 8 or 24"<<endl;
	}
}