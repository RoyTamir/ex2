#include "BMArrayParserToMatrixes.hpp"

BMArrayParserToMatrixes::BMArrayParserToMatrixes(string str, int width, int height, vector<Color> colors) {
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
BMArrayParserToMatrixes::BMArrayParserToMatrixes(string str, int width, int height) {
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

string BMArrayParserToMatrixes::getStr() const {
	return this->_str;
}

int BMArrayParserToMatrixes::getWidth() const {
	return this->_width;
}

int BMArrayParserToMatrixes::getHeight() const {
	return this->_height;
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
