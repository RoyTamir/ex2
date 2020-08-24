#pragma once

#include "Color.hpp"

#include <cstdint>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::uint32_t;
using std::uint16_t;

class ColorTableParser {

	string _str;
	vector<Color> _colors;

public:
	ColorTableParser(const string& str);
	const string& getStr() const;
	uint32_t getColorCount() const;
	Color getColor(uint32_t n) const;
	vector<Color> getColors() const;
};
