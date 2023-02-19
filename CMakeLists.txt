cmake_minimum_required(VERSION 2.8.12)
project(TestBot)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(AppMain AppMain.cpp)
target_link_libraries(AppMain ${CONAN_LIBS})
