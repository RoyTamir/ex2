#pragma once

#include <string>
using std::string;

class BMPHeaderParser {

	string _str;
	int _size;
	int _offset;

public:
	BMPHeaderParser(string str);
	string getStr() const;
	int getSize() const;
	int getOffset() const;
};
