#include <iostream>
#include "MatrixClass.hpp"

int main() {
    try{
    MatrixClass* mc = new MatrixClass(10, 10);
    cout<<mc->getHeight()<<endl;
    }catch(ErrorCodeException& e){
        e.printErrorMessage();
    }
    return 0;
}
