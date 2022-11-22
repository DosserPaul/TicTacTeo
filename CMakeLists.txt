cmake_minimum_required(VERSION 3.0)

project(TicTacToe LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES Main.cpp src/*.cpp src/*.hpp)

# Valgrind
add_definitions(-g -lncurses)

add_executable(TicTacTeo ${SOURCES} ${HEADERS} src/IA/MiniMax.cpp src/IA/MiniMax.hpp)