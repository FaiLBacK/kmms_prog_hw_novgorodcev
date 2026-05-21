cmake_minimum_required(VERSION 3.15)
project(MarioGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mario_game
    src/main.cpp
    src/game.cpp
    src/level.cpp
    src/player.cpp
    src/enemy.cpp
    src/renderer.cpp
)

target_include_directories(mario_game PRIVATE include)