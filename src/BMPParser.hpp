#pragma once

#include "BMPHeaderParser.hpp"
#include "DIBHeaderParser.hpp"
#include "ColorTableParser.hpp"
#include "BMArrayParserToMatrixes.hpp"
#include "BMPParser.hpp"
#include "Color.hpp"

#include <string>
using std::string;

class BMPParser {

	string _str;
	BMPHeaderParser* _BHparser;
	DIBHeaderParser* _DIBparser;
	ColorTableParser* _CTparser;
	BMArrayParserToMatrixes* _BMAparser;

public:
	BMPParser(string str);
	string getBMP() const;
};
