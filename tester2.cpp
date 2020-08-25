#include "file_reading.hpp"
#include "bmp_tester.hpp"
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main()
{
    //24 bits pixel
    testing::bmp::convert_to_grayscale("lena-color.bmp", "result.bmp");
    return 0;
}
