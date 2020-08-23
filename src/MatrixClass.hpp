#include "ErrorCodeException.hpp"
#include "Matrix.h"

#include <cstdint>
using std::uint32_t;

class MatrixClass{
//Fields
PMatrix _matrix;

//methods
public:
	/**
	 * @brief Constructor, all values are initially zeroes.
	 *
	 * @param[in] height Height of the matrix.
	 * @param[in] width Width of the matrix.
	 */
	MatrixClass(uint32_t height, uint32_t width);

	/**
	 * @brief Constructor, a new Matrix Class object from matrix.
	 * (copy Constructor)
	 * 
	 * @param[in] source The matrix to copy.
	 */
	MatrixClass(const MatrixClass& source);

	/**
	 * @brief assignment opperator (copy assignment).
	 *
	 * @param[in] source The assigned matrix.
	 */
	MatrixClass& operator=(const MatrixClass& source);

	/**
	 * @brief Returns height of given matrix.
	 *
	 * @return uint32_t
	 */
	uint32_t getHeight() const;

	/**
	 * @brief Returns width of matrix.
	 *
	 * @return uint32_t
	 */
	uint32_t getWidth() const;

	/**
	 * @brief Sets a value to the matrix.
	 *
	 * @param[in] rowIndex Row index of the value to set.
	 * @param[in] colIndex Column index of the value to setF.
	 * @param[in] value Value to set.
	 */
	void setValue(uint32_t rowIndex, uint32_t colIndex,
                           double value);

	/**
	 * @brief Sets a value to the matrix.
	 *
	 * @param[in] rowIndex Row index of the value to get.
	 * @param[in] colIndex Column index of the value to get.
	 * @return double.
	 */
	double getValue(uint32_t rowIndex, uint32_t colIndex) const;

	/**
	 * @brief Addition opperator (adds to the left side the right side).
	 *
	 * @param[in] other The right hand side of the addition operation.
	 * @return MatrixClass& 
	 */
	MatrixClass& operator+(const MatrixClass& other);

	/**
	 * @brief Multiplication opperator (matrix by matrix the risult in the left matrix).
	 *
	 * @param[in] other The right hand side of the multiplication operation.
	 * @return MatrixClass&
	 */
	MatrixClass& operator*(const MatrixClass& other);

	/**
	 * @brief Multiplication operator (matrix by scalar the result in the matrix).
	 *
	 * @param[in] scalar The scalar to multiply with.
	 * @return MatrixClass&
	 */
	MatrixClass& operator*(double scalar);

	/**
	 * @brief Destructor for destroying the matrix.
	 */
	~MatrixClass();

//DELETING MOVE METHODS (We would use only cpt methods)
	/**
	 * @brief Constructor, a new Matrix Class object from matrix.
	 * (move Constructor)
	 * 
	 * @param[in] source The matrix to copy.
	 */
	MatrixClass(MatrixClass&& source) = delete;

	/**
	 * @brief assignment opperator (move assignment).
	 *
	 * @param[in] source The assigned MatrixClass.
	 */
	MatrixClass& operator=(MatrixClass&& source) = delete;
};
