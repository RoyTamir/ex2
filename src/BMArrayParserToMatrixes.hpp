#pragma once

#include "MatrixClass.hpp"
#include <cstdint>
#include <string>

namespace BMPClasses {
//for 24 bits pixels
class BMArrayParserToMatrixes {
	//if we read a string that 
	//represent 0 we will save her (writing 0 is special).
	std::string m_zero;

	std::string m_str;
	std::uint32_t m_width;
	std::uint32_t m_height;
	std::uint16_t m_bytesPeddingPerRow; //max 3
	MatrixClasses::MatrixClass* m_Rmatrix;
	MatrixClasses::MatrixClass* m_Bmatrix;
	MatrixClasses::MatrixClass* m_Gmatrix;

public:
	/**
	 * @brief Construct a new BMArrayParserToMatrixes object.
	 * 
	 * @param str 
	 * @param width 
	 * @param height 
	 */
	BMArrayParserToMatrixes(const std::string& str, std::uint32_t width, std::uint32_t height);

	/**
	 * @brief Get the Str object.
	 * (& changing the str to support the matrixes)
	 * 
	 * @return const string& 
	 */
	const std::string& getStr();

	/**
	 * @brief Get the Width object.
	 * 
	 * @return uint32_t the width of the BitmapArray.
	 */
	std::uint32_t getWidth() const;
	
	/**
	 * @brief Get the Height object.
	 * 
	 * @return uint32_t the height of the BitmapArray.
	 */
	std::uint32_t getHeight() const;

	/**
	 * @brief Returns the nummber of bytes pedding per row..
	 * 
	 * @return uint16_t the nummber of bytes pedding per row.
	 */
	std::uint16_t getbytesPeddingPerRow() const;

	/**
	 * @brief Get the Bit Map R object.
	 * 
	 * @return MatrixClass& the R pixel'S value -matrix of the BitmapArray.
	 */
	MatrixClasses::MatrixClass& getBitMapR() const;

	/**
	 * @brief Get the Bit Map G object.
	 * 
	 * @return MatrixClass& the G pixel'S value -matrix of the BitmapArray.
	 */
	MatrixClasses::MatrixClass& getBitMapG() const;

	/**
	 * @brief Get the Bit Map B object.
	 * 
	 * @return MatrixClass& the B pixel'S value -matrix of the BitmapArray.
	 */
	MatrixClasses::MatrixClass& getBitMapB() const;

	/**
	 * @brief Changes the matrixes to have
	 * together the RGB of the a gray color.
	 * 
	 */
	void changeToGray();

	/**
 	* @brief Rotating the matrixes 90 degree. 
 	* 
 	*/
	void rotate();
};
}