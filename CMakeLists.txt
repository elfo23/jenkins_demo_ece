PROJECT(JENKINS_DEMO_ECE)

set(CMAKE_CXX_STANDARD 17)

# compiler options. (we only check for gcc)
if (${CMAKE_COMPILER_IS_GNUCC})
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3 -Wall -Werror")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3 -Wall -Werror")
endif()

add_subdirectory(source)
add_subdirectory(tests)