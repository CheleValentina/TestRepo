cmake_minimum_required(VERSION 3.30)
project(Lab2_v1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab2_v1 main.c pet.c MyList.c petstoreservice.c mysort.c)

# Enable Coverage Flags if using GCC or Clang

set(CMAKE_EXE_LINKER_FLAGS "--coverage")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

set(CMAKE_C_FLAGS "--coverage -O0 -g ${CMAKE_CXX_FLAGS}")
