#pragma once

#include <fstream>
#include <iterator>
#include <string>

namespace BMPClasses {
    std::string readFileContent(const std::string& filePath);

    void writeFileContent(const std::string& filePath, const std::string& content);
}