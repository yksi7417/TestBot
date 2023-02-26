include_directories(../../include)
add_executable(AppMain AppMain.cpp)
target_link_libraries(AppMain md5_plugin ${CONAN_LIBS})
