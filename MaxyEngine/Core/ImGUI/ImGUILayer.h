#pragma once

#include "imgui.h"
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
    };
}