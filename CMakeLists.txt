cmake_minimum_required(VERSION 3.29)
project(menedzer_zadan)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(menedzer_zadan
    funkcje.cpp
    funkcje.h
    main.cpp)
