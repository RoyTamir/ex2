#include "BMArrayParserToMatrixes.hpp"

BMArrayParserToMatrixes::BMArrayParserToMatrixes(const string& str, uint32_t width, uint32_t height) {
	this->_str = str;
	this->_width = width;
	this->_height = height;
	this->_Rmatrix = new MatrixClass(height, width);
	this->_Gmatrix = new MatrixClass(height, width);
	this->_Bmatrix = new MatrixClass(height, width);

	//calculating how much padding for width *3 (=nub bits to pixel) to be 4*int
	this->_bytesPeddingPerRow = (4 - ((width * 3) % 4))%4;

	for (uint32_t row = 0; row < height; ++row) {
		//wher in the string the new row of the matrix starts
		uint32_t starOfRow = row * (width * 3 + _bytesPeddingPerRow);

		//the file is starting from the bottom left of 
		//the picture to the upper right of the picture.
		uint32_t rowIndex = (height - 1) - row;
		for (uint32_t col = 0; col < width; ++col) {
			//startOfRaw in the matrix, col = num of pixel in the raw before (*3 = his size in the string)
			uint16_t* r = (uint16_t*) str.substr(starOfRow + col * 3, 1).data();

			uint16_t* g = (uint16_t*) str.substr(starOfRow + col * 3 + 1, 1).data();

			uint16_t* b = (uint16_t*) str.substr(starOfRow + col * 3 + 2, 1).data();

			this->_Rmatrix->setValue(rowIndex, col, *r);
			this->_Gmatrix->setValue(rowIndex, col, *g);
			this->_Bmatrix->setValue(rowIndex, col, *b);
		}
	}
}

const string& BMArrayParserToMatrixes::getStr() const {
	return this->_str;
}

uint32_t BMArrayParserToMatrixes::getWidth() const {
	return this->_width;
}

uint32_t BMArrayParserToMatrixes::getHeight() const {
	return this->_height;
}

uint16_t BMArrayParserToMatrixes::getbytesPeddingPerRow() const {
	return this->_bytesPeddingPerRow;
}

MatrixClass& BMArrayParserToMatrixes::getBitMapR() const {
	return *(this->_Rmatrix);
}

MatrixClass& BMArrayParserToMatrixes::getBitMapG() const {
    return *(this->_Gmatrix);
}

MatrixClass& BMArrayParserToMatrixes::getBitMapB() const {
    return *(this->_Bmatrix);
}

void BMArrayParserToMatrixes::changeToGray() {
	*(this->_Rmatrix) *= 0.2126;
	*(this->_Gmatrix) *= 0.7152;
	*(this->_Bmatrix) *= 0.0722;

	MatrixClass gray(this->_height, this->_width);
	gray += *(this->_Rmatrix);
	gray += *(this->_Gmatrix);
	gray += *(this->_Bmatrix);

	*(this->_Rmatrix) = gray;
	*(this->_Gmatrix) = gray;
	*(this->_Bmatrix) = gray;
}
