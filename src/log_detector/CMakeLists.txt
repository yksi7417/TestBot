include_directories(../../include)
add_library(log_detector log_detector.cpp log_context.cpp)
target_include_directories(log_detector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CONAN_LIBS})
