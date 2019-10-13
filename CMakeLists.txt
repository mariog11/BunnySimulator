cmake_minimum_required(VERSION 3.12)
project(BunnySimulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(BunnySimulator main.cpp Headers/game.h Source/game.cpp Headers/Functions.h Source/Functions.cpp Headers/Enemy.h Source/Enemy.cpp Headers/BunnyWomb.h Source/BunnyWomb.cpp)