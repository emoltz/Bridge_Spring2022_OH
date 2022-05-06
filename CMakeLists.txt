cmake_minimum_required(VERSION 3.22)
project(vscode_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(vscode_cpp
        helloworld.cpp)

add_executable(test test.cpp)
add_executable(May6 May6.cpp)