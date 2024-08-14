# Template for C++ projects

This is a template for starting a c++ project with common tools and libraries. Modify or remove the following as you see fit:
- c++20
- cmake
- clang-format
- [doctest](https://github.com/doctest/doctest) (header library)


### Structure

```
$ tree -L 2
.
├── build
├── CMakeLists.txt
├── include
│   └── doctest
├── README.md
└── src
    ├── CMakeLists.txt
    ├── main.cpp
    └── main_doctest.cpp
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
