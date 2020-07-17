cmake_minimum_required(VERSION 3.16)
project(baseN)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(CMAKE_CXX_STANDARD 14)

add_executable(
        baseN
        include/baseN.h
        src/main.cpp
        src/baseN.cpp
)
