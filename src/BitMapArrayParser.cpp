#include "BitMapArrayParser.hpp"
#include "Color.cpp"

#include <string>
using std::string;

class BitMapArrayParser {

    string _str;
    const int _width;
    const int _height;
    const MatrixClass* _Rmatrix;
	const MatrixClass* _Gmatrix;
	const MatrixClass* _Bmatrix;
	const Vector<Color> _colors;

public
	BitMapArrayParser(string str, int width, int height, vector<Color> colors) {
		this._str = str;
		this._width = width;
		this._height = height;
		this._colors = colors;
		this._Rmatrix = new MatrixClass(this._width, this._height);
		this._Gmatrix = new MatrixClass(this._width, this._height);
		this._Bmatrix = new MatrixClass(this._width, this._height);
		string::iterator it = this._str.begin();
		for (int i = 0; i < this._height; i++) {
			for (int j = 0; j < this.width; j++, it++) {
				Color c = this._colors[it]
				this._Rmatrix.setValue(i, j, c.getR());
				this._Gmatrix.setValue(i, j, c.getG());
				this._Bmatrix.setValue(i, j, c.getB());
			}
		}
	}

	BitMapArrayParser(string str, int width, int height) {
        this._str = str;
        this._width = width;
        this._height = height;
		this._Rmatrix = new MatrixClass(this._width, this._height);
        this._Gmatrix = new MatrixClass(this._width, this._height);
        this._Bmatrix = new MatrixClass(this._width, this._height);
		string::iterator it = this._str.begin();
		for (int i = 0; i < this._height; i++) {
            for (int j = 0; j < this.width; j++, it++) {
                this._Rmatrix.setValue(i, j, it++);
                this._Gmatrix.setValue(i, j, it++);
                this._Bmatrix.setValue(i, j, it++);
            }
        }
    }

    string getStr() const {
		return this._str;
	}

    int getWidth() const {
		return this._width;
	}

    int getHeight() const {
		return this.height;
	}

    &MatrixClass getBitMapR() const {
		return this._Rmatrix;
	}

	&MatrixClass getBitMapG() const {
        return this._Gmatrix;
    }

	&MatrixClass getBitMapB() const {
        return this._Bmatrix;
    }
}
