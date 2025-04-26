cmake_minimum_required(VERSION 3.10)

# Project name
project(LeetcodeSolutions)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable for 410.cpp
add_executable(split_array 410.cpp)

# Add executable for 797.cpp
add_executable(all_paths_source_target 797.cpp)

# Add executable for 17.cpp
add_executable(letter_combinations 17.cpp)