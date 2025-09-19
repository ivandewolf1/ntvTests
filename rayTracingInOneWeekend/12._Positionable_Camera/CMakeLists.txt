cmake_minimum_required(VERSION 3.31)
project(ntvTest)

set(CMAKE_CXX_STANDARD 20)
include_directories(./../../../ntv/src/)
add_executable(ntvTest main.cpp)
