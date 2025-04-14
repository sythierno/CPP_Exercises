#pragma once
#include <cstddef>
#include <array>
#include <functional>

template<typename P, size_t W, size_t H>
class Image
{

public:
    Image() = default;

    Image(const P& pixel) {
        for (size_t i = 0; i < H; i++) {
            std::fill(_image.at(i), W, pixel);
        }
    }

    Image(const std::function<P(size_t i, size_t j)>& f) {
        for (size_t i = 0; i < H; i++) {
            for (size_t j = 0; j < W; j++) {
                _image[i][j] = f(i, j);
            }
        }
    }

    const P& operator()(size_t i, size_t j)const {
        return _image.at(j).at(i);
    }

    P& operator()(size_t i, size_t j) {
        return _image[j][i];
    }

    void operator+(const Image& other) {
        for (size_t i = 0; i < H; i++) {
            for (size_t j = 0; j < W; j++) {
                _image[i][j] += other._image[i][j];
            }
        }
    }

private:
    std::array<std::array<P, W>, H> _image;
    // size_t _W;
    // size_t _H;
};

