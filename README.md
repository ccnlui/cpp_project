# Template for C++ projects

This is a template for starting a c++ project with common tools and libraries. Modify or remove the following as you see fit:
- c++20
- cmake
- clang-format


### Structure

```
$ tree .
.
├── build
├── CMakeLists.txt
├── include
├── README.md
└── src
    ├── CMakeLists.txt
    └── main.cpp
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
