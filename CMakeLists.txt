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
include_directories("include/doctest")

# Google Test Library
add_subdirectory("vendor/googletest-1.15.2" "vendor/googletest-1.15.2")
mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)
set_target_properties(gtest PROPERTIES FOLDER vendor)
set_target_properties(gtest_main PROPERTIES FOLDER vendor)
set_target_properties(gmock PROPERTIES FOLDER vendor)
set_target_properties(gmock_main PROPERTIES FOLDER vendor)
macro(googletest_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} PRIVATE gtest PRIVATE gmock PRIVATE gtest_main)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

# Create executable
add_executable(main)

# Create catch2 executable
add_executable(main_catch)

# Create doctest executable
add_executable(main_doctest)

# Create gtest executable
googletest_add_test(main_gtest)

# Source
include_directories("src")
add_subdirectory("src")
