# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Homework3 VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directory for headers
include_directories(${CMAKE_SOURCE_DIR}/src)

# Addthe executable target
add_executable(Homework3_Carlo
    ${CMAKE_SOURCE_DIR}/src/MonteCarlo.cpp
    ${CMAKE_SOURCE_DIR}/src/carlotools.cpp
)

add_executable(Homework3_Salesman
    ${CMAKE_SOURCE_DIR}/src/TravelingSalesman.cpp
    ${CMAKE_SOURCE_DIR}/src/salesmantools.cpp
)

add_definitions(-DDATA_DIR="${CMAKE_SOURCE_DIR}/data/")
