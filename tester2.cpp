#include "file_reading.hpp"
#include "bmp_tester.hpp"
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main()
{
    //24 bits pixel
    testing::bmp::convert_to_grayscale("lena-color.bmp", "lana-gray.bmp");
    testing::bmp::rotate_image("lena-color.bmp", "lana-rotate.bmp");

    //8 bits pixel
    testing::bmp::convert_to_grayscale("image.bmp", "image-gray.bmp");
    testing::bmp::rotate_image("image.bmp", "image-rotate.bmp");
    return 0;
}
