cmake_minimum_required(VERSION 3.6)
project(M2_TScopedPtr)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp TScopedPtr.h)
add_executable(M2_TScopedPtr ${SOURCE_FILES})