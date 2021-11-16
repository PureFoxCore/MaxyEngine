#pragma once

#include <imgui.h>

namespace Maxy
{
    class Performance
    {
    public:
        inline static void OnImGUIRender(bool &open)
        {
            if (open == false)
                return;

            ImGui::Begin("Performance", &open);
            ImGui::End();
        }
    };
}