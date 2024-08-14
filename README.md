# Template for C++ projects

This is a template for starting a c++ project with common tools and libraries. Modify or remove the following as you see fit:
- c++20
- cmake
- clang-format
- [Catch2 v2](https://github.com/catchorg/Catch2/tree/v2.x) (header library)
- [CLI11](https://github.com/CLIUtils/CLI11) (header library)
- [doctest](https://github.com/doctest/doctest) (header library)
- [googletest](https://github.com/google/googletest) (vendor library)


### Structure

```
$ tree -L 2
.
├── build
├── CMakeLists.txt
├── include
│   ├── Catch2
│   ├── CLI11
│   └── doctest
├── README.md
├── src
│   ├── CMakeLists.txt
│   ├── main_catch.cpp
│   ├── main.cpp
│   ├── main_doctest.cpp
│   └── main_gtest.cpp
└── vendor
    ├── googletest-1.15.2
    └── README.md
```

### Building

Create a build directory (e.g. `build/`), and run cmake and make to build target.

Example:

```shell
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=[Debug | Release]
make
./main
```
