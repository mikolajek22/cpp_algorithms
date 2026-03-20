cmake_minimum_required(VERSION 3.20)

project(cpp_alghoritms)

add_library(algorithms
            queue/src/queue.cpp
            stack/src/stack.cpp
)

target_include_directories(algorithms PUBLIC
                            ${CMAKE_CURRENT_SOURCE_DIR}/queue/inc
                            ${CMAKE_CURRENT_SOURCE_DIR}/stack/inc
)

target_compile_features(algorithms PUBLIC cxx_std_20)