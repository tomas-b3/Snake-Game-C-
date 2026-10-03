cmake_minimum_required(VERSION 3.20)

project(Game)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib CONFIG REQUIRED)

add_executable(Game
    src/main.cpp
)

target_link_libraries(Game PRIVATE raylib)