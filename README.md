# README for Split Array Project

## Project Overview
This project implements a solution for splitting an array into `k` non-empty continuous subarrays such that the largest sum among these subarrays is minimized. The main functionality is encapsulated in the `Solution` class, which provides methods to validate potential largest sums and to compute the optimal split.

## Files
- **CMakeLists.txt**: Configuration file for CMake, specifying the project settings and source files.
- **410.cpp**: Contains the implementation of the `Solution` class with methods for validating and splitting the array based on a target sum.

## Build Instructions
To build the project, follow these steps:
1. Navigate to the project directory:
   ```
   cd /Users/zeyuning/Desktop/Leetcode/github_cmake
   ```
2. Create a build directory:
   ```
   mkdir build
   cd build
   ```
3. Run CMake to configure the project:
   ```
   cmake ..
   ```
4. Compile the project:
   ```
   make
   ```

## Usage
After building the project, you can run the executable to test the functionality of the `Solution` class. You may modify the `410.cpp` file to include test cases or integrate it into a larger application as needed.

## License
This project is open-source and available for modification and distribution under the terms of the MIT License.