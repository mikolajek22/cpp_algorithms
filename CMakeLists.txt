cmake_minimum_required(VERSION 3.20)

project(cpp_alghoritms)

# add_library(algorithms
#             queue/src/queue.cpp
#             stack/src/stack.cpp
# )
add_library(algorithms INTERFACE)


target_include_directories(algorithms INTERFACE
                            ${CMAKE_CURRENT_SOURCE_DIR}/queue
                            ${CMAKE_CURRENT_SOURCE_DIR}/stack
)

target_compile_features(algorithms INTERFACE cxx_std_20)