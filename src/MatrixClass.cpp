#include "MatrixClass.hpp"

//Implementing methods
	MatrixClass::MatrixClass(uint32_t height, uint32_t width)
     throw(ErrorCodeException) {
        //creating the matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_create(&_matrix, height, width));
    }

    MatrixClass::MatrixClass(const MatrixClass& source)
     throw(ErrorCodeException) {
        //copy the matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_copy(&_matrix, source._matrix));
    }

    MatrixClass& MatrixClass::operator=(const MatrixClass& source)
     throw(ErrorCodeException){

        //Trying to destroy the matrix in the field (if not intalized yet would do nothing)
        matrix_destroy(_matrix);

        //creating copy of the matrix in the field & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_copy(&_matrix, source._matrix));

        return *this;
    }

    uint32_t MatrixClass::getHeight() const throw(ErrorCodeException) {
        uint32_t height;

        //gets the height & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_getHeight(_matrix, &height));

        return height;
    }

    uint32_t MatrixClass::getWidth() const throw(ErrorCodeException) {
        uint32_t width;

        //gets the width & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_getWidth(_matrix, &width));

        return width;
    }

    void MatrixClass::setValue(uint32_t rowIndex, uint32_t colIndex,
                           double value) throw(ErrorCodeException){
        //sets the value & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_setValue(_matrix, rowIndex, colIndex, value));
    }

    double MatrixClass::getValue(uint32_t rowIndex, uint32_t colIndex)
     const throw(ErrorCodeException){
        double value;

        //gets the value & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_getValue(_matrix, rowIndex, colIndex, &value));

        return value;
    }

    MatrixClass& MatrixClass::operator+(const MatrixClass& other)
     throw(ErrorCodeException){
        //Creating the result matrix 
        PMatrix result;
        matrix_create(&result, this->getHeight(), this->getWidth());

        //Calculating result matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_add(&result, _matrix, other._matrix));

        //destroying the corrent matrix
        matrix_destroy(_matrix);

        //updating the matrix to the result
        _matrix = result;

        return *this;
    }

    MatrixClass& MatrixClass::operator*(const MatrixClass& other)
     throw(ErrorCodeException){
        //Creating the result matrix 
        PMatrix result;
        matrix_create(&result, this->getHeight(), other.getWidth());

        //Calculating result matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_multiplyMatrices(&result, _matrix, other._matrix));

        //destroying the corrent matrix
        matrix_destroy(_matrix);

        //updating the matrix to the result
        _matrix = result;

        return *this;
    }

    MatrixClass& MatrixClass::operator*(double scalar) throw(ErrorCodeException){
        //Multipling this matrix with the scalar into 
        //this matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_multiplyWithScalar(_matrix, scalar));

        return *this;
    }

    MatrixClass::~MatrixClass() {
        //destroying the corrent matrix
        matrix_destroy(_matrix);
    }
