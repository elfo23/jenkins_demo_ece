ADD_EXECUTABLE(
  run-tests

  circular_buffer_tests.c
)

target_link_libraries(
  run-tests

  PUBLIC

  unity_test
  circular_buffer
)
