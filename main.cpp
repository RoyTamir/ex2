#include "bmp_tester.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout<<"testing 1279x959-8.bmp..."<<endl;
    testing::bmp::rotate_image("tester/1279x959-8.bmp",
    "result/1279x959-8-rotate.bmp");


    testing::bmp::convert_to_grayscale("tester/1279x959-8.bmp",
    "result/1279x959-8-gray.bmp");

    cout<<"testing 1280x960-8.bmp..."<<endl;
        testing::bmp::rotate_image("tester/1280x960-8.bmp",
    "result/1280x960-8-rotate.bmp");


    testing::bmp::convert_to_grayscale("tester/1280x960-8.bmp",
    "result/1280x960-8-gray.bmp");

    cout<<"testing lena.bmp..."<<endl;
        testing::bmp::rotate_image("tester/lena.bmp",
    "result/lena-rotate.bmp");


    testing::bmp::convert_to_grayscale("tester/lena.bmp",
    "result/lena-gray.bmp");

    cout<<"testing lena-color.bmp..."<<endl;
        testing::bmp::rotate_image("tester/lena-color.bmp",
    "result/lena-color-rotate.bmp");


    testing::bmp::convert_to_grayscale("tester/lena-color.bmp",
    "result/lena-color-gray.bmp");

    cout<<"testing no-image.bmp..."<<endl;
    testing::bmp::rotate_image("tester/no-image.bmp",
    "result/no-image-rotate.bmp");

    testing::bmp::convert_to_grayscale("tester/no-image.bmp",
    "result/no-image-gray.bmp");

    cout<<"testing lena.txt..."<<endl;
        testing::bmp::rotate_image("tester/lena.txt",
    "result/lena-text-rotate.bmp");

    testing::bmp::convert_to_grayscale("tester/lena.txt",
    "result/lena-text-gray.bmp");

    cout<<"finished test"<<endl;
    return 0;
}
