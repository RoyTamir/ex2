#pragma once

#include "ColorTableParser.hpp"
#include "Color.cpp"

#include <string>
#include <vector>
using std::string;
using std::vector;

ColorTableParser::ColorTableParser(string str) {
	this->_str = str;
	for (string::iterator it = this->_str.begin(); it != this->_str.end(); it++) {
		this->_colors.push_back(*(new Color(*(it++), *(it++), *(it++))));
	}
}

string ColorTableParser::getStr() const {
	return this->_str;
}

int ColorTableParser::getColorCount() const {
	return this->_colors.size();
}

Color ColorTableParser::getColor(int n) const {
	return this->_colors[n];
}

vector<Color> ColorTableParser::getColors() const {
	return this->_colors;
}
