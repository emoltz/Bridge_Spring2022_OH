cmake_minimum_required(VERSION 3.22)
project(vscode_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(vscode_cpp
        exampleArchive/helloworld.cpp)

add_executable(test exampleArchive/test.cpp)
add_executable(May6 exampleArchive/May6.cpp)
add_executable(practiceExam3 "Exam Review/practiceExam3.cpp")