cmake_minimum_required(VERSION 3.15)
project(dan2)

set(CMAKE_CXX_STANDARD 17)

add_executable(dan2 main.cpp bankint.h deposits.cpp assoc.cpp app.cpp mapx.cpp)