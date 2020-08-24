#pragma once

#include "BitmapHeaderParser.hpp"
#include "DIBHeaderParser.hpp"
#include "ColorTableParser.hpp"
#include "BitMapArrayParser.hpp"
#include "Color.hpp"

#include <string>
using std::string;

class BMPParser {

	string _str;
	BitmapHeaderParser* _BHparser;
	DIBHeaderParser* _DIBparser;
	ColorTableParser* _CTparser;
	BitMapArrayParser* _BMAparser;

public:
	BMPParser(string str);
	string getBMP() const;
};
