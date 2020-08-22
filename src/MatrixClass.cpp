#include "MatrixClass.hpp"

class MatrixClass{
//Fields
PMatrix matrix;

//methods
public:
	MatrixClass(uint32_t height, uint32_t width) throw(ErrorCodeException) {
        //creating the matrix
        ErrorCode er = matrix_create(&matrix, height, width);

        //checking success
        ErrorCodeException* exeption = new ErrorCodeException(er);
        if(!exeption->isSuccess()) {
            throw exeption;
        }
    }

    MatrixClass(const MatrixClass& source) throw(ErrorCodeException) {
        //copy the matrix
        ErrorCode er = matrix_copy(&matrix, source.matrix);

        //checking success
        ErrorCodeException* exeption = new ErrorCodeException(er);
        if(!exeption->isSuccess()) {
            throw exeption;
        }
    }

    MatrixClass& operator=(const MatrixClass& source) throw(ErrorCodeException){

        //Trying to destroy the matrix in the field (if not intalized yet would do nothing)
        matrix_destroy(matrix);

        //create copy of the matrix in the fields
        ErrorCode er = matrix_copy(&matrix, source.matrix);

        //checking success
        ErrorCodeException* exeption = new ErrorCodeException(er);
        if(!exeption->isSuccess()) {
            throw exeption;
        }

        return *this;
    }
};
