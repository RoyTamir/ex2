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

    testing::bmp::convert_to_grayscale("image3.bmp", "image3-gray.bmp");
    testing::bmp::rotate_image("image3.bmp", "image3-rotate.bmp");
    //8 bits pixel
    testing::bmp::convert_to_grayscale("image.bmp", "image-gray.bmp");
    testing::bmp::rotate_image("image.bmp", "image-rotate.bmp");

    testing::bmp::convert_to_grayscale("image2.bmp", "image2-gray.bmp");
    testing::bmp::rotate_image("image2.bmp", "image2-rotate.bmp");
    return 0;
}
