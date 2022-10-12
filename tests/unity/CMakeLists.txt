add_library(
  unity_test STATIC 

  unity.h
  unity.cpp
)
target_include_directories(unity_test PUBLIC .)
