cmake_minimum_required(VERSION 3.16)
project(TP10)

add_executable(tp10
    src/mandelbrot.cpp
    src/image.hpp
)
target_compile_features(tp10 PRIVATE cxx_std_17)

