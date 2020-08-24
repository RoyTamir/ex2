#include "file_reading.hpp"
#include "BMPHeaderParser.hpp"
#include "DIBHeaderParser.hpp"
#include "ColorTableParser.hpp"
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main() {
    string lana = readFileContent("image.bmp");

    BMPHeaderParser header(lana.substr(0, 14));
    
    cout<<header.getSize()<<endl;
    cout<<header.getOffset()<<endl;

    DIBHeaderParser DIBheader(lana.substr(14, 40));
    cout<<DIBheader.getBitArrayWidth()<<endl;
    cout<<DIBheader.getBitArrayHeight()<<endl;
    cout<<DIBheader.getBitsPerPixel()<<endl;
    cout<<DIBheader.getNumColorsInColorPalette()<<endl;

    ColorTableParser colorTable(lana.substr(54, 1024));//2^8*4=1024

    cout<<"color:"<<colorTable.getColor(2).getR()<<"r,"<<colorTable.getColor(2).getG()
    <<"g,"<<colorTable.getColor(5).getB()<<"b"<<endl;

	return 0;
}