#include "BMPParser.hpp"

#include <string>
using std::string;

BMPParser::BMPParser(string str) {
	this->_str = str;
	this->_BHparser = new BMPHeaderParser(str.substr(0, 14));
	this->_DIBparser = new DIBHeaderParser(str.substr(14, 40));
	this->_CTparser = new ColorTableParser(this->_str.substr(54, this->_BHparser->getOffset()));
	this->_BMAparser = new BMArrayParserToMatrixes(this->_str.substr(this->_BHparser->getOffset(),
										 	 this->_str.size() - (this->_BHparser->getOffset())),
										 	 this->_DIBparser->getBitArrayWidth(), this->_DIBparser->getBitArrayHeight());
}

string BMPParser::getBMP() const {
	return this->_str;
}