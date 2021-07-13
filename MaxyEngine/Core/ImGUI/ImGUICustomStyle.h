#pragma once

#include "imgui.h"

namespace Maxy
{
    class ImGUICustomStyle : public ImGuiStyle
    {
    public:
        ImGUICustomStyle(ImGuiStyle style)
            : m_Style(style)
        {
            m_Style.WindowRounding = 8.0f;
            m_Style.ChildRounding = 8.0f;
            m_Style.PopupRounding = 8.0f;
            m_Style.FrameRounding = 4.0f;
            m_Style.TabRounding = 5.0f;
            m_Style.GrabRounding = 3.0f;
            m_Style.ScrollbarRounding = 3.0f;
            m_Style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        inline const ImGuiStyle Get() const { return m_Style; }

    private:
        ImGuiStyle m_Style;
    };
}