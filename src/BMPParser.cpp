#include "BMPParser.hpp"
#include "BitmapHeaderParser.cpp"
#include "DIBHeaderParser.cpp"
#include "ColorTableParser.cpp"
#include "BitmapArrayParser.cpp"
#include "Color.cpp"

#include <string>
using std::string;

BMPParser::BMPParser(string str) {
	this->_str = str;
	this->_BHparser = new BitmapHeaderParser(str.substr(0, 14));
	this->_DIBparser = new DIBHeaderParser(str.substr(14, 40));
	this->_CTparser = new ColorTableParser(this->_str.substr(54, this->_BHparser->getOffset()));
	this->_BMAparser = new BitMapArrayParser(this->_str.substr(this->_BHparser->getOffset(),
										 	 this->_str.size() - (this->_BHparser->getOffset())),
										 	 this->_DIBparser->getBitArrayWidth(), this->_DIBparser->getBitArrayHeight(),
											 this->_CTparser->getColors());
}

string BMPParser::getBMP() const {
	return this->_str;
}

int main() {
	BMPParser* parser = new BMPParser("bflcq,le,por.ewrap/riclhmulhmil,cmhoejrgruajekfnekfhnrlglkgj,rigjrimjcjfdfbjfhufhufbjanhcsn");
	return 0;
}
