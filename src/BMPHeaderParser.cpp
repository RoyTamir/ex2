#include <string>
using std::string;

#include "BMPHeaderParser.hpp"

BMPHeaderParser::BMPHeaderParser(string str) {
	this->_str = str;

	string sizeString = str.substr(LOCATION_OF_SIZE,
			LOCATION_OF_SIZE + NUM_BYTES_OF_SIZE_AND_OFFSET - 1);

	string offsetString = str.substr(LOCATION_OF_OFFSET,
			LOCATION_OF_OFFSET + NUM_BYTES_OF_SIZE_AND_OFFSET - 1);

	this->_size = stoi(sizeString);
	this->_offset = stoi(offsetString);
}

string BMPHeaderParser::getStr() const {
	return this->_str;
}

uint32_t BMPHeaderParser::getSize() const {
	return this->_size;
}

uint32_t BMPHeaderParser::getOffset() const {
	return this->_offset;
}
