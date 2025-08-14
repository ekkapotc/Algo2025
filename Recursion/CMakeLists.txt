cmake_minimum_required(VERSION 3.1)

project(Recursion CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(add add.cpp)

add_executable(factorial factorial.cpp)

add_executable(fibonacci fibonacci.cpp)
