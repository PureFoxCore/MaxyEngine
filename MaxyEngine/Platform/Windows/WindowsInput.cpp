#include "mxpch.h"

#include "Platform/Windows/WindowsInput.h"
#include "Core/Application.h"

#include <GLFW/glfw3.h>

namespace Maxy
{
#ifdef MAXY_PLATFORM_WINDOWS
    Input *Input::s_Instance = new WindowsInput();
#endif

    bool WindowsInput::IsKeyPressedImplementation(int keycode)
    {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::IsMouseButtonPressedImplementation(int button)
    {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    std::pair<float, float> WindowsInput::GetMousePositionImplementation()
    {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);

        return {(float)xPos, (float)yPos};
    }

    float WindowsInput::GetMouseXImplementation()
    {
        auto [x, y] = GetMousePositionImplementation();
        return x;
    }

    float WindowsInput::GetMouseYImplementation()
    {
        auto [x, y] = GetMousePositionImplementation();
        return y;
    }
}