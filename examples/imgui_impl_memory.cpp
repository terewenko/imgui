// dear imgui: Platform Binding for Memory

// Implemented features:


#include "imgui.h"
#include "imgui_impl_memory.h"
#include "MemoryTexture.hpp"

// CHANGELOG
// (minor and older changes stripped away, please see git history for details)


// Memory Data
static MemoryTexture*       g_pTexture = nullptr;
static bool                 g_HasGamepad = false;
static bool                 g_WantUpdateHasGamepad = false;

// Functions
bool    ImGui_ImplMemory_Init(void* ptexture)
{
    // Setup back-end capabilities flags
    g_pTexture = reinterpret_cast<MemoryTexture*>(ptexture);
    ImGuiIO& io = ImGui::GetIO();
    io.BackendFlags |= ImGuiConfigFlags_NoMouseCursorChange;
    io.BackendPlatformName = "imgui_impl_memory";
    io.ImeWindowHandle = ptexture;

    return true;
}

void    ImGui_ImplMemory_Shutdown()
{
    g_pTexture = nullptr;
}

void    ImGui_ImplMemory_NewFrame()
{
    ImGuiIO& io = ImGui::GetIO();
    IM_ASSERT(io.Fonts->IsBuilt() && "Font atlas not built! It is generally built by the renderer back-end. Missing call to renderer _NewFrame() function? e.g. ImGui_ImplOpenGL3_NewFrame().");

    // Setup display size (every frame to accommodate for window resizing)
    io.DisplaySize = ImVec2((float)g_pTexture->width, (float)g_pTexture->height);

    // Setup time step
    io.DeltaTime = 1.0f;
}
