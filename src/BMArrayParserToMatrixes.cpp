#include "BMArrayParserToMatrixes.hpp"

//calculating how much padding for width *3 (=nub bits to pixel) to be 4*int
#define GET_BYTES_PEDDING_PER_ROW(width) ((4 - ((width * 3) % 4))%4)

using namespace BMPClasses;
using namespace MatrixClasses;
using std::uint16_t;
using std::uint32_t;
using std::string;

void BMArrayParserToMatrixes::writeChangesToStr() {
	//writing the changes to the string
	for (uint32_t row = 0; row < this->m_height; ++row) {
		//where in the string the new row of the matrix starts
		uint32_t starOfRow = row * (this->m_width * 3 + m_bytesPeddingPerRow);

		//the file is starting from the bottom left of 
		//the picture to the upper right of the picture.
		uint32_t rowIndex = (this->m_height - 1) - row;

		uint16_t color;
    	char* c;
   		string s;
		//Note: if we have 0 in one of the var we check
		// it means we got a zero when we read (and intalized _zero)
		//(if the 0 is from changeToGray() it means there were a place were
		//R=0, G=0, B=0
		for (uint32_t col = 0; col < this->m_width; ++col) {
			if ((*(this->m_Rmatrix))(rowIndex, col) != 0) {
				color = static_cast<uint16_t>((*(this->m_Rmatrix))(rowIndex, col));
				c = reinterpret_cast<char*>(&color);
   		 		s = c;
			}else{//0 is special to write
   		 		s = this->m_zero;	
			}
			this->m_str.replace(starOfRow + col * 3, 1, s);

			if ((*(this->m_Gmatrix))(rowIndex, col) != 0) {
				color = static_cast<uint16_t>((*(this->m_Gmatrix))(rowIndex, col));
				c = reinterpret_cast<char*>(&color);
   		 		s = c;
			}else{//0 is special to write
   		 		s = this->m_zero;	
			}
			this->m_str.replace(starOfRow + col * 3 + 1, 1, s);

			if ((*(this->m_Bmatrix))(rowIndex, col) != 0) {
				color = static_cast<uint16_t>((*(this->m_Bmatrix))(rowIndex, col));
				c = reinterpret_cast<char*>(&color);
   		 		s = c;
			}else{//0 is special to write
   		 		s = this->m_zero;	
			}
			this->m_str.replace(starOfRow + col * 3 + 2, 1, s);
		}
	}
}

BMArrayParserToMatrixes::BMArrayParserToMatrixes(string str, uint32_t width, uint32_t height) {
	this->m_str = std::move(str);
	this->m_width = width;
	this->m_height = height;
	this->m_Rmatrix = std::make_shared<MatrixClass>(height, width);
	this->m_Gmatrix = std::make_shared<MatrixClass>(height, width);
	this->m_Bmatrix = std::make_shared<MatrixClass>(height, width);

	//calculating how much padding for width *3 (=nub bits to pixel) to be 4*int
	this->m_bytesPeddingPerRow = GET_BYTES_PEDDING_PER_ROW(width);

	for (uint32_t row = 0; row < height; ++row) {
		//wher in the string the new row of the matrix starts
		uint32_t starOfRow = row * (width * 3 + m_bytesPeddingPerRow);

		//the file is starting from the bottom left of 
		//the picture to the upper right of the picture.
		uint32_t rowIndex = (height - 1) - row;
		for (uint32_t col = 0; col < width; ++col) {
			//startOfRaw in the matrix, col = num of pixel in the raw before (*3 = his size in the string)
			uint16_t* r = const_cast<uint16_t*>(reinterpret_cast<const uint16_t*>(str.substr(starOfRow + col * 3, 1).data()));
			if(*r == 0){
				this->m_zero = str.substr(starOfRow + col * 3, 1);
			}

			uint16_t* g = const_cast<uint16_t*>(reinterpret_cast<const uint16_t*>(str.substr(starOfRow + col * 3 + 1, 1).data()));
			if(*r == 0){
				this->m_zero = str.substr(starOfRow + col * 3 + 1, 1);
			}

			uint16_t* b = const_cast<uint16_t*>(reinterpret_cast<const uint16_t*>(str.substr(starOfRow + col * 3 + 2, 1).data()));
			if(*r == 0){
				this->m_zero = str.substr(starOfRow + col * 3 + 2, 1);
			}

			this->m_Rmatrix->setValue(rowIndex, col, *r);
			this->m_Gmatrix->setValue(rowIndex, col, *g);
			this->m_Bmatrix->setValue(rowIndex, col, *b);
		}
	}
}

string BMArrayParserToMatrixes::getStr() const{
	return this->m_str;
}

uint32_t BMArrayParserToMatrixes::getWidth() const {
	return this->m_width;
}

uint32_t BMArrayParserToMatrixes::getHeight() const {
	return this->m_height;
}

uint16_t BMArrayParserToMatrixes::getbytesPeddingPerRow() const {
	return this->m_bytesPeddingPerRow;
}

MatrixClass& BMArrayParserToMatrixes::getBitMapR() const {
	return *(this->m_Rmatrix);
}

MatrixClass& BMArrayParserToMatrixes::getBitMapG() const {
    return *(this->m_Gmatrix);
}

MatrixClass& BMArrayParserToMatrixes::getBitMapB() const {
    return *(this->m_Bmatrix);
}

void BMArrayParserToMatrixes::changeToGray() {
	//the numbers are part of a 
	//formula to make a RGB color to gray.
	*(this->m_Rmatrix) *= 0.2126;
	*(this->m_Gmatrix) *= 0.7152;
	*(this->m_Bmatrix) *= 0.0722;

	MatrixClass gray(this->m_height, this->m_width);
	gray += *(this->m_Rmatrix);
	gray += *(this->m_Gmatrix);
	gray += *(this->m_Bmatrix);

	*(this->m_Rmatrix) = gray;
	*(this->m_Gmatrix) = gray;
	*(this->m_Bmatrix) = gray;

	writeChangesToStr();
}

void BMArrayParserToMatrixes::rotate() {
	//switching width & height
	uint32_t width = this->m_width;
	uint32_t height = this->m_height;
	this->m_height = width;
	this->m_width = height;

	std::shared_ptr<MatrixClass>  newRmatrix = std::make_shared<MatrixClass>(this->m_height, this->m_width);
	std::shared_ptr<MatrixClass>  newGmatrix = std::make_shared<MatrixClass>(this->m_height, this->m_width);
	std::shared_ptr<MatrixClass>  newBmatrix = std::make_shared<MatrixClass>(this->m_height, this->m_width);

	//Itarating on the old matrixes and intalizing the new ones.
	for (uint32_t row = 0; row < this->m_width; ++row) {
		for (uint32_t col = 0; col < this->m_height; ++col) {
		
			newRmatrix->setValue(col, this->m_width - row - 1,(*(this->m_Rmatrix))(row, col));
			newGmatrix->setValue(col, this->m_width -  row - 1,(*(this->m_Gmatrix))(row, col));
			newBmatrix->setValue(col, this->m_width -  row - 1,(*(this->m_Bmatrix))(row, col));
		
		}
	}

	this->m_Rmatrix = newRmatrix;
	this->m_Gmatrix = newGmatrix;
	this->m_Bmatrix = newBmatrix;

	writeChangesToStr();
}
