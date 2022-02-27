# CMake & GoogleTest Quickstart
#
# Usage:
# $ cmake -S . -B build
# $ cmake --build build
# $ (cd build && ctest)
# 
# From Visual Studio Code: Ctrl+Shift+P > CMake: Configure, Build, Debug, Run Without Debugging, Run Tests...
#
# References:
# - [Get started with CMake Tools on Linux](https://code.visualstudio.com/docs/cpp/cmake-linux)
# - [GoogleTest Quickstart: Building with CMake](https://google.github.io/googletest/quickstart-cmake.html)
# - [Modern CMake - A Simple Example](https://cliutils.gitlab.io/modern-cmake/chapters/basics/example.html)

# Almost all CMake files should start with this
# You should always specify a range with the newest
# and oldest tested versions of CMake. This will ensure
# you pick up the best policies.
cmake_minimum_required(VERSION 3.14..3.22)

# This is your project statement. You should always list languages.
# Listing the version is nice here since it sets lots of useful variables.
project(
    CMakeExample
    VERSION 0.1.0
    LANGUAGES CXX
)

# If you set any CMAKE_ variables, that can go here.
# (But usually don't do this, except maybe for C++ standard)
# GoogleTest requires at least C++11.
set(CMAKE_CXX_STANDARD 17)

# Download GoogleTest dependency from GitHub.
include(FetchContent)
FetchContent_Declare(
    googletest
    # Update the hash often to point to the latest version.
    URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Declare a library.
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system.
add_library(
    MyLibrary
    SHARED
    max_value.h
    max_value.cc
)

# Declare a standalone binary (output name matches target name)...
add_executable(
    HelloWorld
    main.cpp
)
# ... and link it to our library.
target_link_libraries(
    HelloWorld
    PRIVATE
    MyLibrary
)

# Declare a C++ test binary...
add_executable(
    HelloTest
    hello_test.cc
)
# ... and link it to GoogleTest and our library.
target_link_libraries(
    HelloTest
    PRIVATE
    gtest_main
    MyLibrary
)

# Enable CMake's test runner to discover the tests included in the binary, using the GoogleTest CMake module.
include(GoogleTest)
gtest_discover_tests(HelloTest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
