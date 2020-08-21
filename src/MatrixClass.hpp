#include <cstdint>
using std::uint32_t;

#include "ErrorCodeException.hpp"
#include "Matrix.h"

class MatrixClass{
//Fields
PMatrix matrix;

//methods
public:
	/**
	 * @brief Constructor, all values are initially zeroes.
	 *
	 * @param[in] height Height of the matrix.
	 * @param[in] width Width of the matrix.
	 */
	MatrixClass(uint32_t height, uint32_t width) throw(ErrorCodeException);

	/**
	 * @brief Constructor, a new Matrix Class object from matrix.
	 * (copy Constructor)
	 * 
	 * @param[in] source The matrix to copy.
	 */
	MatrixClass(const MatrixClass& source) throw(ErrorCodeException);

	/**
	 * @brief assignment opperator (copy assignment).
	 *
	 * @param[in] source The assigned matrix.
	 */
	MatrixClass& operator=(const MatrixClass& source) throw(ErrorCodeException);

		/**
	 * @brief Constructor, a new Matrix Class object from matrix.
	 * (move Constructor)
	 * 
	 * @param[in] source The matrix to copy.
	 */
	MatrixClass(MatrixClass&& source) throw(ErrorCodeException);

	/**
	 * @brief assignment opperator (move assignment).
	 *
	 * @param[in] source The assigned matrix.
	 */
	MatrixClass& operator=(MatrixClass&& source) throw(ErrorCodeException);

	/**
	 * @brief Returns height of given matrix.
	 *
	 * @return uint32_t
	 */
	uint32_t getHeight() const throw(ErrorCodeException);

	/**
	 * @brief Returns width of matrix.
	 *
	 * @return uint32_t
	 */
	uint32_t getWidth() const throw(ErrorCodeException);

	/**
	 * @brief Sets a value to the matrix.
	 *
	 * @param[in] rowIndex Row index of the value to set.
	 * @param[in] colIndex Column index of the value to setF.
	 * @param[in] value Value to set.
	 */
	void setValue(uint32_t rowIndex, uint32_t colIndex,
                           double value) throw(ErrorCodeException);

	/**
	 * @brief Sets a value to the matrix.
	 *
	 * @param[in] rowIndex Row index of the value to get.
	 * @param[in] colIndex Column index of the value to get.
	 * @return double.
	 */
	double getValue(uint32_t rowIndex, uint32_t colIndex) throw(ErrorCodeException);

	/**
	 * @brief Addition opperator.
	 *
	 * @param[in] other The right hand side of the addition operation.
	 * @return Matrix&
	 */
	MatrixClass& operator+(const MatrixClass& other) throw(ErrorCodeException);

	/**
	 * @brief Multiplication opperator (matrix by matrix).
	 *
	 * @param[in] other The right hand side of the multiplication operation.
	 * @return Matrix&
	 */
	MatrixClass& operator*(const MatrixClass& other) throw(ErrorCodeException);

	/**
	 * @brief Multiplication operator (matrix by scalar).
	 *
	 * @param[in] scalar The scalar to multiply with.
	 * @return Matrix&
	 */
	MatrixClass& operator*(double scalar) throw(ErrorCodeException);

	/**
	 * @brief Destructor for destroying the matrix.
	 */
	~MatrixClass();
};
