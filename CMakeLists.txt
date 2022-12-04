cmake_minimum_required(VERSION 3.24)
project(projekt_pp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(projekt_pp
        main1.3.cpp
        fight_functions.h
        fight_functions.cpp
        )
