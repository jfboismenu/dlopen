cmake_minimum_required(VERSION 2.8.9)
project (hello)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello main.cpp)

add_library(english MODULE english.c)
add_library(francais MODULE francais.c)

# set_target_properties(english francais PROPERTIES ENABLE_EXPORTS true)