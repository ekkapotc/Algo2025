cmake_minimum_required(VERSION 3.1)

project(Measurement CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main-O0 main.cpp)
target_compile_options(main-O0 PRIVATE -O0)

add_executable(main-O3 main.cpp)
target_compile_options(main-O3 PRIVATE -O3)

add_executable(test test.cpp)
