#include "file_reading.hpp"
#include "BMPHeaderParser.hpp"
#include "DIBHeaderParser.hpp"
#include <iostream>

using namespace std;

int main() {
    BMPHeaderParser header(readFileContent("lena-color.bmp").substr(0, 13));
    
    cout<<header.getSize()<<endl;
    cout<<header.getOffset()<<endl;

    DIBHeaderParser DIBheader(readFileContent("lena-color.bmp").substr(14, 53));

    cout<<DIBheader.getBitArrayWidth()<<endl;
    cout<<DIBheader.getBitArrayHeight()<<endl;
    cout<<DIBheader.getBitsPerPixel()<<endl;
    cout<<DIBheader.getNumColorsInColorPalette()<<endl;
	return 0;
}