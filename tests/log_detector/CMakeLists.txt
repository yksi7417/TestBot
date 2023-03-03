find_package(GTest REQUIRED)

enable_testing()

include_directories(../include)
  
set(test_sources log_detector_test.cpp log_config_store_test.cpp)

add_executable(log_detector_test ${test_sources})

target_link_libraries(log_detector_test PRIVATE  log_detector ${CONAN_LIBS} gtest)

add_test(log_detector_test ${CMAKE_BINARY_DIR}/bin/log_detector_test)

configure_file(log_pattern_config.csv ${CMAKE_BINARY_DIR}/bin/log_pattern_config.csv COPYONLY)

install(FILES ${CMAKE_BINARY_DIR}/log_pattern_config.csv DESTINATION release)
