#include "BMPHeaderParser.hpp"

using namespace BMPClasses;
using std::cout;
using std::endl;
using std::string;
using std::uint32_t;

BMPHeaderParser::BMPHeaderParser(const string& str) {
	this->m_str = str;

	if(str[0] != 'B' && str[1] != 'M'){
		cout<<"Error: BMPHeaderParser Constructor: This isn't a BMP file"<<endl;
	}

	uint32_t* size = (uint32_t*) str.substr(LOCATION_OF_SIZE,
			NUM_BYTES_OF_SIZE_AND_OFFSET).data();

	uint32_t* offset = (uint32_t*) str.substr(LOCATION_OF_OFFSET,
			NUM_BYTES_OF_SIZE_AND_OFFSET).data();

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
