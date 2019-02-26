cmake_minimum_required(VERSION 3.13)
project(sims)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_executable(sims main.cpp map_option.h ptl_option.h othertools.h mltrd.h)