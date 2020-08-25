#include "file_reading.hpp"
#include "BMPHeaderParser.hpp"
#include "DIBHeaderParser.hpp"
#include "ColorTableParser.hpp"
#include "BMArrayParserToMatrixes.hpp"
#include "BMArrayWithColorPattle.hpp"
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

    BMArrayParserToMatrixes bitMatrix24(lana.substr(header.getOffset(), lana.length()),
     DIBheader.getBitArrayWidth(), DIBheader.getBitArrayHeight());
    cout<<"color:"<<bitMatrix24.getBitMapR()(0, 0)<<"r,"<<bitMatrix24.getBitMapG()(0, 0)
    <<"g,"<<bitMatrix24.getBitMapB()(0, 0)<<"b"<<endl;

    bitMatrix24.changeToGray();
    cout<<"color in gray:"<<bitMatrix24.getBitMapR()(0, 0)<<"r,"<<bitMatrix24.getBitMapG()(0, 0)
    <<"g,"<<bitMatrix24.getBitMapB()(0, 0)<<"b"<<endl;

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

    cout<<"color:"<<colorTable.getColor(255).getR()<<"r,"<<colorTable.getColor(255).getG()
    <<"g,"<<colorTable.getColor(255).getB()<<"b"<<endl;

    BMArrayWithColorPattle bitMatrix8(image.substr(header.getOffset(), image.length()),
     DIBheader.getBitArrayWidth(), DIBheader.getBitArrayHeight(), &colorTable);
    cout<<"colorIndex:"<<bitMatrix8.getBitMap()(bitMatrix8.getBitMap().getHeight() - 1, bitMatrix8.getBitMap().getWidth() - 1)<<endl;

    cout<<"color:"<<colorTable.getColor(bitMatrix8.getBitMap()(0,0)).getR()<<"r,"<<colorTable.getColor(bitMatrix8.getBitMap()(0,0)).getG()
    <<"g,"<<colorTable.getColor(bitMatrix8.getBitMap()(0,0)).getB()<<"b"<<endl;

     
    }catch(const ErrorCodeException& e) {
        e.printErrorMessage();
    }
	return 0;
}