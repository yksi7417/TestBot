include_directories(../../include)
add_library(md5_plugin md5.cpp)
target_include_directories(md5_plugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CONAN_LIBS})
