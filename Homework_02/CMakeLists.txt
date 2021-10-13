cmake_minimum_required(VERSION 3.20)
project(Homework_02)

set(CMAKE_CXX_STANDARD 17)
set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
        # Headers
        rnd.h
        regularmatrix.h
        trianglematrix.h
        diagonalmatrix.h
        Matrix.h
        Container.h

        # Sources
        regularmatrix.cpp
        trianglematrix.cpp
        diagonalmatrix.cpp
        Matrix.cpp
        Container.cpp
        main.cpp)

add_executable(Homework_02 ${SOURCE_FILES})
