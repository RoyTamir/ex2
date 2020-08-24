#pragma once

#include "MatrixClass.hpp"
#include "Color.hpp"

#include <string>
using std::string;
#include <vector>
using std::vector;

class BitMapArrayParser {

	string _str;
	int _width;
	int _height;
	MatrixClass* _Rmatrix;
	MatrixClass* _Bmatrix;
	MatrixClass* _Gmatrix;
	vector<Color> _colors;

public:
	BitMapArrayParser(string str, int width, int height, vector<Color> colors);
	//BitMapArrayParser(string str, int width, int height);
	string getStr() const;

	int getWidth() const;

	int getHeight() const;

	MatrixClass& getBitMap() const;

	MatrixClass& getBitMapR() const;

	MatrixClass& getBitMapG() const;

	MatrixClass& getBitMapB() const;
};
