#include "MatrixClass.hpp"

class MatrixClass{
//Fields
PMatrix matrix;

//methods
public:
	MatrixClass(uint32_t height, uint32_t width) throw(ErrorCodeException) {
        //creating the matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_create(&matrix, height, width));
    }

    MatrixClass(const MatrixClass& source) throw(ErrorCodeException) {
        //copy the matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_copy(&matrix, source.matrix));
    }

    MatrixClass& operator=(const MatrixClass& source) throw(ErrorCodeException){

        //Trying to destroy the matrix in the field (if not intalized yet would do nothing)
        matrix_destroy(matrix);

        //creating copy of the matrix in the field & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_copy(&matrix, source.matrix));

        return *this;
    }

    uint32_t getHeight() const throw(ErrorCodeException) {
        uint32_t height;

        //gets the height & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_getHeight(matrix, &height));

        return height;
    }

    uint32_t getWidth() const throw(ErrorCodeException) {
        uint32_t width;

        //gets the width & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_getWidth(matrix, &width));

        return width;
    }

    void setValue(uint32_t rowIndex, uint32_t colIndex,
                           double value) throw(ErrorCodeException){
        //sets the value & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_setValue(matrix, rowIndex, colIndex, value));
    }

    
};
