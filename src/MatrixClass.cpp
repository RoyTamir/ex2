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

    double getValue(uint32_t rowIndex, uint32_t colIndex) const throw(ErrorCodeException){
        double value;

        //gets the value & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_getValue(matrix, rowIndex, colIndex, &value));

        return value;
    }

    MatrixClass& operator+(const MatrixClass& other) throw(ErrorCodeException){
        //Creating the result matrix 
        PMatrix result;
        matrix_create(&result, this->getHeight(), this->getWidth());

        //Calculating result matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_add(&result, matrix, other.matrix));

        //destroying the corrent matrix
        matrix_destroy(matrix);

        //updating the matrix to the result
        matrix = result;

        return *this;
    }

    MatrixClass& operator*(const MatrixClass& other) throw(ErrorCodeException){
        //Creating the result matrix 
        PMatrix result;
        matrix_create(&result, this->getHeight(), other.getWidth());

        //Calculating result matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_multiplyMatrices(&result, matrix, other.matrix));

        //destroying the corrent matrix
        matrix_destroy(matrix);

        //updating the matrix to the result
        matrix = result;

        return *this;
    }

    MatrixClass& operator*(double scalar) throw(ErrorCodeException){
        //Multipling this matrix with the scalar into 
        //this matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_multiplyWithScalar(matrix, scalar));

        return *this;
    }
};
