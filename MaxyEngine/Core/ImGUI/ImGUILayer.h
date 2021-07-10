#pragma once

#include "Core/Layer.h"

namespace Maxy
{
    class ImGUILayer : public Layer
    {
    public:
        ImGUILayer();
        ~ImGUILayer();

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event &event) override;

    private:
        float m_Time;
    };
}