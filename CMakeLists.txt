cmake_minimum_required(VERSION 3.20)
project(typo_checker)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

include_directories(src/include/)

file (GLOB_RECURSE SRC_FILES src/*.cc)
add_executable(typo_checker ${SRC_FILES})

install(TARGETS typo_checker DESTINATION bin)