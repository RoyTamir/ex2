#include "BMArrayWithColorPattle.hpp"

BMArrayWithColorPattle::BMArrayWithColorPattle(const string& str, uint32_t width,
            uint32_t height, ColorTableParser* colorTable){
    this->_str = str;
	this->_width = width;
	this->_height = height;
	this->_matrix = new MatrixClass(height, width);
    this->_colorTable = colorTable;

	//calculating how much padding for width *1 (=nub bits to pixel) to be 4*int
	this->_bytesPeddingPerRow = (4 - ((width) % 4))%4;

	for (uint32_t row = 0; row < height; ++row) {
		//where in the string the new row of the matrix starts
		uint32_t starOfRow = row * (width + _bytesPeddingPerRow);

		//the file is starting from the bottom left of 
		//the picture to the upper right of the picture.
		uint32_t rowIndex = (height - 1) - row;
		for (uint32_t col = 0; col < width; ++col) {
			//startOfRaw in the matrix, col = num of pixel in the raw before (*1 = this size in the string)
			uint16_t* colorIndex = (uint16_t*) str.substr(starOfRow + col , 1).data();

			this->_matrix->setValue(rowIndex, col, *colorIndex);
		}
	}
}

const string& BMArrayWithColorPattle::getStr() const {
	return this->_str;
}

uint32_t BMArrayWithColorPattle::getWidth() const {
	return this->_width;
}

uint32_t BMArrayWithColorPattle::getHeight() const {
	return this->_height;
}

uint16_t BMArrayWithColorPattle::getbytesPeddingPerRow() const {
	return this->_bytesPeddingPerRow;
}

MatrixClass& BMArrayWithColorPattle::getBitMap() const {
	return *(this->_matrix);
}
 

