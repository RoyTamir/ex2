#include "file_reading.hpp"
#include "BMPHeaderParser.hpp"
#include "DIBHeaderParser.hpp"
#include "ColorTableParser.hpp"
#include "BMArrayParserToMatrixes.hpp"
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main() {
    try{
    cout<<"*****************lana (24 bits):*****************"<<endl;
    string lana = readFileContent("lena-color.bmp");

    BMPHeaderParser header(lana.substr(0, 14));
    
    cout<<header.getSize()<<endl;
    cout<<header.getOffset()<<endl;

    DIBHeaderParser DIBheader(lana.substr(14, 40));
    cout<<DIBheader.getBitArrayWidth()<<endl;
    cout<<DIBheader.getBitArrayHeight()<<endl;
    cout<<DIBheader.getBitsPerPixel()<<endl;
    cout<<DIBheader.getNumColorsInColorPalette()<<endl;

    BMArrayParserToMatrixes bitMatrix(lana.substr(header.getOffset(), lana.length()),
     DIBheader.getBitArrayWidth(), DIBheader.getBitArrayHeight());
    cout<<"color:"<<bitMatrix.getBitMapR()(0, 0)<<"r,"<<bitMatrix.getBitMapG()(0, 0)
    <<"g,"<<bitMatrix.getBitMapB()(0, 0)<<"b"<<endl;

    cout<<"*****************image (8 bits):*****************"<<endl;

    string image = readFileContent("image.bmp");

    header = BMPHeaderParser(image.substr(0, 14));
    
    cout<<header.getSize()<<endl;
    cout<<header.getOffset()<<endl;

    DIBheader = DIBHeaderParser(image.substr(14, 40));
    cout<<DIBheader.getBitArrayWidth()<<endl;
    cout<<DIBheader.getBitArrayHeight()<<endl;
    cout<<DIBheader.getBitsPerPixel()<<endl;
    cout<<DIBheader.getNumColorsInColorPalette()<<endl;

    ColorTableParser colorTable(image.substr(54, 1024));//2^8*4=1024

    cout<<"color:"<<colorTable.getColor(2).getR()<<"r,"<<colorTable.getColor(2).getG()
    <<"g,"<<colorTable.getColor(5).getB()<<"b"<<endl;
    }catch(const ErrorCodeException& e) {
        e.printErrorMessage();
    }
	return 0;
}