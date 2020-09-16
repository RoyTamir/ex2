#include "BMArrayWithColorPattle.hpp"

using namespace BMPClasses;
using namespace MatrixClasses;
using std::uint16_t;
using std::uint32_t;
using std::string;

BMArrayWithColorPattle::BMArrayWithColorPattle(const string& str, uint32_t width,
        uint32_t height, ColorTableParser* colorTable){
    this->m_str = str;
	this->m_width = width;
	this->m_height = height;
	this->m_matrix = new MatrixClass(height, width);
    this->m_colorTable = colorTable;

	//calculating how much padding for width *1 (=nub bits to pixel) to be 4*int
	this->m_bytesPeddingPerRow = (4 - ((width) % 4))%4;

	for (uint32_t row = 0; row < height; ++row) {
		//where in the string the new row of the matrix starts
		uint32_t starOfRow = row * (width + m_bytesPeddingPerRow);

		//the file is starting from the bottom left of 
		//the picture to the upper right of the picture.
		uint32_t rowIndex = (height - 1) - row;
		for (uint32_t col = 0; col < width; ++col) {
			//startOfRaw in the matrix, col = num of pixel in the raw before (*1 = this size in the string)
			uint16_t* colorIndex = (uint16_t*) str.substr(starOfRow + col , 1).data();
			if(*colorIndex == 0){
			this->m_zero = str.substr(starOfRow + col , 1);
			}
			this->m_matrix->setValue(rowIndex, col, *colorIndex);
		}
	}
}

const string& BMArrayWithColorPattle::getStr() const {
	return this->m_str;
}

uint32_t BMArrayWithColorPattle::getWidth() const {
	return this->m_width;
}

uint32_t BMArrayWithColorPattle::getHeight() const {
	return this->m_height;
}

uint16_t BMArrayWithColorPattle::getbytesPeddingPerRow() const {
	return this->m_bytesPeddingPerRow;
}

MatrixClass& BMArrayWithColorPattle::getBitMap() const {
	return *(this->m_matrix);
}

void BMArrayWithColorPattle::changeToGray() {
	for(uint32_t row = 0; row < this->m_height; ++row){
		for (uint32_t col = 0; col < this->m_width; ++col) {
			this->m_colorTable->changeColorToGray((uint32_t) ((*(this->m_matrix))(row, col)));
		}
	}
}

void BMArrayWithColorPattle::rotate() {
		//switching width & height
	uint32_t width = this->m_width;
	uint32_t height = this->m_height;
	this->m_height = width;
	this->m_width = height;

	MatrixClass* newMatrix = new MatrixClass(this->m_height, this->m_width);

	//Itarating on the old matrixes and intalizing the new ones.
	for (uint32_t row = 0; row < this->m_width; ++row) {
		for (uint32_t col = 0; col < this->m_height; ++col) {
		
			newMatrix->setValue(col, this->m_width - row - 1,(*(this->m_matrix))(row, col));
		
		}
	}
	delete this->m_matrix;

	this->m_matrix = newMatrix;

	//writing it to the str:

	for (uint32_t row = 0; row < this->m_height; ++row) {
		//where in the string the new row of the matrix starts
		uint32_t starOfRow = row * (this->m_width + m_bytesPeddingPerRow);

		//the file is starting from the bottom left of 
		//the picture to the upper right of the picture.
		uint32_t rowIndex = (this->m_height - 1) - row;

		uint16_t color;
    	char* c;
   		string s;
		for (uint32_t col = 0; col < this->m_width; ++col) {
			if ((*(this->m_matrix))(rowIndex, col) != 0) {
				color = (uint16_t) (*(this->m_matrix))(rowIndex, col);
				c = (char*) &color;
   		 		s = c;
			}else{//0 is special to write
   		 		s = this->m_zero;	
			}
			this->m_str.replace(starOfRow + col , 1, s);
		}
	}
}

