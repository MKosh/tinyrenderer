cmake_minimum_required(VERSION 3.24)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

project(tinyrenderer LANGUAGES C CXX)

add_subdirectory(external)
add_subdirectory(src)
