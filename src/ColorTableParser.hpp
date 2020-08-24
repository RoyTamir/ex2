#pragma once

#include "Color.hpp"

#include <string>
#include <vector>
using std::string;
using std::vector;

class ColorTableParser {

	string _str;
	vector<Color> _colors;

public:
	ColorTableParser(string str);
	string getStr() const;
	int getColorCount() const;
	Color getColor(int n) const;
	vector<Color> getColors() const;
};
