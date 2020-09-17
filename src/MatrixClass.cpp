#include "MatrixClass.hpp"

using namespace MatrixClasses;
using std::uint32_t;

//Implementing methods
	MatrixClass::MatrixClass(uint32_t height, uint32_t width){
        //creating the matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_create(&m_matrix, height, width));
    }

    MatrixClass::MatrixClass(const MatrixClass& source){
        //copy the matrix & throwing excepstion if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_copy(&m_matrix, source.m_matrix));
    }

    MatrixClass::MatrixClass(MatrixClass&& source) {
        //copying the data
        m_matrix = source.m_matrix;

        // Nulling out the deta of op
        source.m_matrix = nullptr;
    }

    MatrixClass& MatrixClass::operator=(MatrixClass&& source){
        //copying the data
        m_matrix = source.m_matrix;

        // Nulling out the deta of op
        source.m_matrix = nullptr;

        return *this;
    }

    MatrixClass& MatrixClass::operator=(const MatrixClass& source){

        //Trying to destroy the matrix in the field (if not intalized yet would do nothing)
        matrix_destroy(m_matrix);

        //creating copy of the matrix in the field & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_copy(&m_matrix, source.m_matrix));

        return *this;
    }

    uint32_t MatrixClass::getHeight() const {
        uint32_t height;

        //gets the height & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_getHeight(m_matrix, &height));

        return height;
    }

    uint32_t MatrixClass::getWidth() const {
        uint32_t width;

        //gets the width & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_getWidth(m_matrix, &width));

        return width;
    }

    void MatrixClass::setValue(uint32_t rowIndex, uint32_t colIndex,
                           double value) {
        //sets the value & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_setValue(m_matrix, rowIndex, colIndex, value));
    }

    double MatrixClass::operator()(uint32_t rowIndex, uint32_t colIndex) const{
        double value;

        //gets the value & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_getValue(m_matrix, rowIndex, colIndex, &value));

        return value;
    }

    MatrixClass& MatrixClass::operator+=(const MatrixClass& other) {
        //Creating the result matrix 
        PMatrix result;
        ErrorCodeException::throwErrorIfNeeded(
            matrix_create(&result, this->getHeight(), this->getWidth()));

        //Calculating result matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_add(&result, m_matrix, other.m_matrix));

        //destroying the corrent matrix
        matrix_destroy(m_matrix);

        //updating the matrix to the result
        m_matrix = result;

        return *this;
    }

    MatrixClass&  MatrixClass::operator-=(const MatrixClass& other) {
        MatrixClass minusOther (other);
        minusOther *= (-1); //making the matrix to minus
        (*this) += minusOther;
        return *this;
    }

    MatrixClass& MatrixClass::operator*=(const MatrixClass& other) {
        //Creating the result matrix 
        PMatrix result;
        ErrorCodeException::throwErrorIfNeeded(
            matrix_create(&result, this->getHeight(), other.getWidth()));

        //Calculating result matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_multiplyMatrices(&result, m_matrix, other.m_matrix));

        //destroying the corrent matrix
        matrix_destroy(m_matrix);

        //updating the matrix to the result
        m_matrix = result;

        return *this;
    }

    MatrixClass& MatrixClass::operator*=(double scalar){
        //Multipling this matrix with the scalar into 
        //this matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_multiplyWithScalar(m_matrix, scalar));

        return *this;
    }

    MatrixClass& MatrixClass::operator/=(double scalar) {
        if (scalar == 0) {
            throw std::runtime_error("Error: can't divide the matrix by 0");
        }

        return *(this) *= (1 / scalar);
    }

    MatrixClass::~MatrixClass() {
        //destroying the corrent matrix
        matrix_destroy(m_matrix);
    }

//another operators. warning! they return new MatrixClass
    MatrixClass& MatrixClass::operator+(const MatrixClass& other) const{
        //Creating the result matrix 
        std::shared_ptr<MatrixClass> result = std::make_shared<MatrixClass>(this->getHeight(), this->getWidth());

        //Calculating result matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_add(&result->m_matrix, m_matrix, other.m_matrix));

        return *result;
    }

    MatrixClass& MatrixClass::operator-(const MatrixClass& other) const {
        MatrixClass minusOther (other);
        minusOther *= (-1); //making the matrix to minus

        //Creating the result matrix 
        std::shared_ptr<MatrixClass> result = std::make_shared<MatrixClass>(this->getHeight(), this->getWidth());

        //Calculating result matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
             matrix_add(&result->m_matrix, m_matrix, minusOther.m_matrix));
        return *result;
    }

    MatrixClass& MatrixClass::operator*(const MatrixClass& other) const{
        //Creating the result matrix 
        std::shared_ptr<MatrixClass> result = std::make_shared<MatrixClass>(this->getHeight(), other.getWidth());

        //Calculating result matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_multiplyMatrices(&result->m_matrix, m_matrix, other.m_matrix));

        return *result;
    }

    MatrixClass& MatrixClass::operator*(double scalar) const {
        //Creating the result matrix (copying this matrix)
        std::shared_ptr<MatrixClass> result = std::make_shared<MatrixClass>(*this);

        //Multipling this matrix with the scalar into 
        //this matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_multiplyWithScalar(result->m_matrix, scalar));

        return *result;
    }

    MatrixClass& MatrixClass::operator/(double scalar) const {
        if (scalar == 0) {
            throw std::runtime_error("Error: can't divide the matrix by 0");
        }

        return *this * (1 / scalar);
    }

//friends functins

    MatrixClass& operator*(double scalar, const MatrixClass& matrix) {
        return matrix * scalar;
    }
