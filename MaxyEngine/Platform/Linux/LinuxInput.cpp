#include "mxpch.h"

#include "Platform/Linux/LinuxInput.h"
#include "Core/Application.h"

#include <GLFW/glfw3.h>

namespace Maxy
{
#ifdef MAXY_PLATFORM_LINUX
    Input *Input::s_Instance = new LinuxInput();
#endif

    bool LinuxInput::IsKeyPressedImplementation(int keycode)
    {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool LinuxInput::IsMouseButtonPressedImplementation(int button)
    {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    std::pair<float, float> LinuxInput::GetMousePositionImplementation()
    {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);

        return {(float)xPos, (float)yPos};
    }

    float LinuxInput::GetMouseXImplementation()
    {
        auto [x, y] = GetMousePositionImplementation();
        return x;
    }

    float LinuxInput::GetMouseYImplementation()
    {
        auto [x, y] = GetMousePositionImplementation();
        return y;
    }
}