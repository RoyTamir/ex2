#include "BitMapArrayParser.hpp"

#include <string>
using std::string;
#include <vector>
using std::vector;

BitMapArrayParser::BitMapArrayParser(string str, int width, int height, vector<Color> colors) {
	this->_str = str;
	this->_width = width;
	this->_height = height;
	this->_colors = colors;
	this->_Rmatrix = new MatrixClass(this->_width, this->_height);
	this->_Gmatrix = new MatrixClass(this->_width, this->_height);
	this->_Bmatrix = new MatrixClass(this->_width, this->_height);
	string::iterator it = this->_str.begin();
	if (this->_colors.size()) {
		for (int i = 0; i < this->_height; i++) {
			for (int j = 0; j < this->_width; j++, it++) {
				Color c = this->_colors[*it];
				this->_Rmatrix->setValue(i, j, c.getR());
				this->_Gmatrix->setValue(i, j, c.getG());
				this->_Bmatrix->setValue(i, j, c.getB());
			}
		}
	} else {
		for (int i = 0; i < this->_height; i++) {
     	   for (int j = 0; j < this->_width; j++, it++) {
        	    this->_Rmatrix->setValue(i, j, *(it++));
            	this->_Gmatrix->setValue(i, j, *(it++));
            	this->_Bmatrix->setValue(i, j, *(it++));
        	}
    	}
	}
}
/*
BitMapArrayParser::BitMapArrayParser(string str, int width, int height) {
    this->_str = str;
    this->_width = width;
    this->_height = height;
	this->_Rmatrix = new MatrixClass(this->_width, this->_height);
    this->_Gmatrix = new MatrixClass(this->_width, this->_height);
    this->_Bmatrix = new MatrixClass(this->_width, this->_height);
	string::iterator it = this->_str.begin();
	for (int i = 0; i < this->_height; i++) {
        for (int j = 0; j < this->_width; j++, it++) {
            this->_Rmatrix->setValue(i, j, *(it++));
            this->_Gmatrix->setValue(i, j, *(it++));
            this->_Bmatrix->setValue(i, j, *(it++));
        }
    }
}
*/

string BitMapArrayParser::getStr() const {
	return this->_str;
}

int BitMapArrayParser::getWidth() const {
	return this->_width;
}

int BitMapArrayParser::getHeight() const {
	return this->_height;
}

MatrixClass& BitMapArrayParser::getBitMapR() const {
	return *(this->_Rmatrix);
}

MatrixClass& BitMapArrayParser::getBitMapG() const {
    return *(this->_Gmatrix);
}

MatrixClass& BitMapArrayParser::getBitMapB() const {
    return *(this->_Bmatrix);
}
