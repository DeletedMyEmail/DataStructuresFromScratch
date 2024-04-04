cmake_minimum_required(VERSION 3.26)
project(DataStructuresFromScratch C)

set(CMAKE_C_STANDARD 17)

# add all source files to executable
file(GLOB_RECURSE SRC_FILES src/*.c includes/*.h)

add_executable(DataStructuresFromScratch ${SRC_FILES})