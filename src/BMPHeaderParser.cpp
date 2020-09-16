#include "BMPHeaderParser.hpp"

using namespace BMPClasses;
using std::string;
using std::uint32_t;

BMPHeaderParser::BMPHeaderParser(const string& str) {
	this->m_str = str;

	if(str[0] != 'B' && str[1] != 'M'){
		throw std::runtime_error("Error: BMPHeaderParser Constructor: This isn't a BMP file");
	}

	uint32_t* size = const_cast<uint32_t*>(reinterpret_cast<const uint32_t*>(str.substr(SIZE_LOCATION,
			BYTES_IN_SIZE).data()));

	uint32_t* offset = const_cast<uint32_t*>(reinterpret_cast<const uint32_t*>(str.substr(OFFSET_LOCATION,
			BYTES_IN_SIZE).data()));

	this->m_size = *size;
	this->m_offset = *offset;
}

const string& BMPHeaderParser::getStr() const {
	return this->m_str;
}

uint32_t BMPHeaderParser::getSize() const {
	return this->m_size;
}

uint32_t BMPHeaderParser::getOffset() const {
	return this->m_offset;
}
