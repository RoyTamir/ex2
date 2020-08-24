#pragma once

#include <string>
using std::string;

#define NUM_BYTES_OF_SIZE_AND_OFFSET 4
#define LOCATION_OF_SIZE 2
#define LOCATION_OF_OFFSET 10
class BMPHeaderParser {

//Fields
	string _str;
	int _size;
	int _offset;
public:
	/**
	 * @brief Construct a new BMPHeaderParser object.
	 * 
	 * @param str the string from the 
	 * BMP file that Represents the Header.
	 */
	BMPHeaderParser(string str);

	/**
	 * @brief Get the Str object.
	 * 
	 * @return the string from the 
	 * BMP file that Represents the Header.
	 */
	string getStr() const;

	/**
	 * @brief Get the Size object.
	 * 
	 * @return the the size of the BMP file, in bytes.
	 */
	int getSize() const;

	/**
	 * @brief Get the Offset object.
	 * 
	 * @return the Offset of the pixel array in bytes.
	 */
	int getOffset() const;
};
