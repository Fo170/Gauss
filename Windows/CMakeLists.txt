cmake_minimum_required(VERSION 3.16)
project(Gauss VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Gauss
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/Gauss.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/Type.h
)

target_include_directories(Gauss PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)
