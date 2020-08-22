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
	string getStr() const;
	int getBitArrayWidth() const;
	int getBitArrayHeight() const;
	int getBitsPerPixel() const;
	int getHorizontalResolution() const;
	int getVerticalResolution() const;
}
