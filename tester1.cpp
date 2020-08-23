#include <iostream>
#include "MatrixClass.hpp"

using namespace std;

int main() {
    try{
    MatrixClass* mc = new MatrixClass(10, 10);
    cout<<mc->getHeight()<<endl;
    }catch(const ErrorCodeException& e){
        e.printErrorMessage();
    }
    return 0;
}
