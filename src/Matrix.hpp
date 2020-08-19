#include <cstdint>
using std::uint32_t;

#include "ErrorCodeException.hpp"

class Matrix {
private:
	const uint32_t _width;
	const uint32_t _height;
	const double* _topLeft;

public:
	/**
	 * @brief Constructor, all values are initially zeroes.
	 *
	 * @param[in] height Height of the matrix
	 * @param[in] width Width of the matrix
	 */
	Matrix(const uint32_t height, const uint32_t width) throw(ErrorCodeException);

	/**
	 * @brief assignment opperator.
	 *
	 * @param[in] source The assigned matrix.
	 */
	Matrix& operator=(const Matrix& source) throw(ErrorCodeException);

	/**
	 * @brief Destroys matrix.
	 */
	void destroy() throw(ErrorCodeException);

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
	void setValue(const uint32_t rowIndex, const uint32_t colIndex,
                          const double value) throw(ErrorCodeException);

	/**
	 * @brief Sets a value to the matrix.
	 *
	 * @param[in] rowIndex Row index of the value to get.
	 * @param[in] colIndex Column index of the value to get.
	 * @return double.
	 */
	double getValue(const uint32_t rowIndex, const uint32_t colIndex)
						const throw(ErrorCodeException);

	/**
	 * @brief Addition opperator.
	 *
	 * @param[in] other The right hand side of the addition operation.
	 * @return Matrix&
	 */
	Matrix& operator+(const Matrix& other) throw(ErrorCodeException);

	/**
	 * @brief Multiplication opperator (matrix by matrix).
	 *
	 * @param[in] other The right hand side of the multiplication operation.
	 * @return Matrix&
	 */
	Matrix& operator*(const Matrix& other) throw(ErrorCodeException);

	/**
	 * @brief Multiplication operator (matrix by scalar).
	 *
	 * @param[in] scalar The scalar to multiply with.
	 * @return Matrix&
	 */
	Matrix& operator*(const double scalar) noexcept;
}
