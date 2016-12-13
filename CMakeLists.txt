cmake_minimum_required(VERSION 3.6)
project(AlgoritmsCPP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp graph/model.cpp graph/model.h graph/graph.cpp graph/graph.h sorting/sorting.h sorting/sorting.cpp nam/NMA.h nam/NMA.cpp nam/Substitution.h nam/Substitution.cpp post/Machine.h post/Machine.cpp enables.h)
add_executable(AlgoritmsCPP ${SOURCE_FILES})