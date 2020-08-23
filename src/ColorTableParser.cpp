#include "ColorTableParser.hpp"

#include <string>
#include <vector>
using std::string;
using std::vector;

class ColorTableParser {

    string _str;
    vector<Color> _colors;

public:
	ColorTableParser(string str) {
		this._str = str;
		for (string::iterator it = this._str.begin(); it != this._str.end, it++) {
			this._colors.pushback(new Color(it++, it++, it++));
		}
	}

    string getStr() const {
		return this._str;
	}

	int getColorCount() const {
		return this._colors.size();
	}

    Color getColor(int n) const {
		return _colors[n];
	}
}
