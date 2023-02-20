cmake_minimum_required(VERSION 3.5)
project(TestBot)
set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(GTest REQUIRED)

add_executable(AppMain AppMain.cpp)
target_link_libraries(AppMain ${CONAN_LIBS})

add_executable(UnitTests
    plugins/md5_plugin/test/TestMd5Case.cpp
)

target_link_libraries(UnitTests PRIVATE ${CONAN_LIBS})

enable_testing()
add_test(NAME UnitTests COMMAND UnitTests)
