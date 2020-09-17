#pragma once

#include <cstdint>
#include <string>
#include <iostream>

namespace BMPClasses {
class BMPHeaderParser {

//Fields
	std::string m_str;
	std::uint32_t m_size;
	std::uint32_t  m_offset;
public:

	static constexpr int BYTES_IN_SIZE = 4;
	static constexpr int SIZE_LOCATION = 2;
	static constexpr int OFFSET_LOCATION = 10;

	/**
	 * @brief Construct a new BMPHeaderParser object.
	 * 
	 * @param str the string from the BMP file
	 * that refers to header.
	 */
	BMPHeaderParser(std::string str);

	/**
	 * @brief Get the Str object.
	 * 
	 * @return the string from the BMP file
	 * * that refers to header.
	 */
	std::string getStr() const;

	/**
	 * @brief Get the Size object.
	 * 
	 * @return the the size of the BMP file, in bytes.
	 */
	std::uint32_t getSize() const;

	/**
	 * @brief Get the Offset object.
	 * 
	 * @return the Offset of the pixel array in bytes.
	 */
	std::uint32_t getOffset() const;
};
}