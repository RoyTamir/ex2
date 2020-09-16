#pragma once

#include <cstdint>
#include <string>
#include <iostream>

#define NUM_BYTES_OF_SIZE_AND_OFFSET 4
#define LOCATION_OF_SIZE 2
#define LOCATION_OF_OFFSET 10

namespace BMPClasses {
class BMPHeaderParser {

//Fields
	std::string m_str;
	std::uint32_t m_size;
	std::uint32_t  m_offset;
public:
	/**
	 * @brief Construct a new BMPHeaderParser object.
	 * 
	 * @param str the string from the BMP file
	 * that refers to header.
	 */
	BMPHeaderParser(const std::string& str);

	/**
	 * @brief Get the Str object.
	 * 
	 * @return the string from the BMP file
	 * * that refers to header.
	 */
	const std::string& getStr() const;

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