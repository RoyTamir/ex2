#include <iostream>
#include "MatrixClass.hpp"

using namespace std;

int main() {
    try{
    MatrixClass mc =MatrixClass(5, 5);

    cout<<mc.getHeight()<<","<<mc.getWidth()<<endl;

    for(uint32_t row = 0; row < mc.getHeight(); ++row) {
        for(uint32_t col = 0; col < mc.getWidth(); ++col) {
            mc.setValue(row, col, row + col);
        }
    }

    const MatrixClass copyMc = mc;
    cout<<endl<<"the matrix:"<<endl<<mc;
    cout<<endl<<"after mult"<<endl<<(mc *= copyMc);
    cout<<endl<<"after add:"<<endl<<(mc += copyMc);
    cout<<endl<<"after mult (scalar)"<<endl<<(mc *= 9);
    cout<<endl<<"after divide (scalar)"<<endl<<(mc /= 9);

    cout<<endl<<"after Minus "<<endl<<(mc -= copyMc);

    //check for the other operators
    mc = copyMc;
    cout<<endl<<"the matrix:"<<endl<<mc;
    cout<<endl<<"after mult"<<endl<<(mc * copyMc);
    cout<<endl<<"after add:"<<endl<<(mc + copyMc);
    cout<<endl<<"after mult (scalar)"<<endl<<(mc * 9);
    cout<<endl<<"after mult (scalar)"<<endl<<(mc * -9);
    cout<<endl<<"after divide (scalar)"<<endl<<(mc / 2);
    cout<<endl<<"after Minus "<<endl<<(mc - copyMc);
    //needs deleting memory... (lets the end of the program hendle it)
    }catch(const ErrorCodeException& e){
        e.printErrorMessage();
    }
    return 0;
}
