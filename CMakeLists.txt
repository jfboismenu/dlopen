cmake_minimum_required(VERSION 2.8.9)
project (hello)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello main.cpp)

add_library(python2 MODULE python.cpp)

target_include_directories(python2 PUBLIC "/Users/jfboismenu/.pyenv/versions/2.7.13/include/python2.7")
target_link_directories(python2 PUBLIC "/Users/jfboismenu/.pyenv/versions/2.7.13/lib")
target_link_libraries(python2 python2.7)


add_library(python3 MODULE python.cpp)

target_include_directories(python3 PUBLIC "/Users/jfboismenu/.pyenv/versions/3.7.3/include/python3.7m")
target_link_directories(python3 PUBLIC "/Users/jfboismenu/.pyenv/versions/3.7.3/lib")
target_link_libraries(python3 python3.7m)
