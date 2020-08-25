#pragma once

#include "MatrixClass.hpp"
#include <cstdint>
#include <string>
#include <memory>

using std::uint16_t;
using std::uint32_t;
using std::string;

//for 24 bits pixels
class BMArrayParserToMatrixes {

	string _str;
	uint32_t _width;
	uint32_t _height;
	uint16_t _bytesPeddingPerRow; //max 3
	MatrixClass* _Rmatrix;
	MatrixClass* _Bmatrix;
	MatrixClass* _Gmatrix;

public:
	BMArrayParserToMatrixes(const string& str, uint32_t width, uint32_t height);

	const string& getStr() const;

	uint32_t getWidth() const;

	uint32_t getHeight() const;

	uint16_t getbytesPeddingPerRow() const;

	MatrixClass& getBitMapR() const;

	MatrixClass& getBitMapG() const;

	MatrixClass& getBitMapB() const;
};
