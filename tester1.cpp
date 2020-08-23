#include <iostream>
#include "MatrixClass.hpp"

using namespace std;

int main() {
    try{
    MatrixClass mc =MatrixClass(5, 5);
    mc.print();
    cout<<mc.getHeight()<<","<<mc.getWidth()<<endl;

    for(uint32_t row = 0; row < mc.getHeight(); ++row) {
        for(uint32_t col = 0; col < mc.getWidth(); ++col) {
            mc.setValue(row, col, row + col);
        }
    }

    MatrixClass copyMc = mc;
    cout<<endl<<"the matrix:";
    mc.print();
    cout<<endl<<"after mult";
    (mc * copyMc).print();
    cout<<endl<<"after add:";
    (mc + copyMc).print();
    cout<<endl<<"after mult (scalar)";
    (mc * 9).print();
    cout<<endl;
    }catch(const ErrorCodeException& e){
        e.printErrorMessage();
    }
    return 0;
}
