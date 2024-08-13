cmake_minimum_required(VERSION 3.21.0)
project(cpp_project VERSION 0.1.0 LANGUAGES C CXX)

# Use c++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# More compiler warnings
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

# Header Libraries
include_directories("include/CLI11")
include_directories("include/Catch2")

# Create executable
add_executable(main)

# Source
include_directories("src")
add_subdirectory("src")
