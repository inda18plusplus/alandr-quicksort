cmake_minimum_required(VERSION 3.13)
project(QuickSort)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/out/)

include_directories(src)

add_executable(QuickSort        src/quickSort.cpp src/main.cpp)
add_executable(QuickSort_fastIO src/quickSort.cpp src/main_fastIO.cpp)
add_executable(timing           src/quickSort.cpp src/timing.cpp)