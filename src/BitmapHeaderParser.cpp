#pragma once

#include <string>
using std::string;

#include "BitmapHeaderParser.hpp"

BitmapHeaderParser::BitmapHeaderParser(string str) {
	this->_str = str;
	int size = 0, offset = 0, power = 1;
	for (int i = 0; i < 4; i++) {
		size += str[2 + i] * power;
		offset += str[10 + i] * power;
		power *= 256;
	}
	this->_size = size;
	this->_offset = offset;
}

string BitmapHeaderParser::getStr() const {
	return this->_str;
}

int BitmapHeaderParser::getSize() const {
	return this->_size;
}

int BitmapHeaderParser::getOffset() const {
	return this->_offset;
}
