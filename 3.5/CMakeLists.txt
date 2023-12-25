cmake_minimum_required(VERSION 3.26)
project(3_5)

set(CMAKE_CXX_STANDARD 17)

add_executable(3_5 main.cpp
        media.cpp
        media.h
        menuCommands.cpp
        menuCommands.h
        list.h
        list.cpp
        exceptions.cpp
        exceptions.h
)
