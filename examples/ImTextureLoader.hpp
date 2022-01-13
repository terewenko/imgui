#pragma once
#include <imgui.h>

ImTextureID LoadTextureFromFile(const char* filename);

ImTextureID LoadTextureFromMemory(unsigned char* data, int width, int height, int channels);

void FreeTexture(ImTextureID texture);

ImVec2 TextureSize(ImTextureID texture);
