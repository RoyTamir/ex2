#pragma once

#include <string>
using std::string;

class BitmapHeaderParser {

	string _str;
	int _size;
	int _offset;

public:
	BitmapHeaderParser(string str);
	string getStr() const;
	int getSize() const;
	int getOffset() const;
};
