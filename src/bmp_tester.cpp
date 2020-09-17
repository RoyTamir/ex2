#include "bmp_tester.hpp"

using namespace BMPClasses;
using std::string;
using std::make_unique;

void testing::bmp::rotate_image(const std::string& imagePath, const std::string& outputPath){
    string imageString = readFileContent(imagePath);
    auto bmpParser = make_unique<BMPParser>(imageString);
    bmpParser->rotateImage();
    writeFileContent(outputPath, bmpParser->getBMP());
}

void testing::bmp::convert_to_grayscale(const std::string& imagePath,
                        const std::string& outputPath){
    string imageString = readFileContent(imagePath);
    auto bmpParser = make_unique<BMPParser>(imageString);
    bmpParser->imageToGray();
    writeFileContent(outputPath, bmpParser->getBMP());
}