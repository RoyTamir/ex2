#include "ColorTableParser.hpp"

#include <string>
#include <vector>
using std::string;
using std::vector;

class ColorTableParser {

    string _str;
    vector<vector<int>> _colors;

public:
	ColorTableParser(string str) {
		this._str = str;
	}

    string getStr() const {
		return this._str;
	}

    vector<int> getColor(int n) const {
		return colors[n];
	}
}
