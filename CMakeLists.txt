
cmake_minimum_required(VERSION 3.0.0)
project(ex2 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror -Wnon-virtual-dtor -Wshadow)

# Add the libmatrix file to the include path - so that
#   we can include it as without explicitly specifying 
#   the files directory.
include_directories(${CMAKE_SOURCE_DIR}/src)
# Link directories - tells the linker to look for .so files
#   in these directories. We want libmatrix.so which is under 
#   the matrix directory. Note that a full path is required.
link_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB My_Source_Files src/*.cpp)
add_executable(ex2 tester1.cpp ${My_Source_Files})
target_link_libraries(ex2 matrix)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)



