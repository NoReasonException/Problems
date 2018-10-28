cmake_minimum_required(VERSION 3.10)
project(untitled1)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled1 main.cpp State/State.cpp State/State.h Table/Table.cpp Table/Table.h Table/ManhattanTable/ManhattanTable.cpp Table/ManhattanTable/ManhattanTable.h State/errors/AlreadyVisitedException.h)