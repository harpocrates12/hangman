cmake_minimum_required(VERSION 3.17.3)

project(Hangman VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(Hangman src/hangman.cpp src/result.cpp src/character.cpp)
