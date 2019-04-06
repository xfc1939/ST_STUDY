cmake_minimum_required(VERSION 3.8)
project(ST_APP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Server.h src/Server.cpp define.h)
add_executable(ST_APP ${SOURCE_FILES})