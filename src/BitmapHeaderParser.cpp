#include "BitmapHeaderParser.hpp"

class BitmapHeaderParser {

    const char* _str;
    const int _size;
    const int _offset;
    
public:
	BitMapHeaderParser(const char* str) {
		this._str = str;
	}

    char* getStr() const {
		return this._str;
	}

    int getSize() const {
		return this._size;
	}

    int getOffset() const {
		return this._offset;
	}
}
