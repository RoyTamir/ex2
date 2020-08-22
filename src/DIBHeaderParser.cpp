#include "DIBHeaderParser.hpp"

#include <string>
using std::string

class DIBHeaderParser {

    string _str;
    int _bitArrayWidth;
    int _bitArrayHeight;
    int _bitsPerPixel;
    int _horizontalResolution;
    int _verticalResolution;

public:
	DIBHeaderParser(string str) {
		this._str = str;
		this._bitsPerPixel = str[10];
		int width = 0, height = 0, horRes = 0, horRes = 0, power = 1;
        for (int i = 0; i < 4; i++) {
            width += str[4 + i] * power;
            height += str[8 + i] * power;
			horRes += str[24 + i] * power;
			verRes += str[28 + i] * power;
            power *= 256;
        }
        this._bitArrayWidth = width;
        this._bitArrayHeight = height;
		this._horizontalResolution = horRes;
		this._verticalResolution = verRes;
	}

    string getStr() const {
		return this._str;
	}

    int getBitArrayWidth() const {
		return this._bitArrayWidth;
	}

    int getBitArrayHeight() const;
		return this._bitArrayHeight;
	}

    int getBitsPerPixel() const {
		return this._bitsPerPixel;
	}

    int getHorizontalResolution() const {
		return this._horizontalResolution;
	}

    int getVerticalResolution() {
		return this._verticalReolution;
	}
}
