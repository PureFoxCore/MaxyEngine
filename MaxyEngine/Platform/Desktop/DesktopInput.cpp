#include "mxpch.hpp"

#include "DesktopInput.hpp"
#include "Core/Application.hpp"

#include <GLFW/glfw3.h>

namespace Maxy
{
    Input *Input::s_Instance = new DesktopInput();

    bool DesktopInput::IsKeyPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool DesktopInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    std::pair<float, float> DesktopInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);

        return {(float)xPos, (float)yPos};
    }

    float DesktopInput::GetMouseXImpl()
    {
        return GetMousePositionImpl().first;
    }

    float DesktopInput::GetMouseYImpl()
    {
        return GetMousePositionImpl().second;
    }
}