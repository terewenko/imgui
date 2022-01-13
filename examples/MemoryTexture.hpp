#pragma once
#include <cstdint>

struct MemoryTexture
{
    uint32_t* pixels = nullptr;
    size_t width = 0;
    size_t height = 0;
};
