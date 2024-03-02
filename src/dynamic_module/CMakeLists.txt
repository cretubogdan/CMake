cmake_minimum_required(VERSION 3.5.0)
project(math_dynamic_lib VERSION 0.1.0 LANGUAGES CXX)

add_library(math_dynamic_lib SHARED math_dynamic.cpp)

target_include_directories(math_dynamic_lib PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))

set(CMAKE_CXX_STANDARD 23)
