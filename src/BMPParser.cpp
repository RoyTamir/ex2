#include "BMPParser.hpp"

using namespace BMPClasses;
using std::string;
using std::uint32_t;


using namespace std;

BMPParser::BMPParser(string str) {
    this->m_str = std::move(str);
    this->m_BHparser = std::make_shared<BMPHeaderParser>(this->m_str.substr(HEADER_LOCATION, HEADER_SIZE));
    this->m_DIBparser = std::make_shared<DIBHeaderParser>(this->m_str.substr(DIB_HEADER_LOCATION, DIB_HEADER_SIZE));

    uint32_t arrayOffset = this->m_BHparser->getOffset();
    if (this->m_DIBparser->getBitsPerPixel() == IMG_WITHOUT_COLOR_TABLE) { //if 24 bits per pixel
        
        this->m_BMAparser = std::make_shared<BMArrayParserToMatrixes>(this->m_str.substr(arrayOffset, this->m_str.length() - arrayOffset),
        this->m_DIBparser->getBitArrayWidth(), this->m_DIBparser->getBitArrayHeight());

    } else if (this->m_DIBparser->getBitsPerPixel() == IMG_WITH_COLOR_TABLE) {//if 8 bits per pixel
        this->m_CTparser = std::make_shared<ColorTableParser>(this->m_str.substr(COLOR_TABLE_LOCATION, COLOR_TABLE_SIZE));

        this->m_BMAColorparser = std::make_shared<BMArrayWithColorPattle>(this->m_str.substr(arrayOffset, this->m_str.length() - arrayOffset),
        this->m_DIBparser->getBitArrayWidth(), this->m_DIBparser->getBitArrayHeight(), this->m_CTparser);

    } else { 
        throw std::runtime_error("Error: BMPParser Constructor: the bits per pixel arn't 8 or 24");
    }
}

string BMPParser::getBMP() const {
    return this->m_str;
}

void BMPParser::imageToGray(){
    
    uint32_t arrayOffset = this->m_BHparser->getOffset();
    if (this->m_DIBparser->getBitsPerPixel() == IMG_WITHOUT_COLOR_TABLE) { //if 24 bits per pixel
        this->m_BMAparser->changeToGray();

        this->m_str.replace(arrayOffset, this->m_str.length() - arrayOffset, this->m_BMAparser->getStr());
    } else if (this->m_DIBparser->getBitsPerPixel() == IMG_WITH_COLOR_TABLE) {//if 8 bits per pixel
        this->m_BMAColorparser->changeToGray();

        this->m_str.replace(COLOR_TABLE_LOCATION, COLOR_TABLE_SIZE, this->m_CTparser->getStr());
    } else { 
        throw std::runtime_error("Error: BMPParser imageToGray: the bits per pixel arn't 8 or 24");
    }
}

void BMPParser::rotateImage() {
    uint32_t arrayOffset = this->m_BHparser->getOffset();
    this->m_DIBparser->switchHeightAndWidth();
    this->m_str.replace(DIB_HEADER_LOCATION, DIB_HEADER_SIZE, this->m_DIBparser->getStr());
    if (this->m_DIBparser->getBitsPerPixel() == IMG_WITHOUT_COLOR_TABLE) { //if 24 bits per pixel
        this->m_BMAparser->rotate();

        this->m_str.replace(arrayOffset, this->m_str.length() - arrayOffset, this->m_BMAparser->getStr());
    } else if (this->m_DIBparser->getBitsPerPixel() == IMG_WITH_COLOR_TABLE) {//if 8 bits per pixel
        this->m_BMAColorparser->rotate();

        this->m_str.replace(arrayOffset, this->m_str.length() - arrayOffset, this->m_BMAColorparser->getStr());
    } else {
        throw std::runtime_error("Error: BMPParser rotateImage: the bits per pixel arn't 8 or 24");
    }
}