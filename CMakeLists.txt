cmake_minimum_required(VERSION 3.14)
project(CPP_ALGORITHMS)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

find_package(GTest REQUIRED)

add_executable(stack_test
  Tests/adt/stack_test.cpp
  Tests/adt/ll_stack_test.cpp
  Tests/adt/queue_test.cpp
  )

target_include_directories(stack_test PRIVATE Include)

target_link_libraries(stack_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(stack_test)