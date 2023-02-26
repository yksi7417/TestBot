# Set up testing using CTest
enable_testing()

# Define a function to add tests for each plugin
function(add_plugin_tests plugin_name)
  # Add test sources for this plugin
  set(test_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/${plugin_name}/${plugin_name}_test.cpp
  )

  add_executable(${plugin_name}_test ${test_sources})

#   target_link_libraries(${plugin_name}_test ${plugin_name} common gtest)
  target_link_libraries(${plugin_name}_test PRIVATE ${CONAN_LIBS} gtest)

  # Add the test to CTest
  add_test(${plugin_name}_test ${CMAKE_BINARY_DIR}/bin/${plugin_name}_test)
endfunction()

# Add tests for each plugin
add_plugin_tests(md5_plugin)
