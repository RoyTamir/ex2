#include "file_reading.hpp"
#include "BMPHeaderParser.hpp"
#include "DIBHeaderParser.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string lana = readFileContent("lena-color.bmp");

    BMPHeaderParser header(lana.substr(0, 13));
    
    cout<<header.getSize()<<endl;
    cout<<header.getOffset()<<endl;

    DIBHeaderParser DIBheader(lana.substr(14, 53));

    cout<<DIBheader.getBitArrayWidth()<<endl;
    cout<<DIBheader.getBitArrayHeight()<<endl;
    cout<<DIBheader.getBitsPerPixel()<<endl;
    cout<<DIBheader.getNumColorsInColorPalette()<<endl;
	return 0;
}