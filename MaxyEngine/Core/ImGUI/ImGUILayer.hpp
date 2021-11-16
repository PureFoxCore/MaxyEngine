#pragma once

#include "imgui.h"
#include "Core/Layer.hpp"
#include "Core/Events/Events.hpp"

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

    private:
        bool m_PerformanceWindowOpen = false;
    };
}