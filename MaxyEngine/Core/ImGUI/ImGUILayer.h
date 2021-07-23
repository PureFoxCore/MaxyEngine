#pragma once

#include <imgui.h>

#include "Core/Layer.h"
#include "Core/Events/Events.h"

namespace Maxy
{
    class ImGUILayer : public Layer
    {
    public:
        ImGUILayer();
        ~ImGUILayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGUIRender() override;

        void Begin();
        void End();

        inline ImVec4 GetBackgroundColor() const { return m_BackgroundColor; }

    private:
        ImVec4 m_BackgroundColor = ImVec4(0.184f, 0.184f, 0.184f, 1.000f);
        float m_Time;
    };
}