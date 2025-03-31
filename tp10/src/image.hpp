#pragma once
#include <cstdint>
#include <array>
#include <algorithm>
#include <cassert>

template <typename P, size_t W, size_t H>
class Image
{

public:
    Image() = default;

    Image(const P& pixel){
        for (auto i = 0; i<H; i++) {
            std::fill_n(_image.at(i), W, pixel);
        }
    }

    Image(const std::function<P(size_t i, size_t j)>& function){
        for(auto h = 0; h < H; h++) {
            for(auto w = 0; w < W; w++) {
                _image[h][w] = function(h, w);
            }
        }
    }

    ~Image(){}

    P& operator()(size_t i, size_t j)
    {
        assert(j < W);
        assert(i < H);
        return _image[j][i];
    }

    const P& operator()(size_t i, size_t j) const
    { 
        assert(j < W);
        assert(i < H);
        return _image[j][i];
    }

    Image operator+(const Image& other) {
        auto result = Image<P,W,H>();
        for(auto h = 0; h < H; h++) {
            for(auto w = 0; w < W; w++) {
                result[h][w] = other._image[h][w] + _image[h][w];
            }
        }
    }

private:
    std::array<std::array<P, W>, H > _image{};
};
