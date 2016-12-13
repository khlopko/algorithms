cmake_minimum_required(VERSION 3.6)
project(AlgoritmsCPP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp graph/Model.cpp graph/Model.h graph/graph.cpp graph/graph.h)
add_executable(AlgoritmsCPP ${SOURCE_FILES})