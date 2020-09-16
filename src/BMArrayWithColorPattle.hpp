#pragma once

#include "MatrixClass.hpp"
#include "ColorTableParser.hpp"
#include <cstdint>
#include <string>
#include <memory>

//for 8 bits pixels
class BMArrayWithColorPattle {
	//if we read a string that 
	//represent 0 we will save her (writing 0 is special).
	std::string _zero;
	
	std::string _str;
	std::uint32_t _width;
	std::uint32_t _height;
	std::uint16_t _bytesPeddingPerRow; //max 3
	MatrixClass* _matrix;
    ColorTableParser* _colorTable;

public:
	/**
	 * @brief Construct a new BMArrayParserToMatrixes object.
	 * 
	 * @param str 
	 * @param width 
	 * @param height 
	 */
	BMArrayWithColorPattle(const std::string& str, std::uint32_t width,
            std::uint32_t height, ColorTableParser* colorTable);

	/**
	 * @brief Get the Str object.
	 * 
	 * @return const string& 
	 */
	const std::string& getStr() const;

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
	MatrixClass& getBitMap() const;

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
