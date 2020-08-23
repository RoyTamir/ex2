#include <string>
using std::string;

class BitMapArrayParser {

	string _str;
	const int _width;
	const int _height;
	MatrixClass* _matrix;

public
	string getStr() const;
	int getWidth() const;
	int getHeight() const;
	&MatrixClass getBitMap() const;
}
