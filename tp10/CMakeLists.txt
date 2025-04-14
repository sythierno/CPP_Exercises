cmake_minimum_required(VERSION 3.16)
project(tp10)

add_executable(tp10
    lib/image_lib.hpp
    lib/image_lib.hpp
    lib/stb_image_write.h
    lib/stb_image.h
    src/mandelbrot.cpp
    src/image.hpp
)
target_compile_features(tp10 PRIVATE cxx_std_17)

