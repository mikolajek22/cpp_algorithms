cmake_minimum_required(VERSION 3.14)
project(CPP_ALGORITHMS)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

find_package(GTest REQUIRED)

add_executable(adt_test
  Tests/adt/stack_test.cpp
  Tests/adt/ll_stack_test.cpp
  Tests/adt/queue_test.cpp
  Tests/adt/ring_queue_test.cpp
  Tests/adt/binaryTree_test.cpp
  )

add_executable(searching_test
  Tests/searching/linearSearch_test.cpp
)

add_executable(sorting_test
  Tests/sorting/bubbleSort_test.cpp
  Tests/sorting/selectionSort_test.cpp
  Tests/sorting/insertionSort_test.cpp
  Tests/sorting/mergeSort_test.cpp
)

target_include_directories(adt_test PRIVATE Include)
target_include_directories(searching_test PRIVATE Include)
target_include_directories(sorting_test PRIVATE Include)

target_link_libraries(adt_test GTest::gtest_main)
target_link_libraries(searching_test GTest::gtest_main)
target_link_libraries(sorting_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(adt_test)
gtest_discover_tests(searching_test)
gtest_discover_tests(sorting_test)