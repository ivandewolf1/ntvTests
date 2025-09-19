cmake_minimum_required(VERSION 3.31)
project(ntvTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
include_directories(./../../../ntv/src/)
add_executable(ntvTest main.cpp)
