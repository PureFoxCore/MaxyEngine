#pragma once

#include "Core/Input.h"

namespace Maxy
{
    class LinuxInput : public Input
    {
    protected:
        virtual bool IsKeyPressedImplementation(int keycode) override;

        virtual bool IsMouseButtonPressedImplementation(int button) override;
        virtual std::pair<float, float> GetMousePositionImplementation() override;
        virtual float GetMouseXImplementation() override;
        virtual float GetMouseYImplementation() override;
    };
}