#pragma once

#include "MatrixClass.hpp"
#include "ColorTableParser.hpp"

#include <memory>
#include <cstdint>
#include <string>
#include <memory>

namespace BMPClasses {
class BMArrayWithColorPattle {
	//if we read a string that 
	//represent 0 we will save her (writing 0 is special).
	std::string m_zero;
	
	std::string m_str;
	std::uint32_t m_width;
	std::uint32_t m_height;
	std::uint16_t m_bytesPeddingPerRow; //max 3
	std::shared_ptr<MatrixClasses::MatrixClass> m_matrix;
    std::shared_ptr<ColorTableParser> m_colorTable;

public:
	/**
	 * @brief Construct a new BMArrayParserToMatrixes object.
	 * 
	 * @param str the string that represent the bmp array.
	 * @param width the width of the array.
	 * @param height the height of the array.
	 */
	BMArrayWithColorPattle(std::string str, std::uint32_t width,
            std::uint32_t height, const std::shared_ptr<ColorTableParser>& colorTable);

	/**
	 * @brief Get the Str object.
	 * 
	 * @return string the string that represent the bmp array.
	 */
	std::string getStr() const;

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
	MatrixClasses::MatrixClass& getBitMap() const;

	/**
	 * @brief Changes the Color Table Parser to gray
	 * as needed in the matrix.
	 * 
	 */
	void changeToGray();

	/**
 	* @brief Rotating the matrix 90 degree. 
 	* 
 	*/
	void rotate();
};
}
