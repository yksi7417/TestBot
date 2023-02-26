cmake_minimum_required(VERSION 3.5)
project(TestBot)
set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(tests)
add_subdirectory(src)
