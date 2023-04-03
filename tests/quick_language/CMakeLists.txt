add_compile_options(/wd4996 /wd4267 /wd4244)

find_package(GTest REQUIRED)

enable_testing()
  
set(test_sources quick_language_test.cpp)

add_executable(quick_language_test ${test_sources})

target_link_libraries(quick_language_test PRIVATE ${CONAN_LIBS} gtest)

add_test(quick_language_test ${CMAKE_BINARY_DIR}/bin/quick_language_test)
