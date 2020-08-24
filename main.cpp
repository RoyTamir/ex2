#include "file_reading.hpp"
#include "BMPHeaderParser.hpp"
#include <iostream>

using namespace std;

int main() {
    BMPHeaderParser header(readFileContent("lena-color.bmp"));
    
    cout<<header.getSize()<<endl;
    cout<<header.getOffset()<<endl;
	return 0;
}