#pragma once

#include "BitmapHeaderParser.cpp"
#include "DIBHeaderParser.cpp"
#include "ColorTableParser.cpp"
#include "BitmapArrayParser.cpp"
#include "Color.cpp"

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
