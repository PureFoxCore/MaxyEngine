#include "mxpch.h"

#include "Platform/Windows/WindowsWindow.h"
#include "Core/Logger.h"

namespace Maxy
{
    static bool isGLFWInitialized = false;

#ifdef MAXY_PLATFORM_WINDOWS
    Window* Window::Create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }
#endif

    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        Init(props);
    }
    
    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.GetTitle();
        m_Data.Width = props.GetWidth();
        m_Data.Height = props.GetHeight();
    
        MAXY_CORE_INFO("Creating windows [Title: {0}, Width: {1}, Height: {2}]", props.GetTitle(), props.GetWidth(), props.GetHeight());
    
        if (!isGLFWInitialized)
        {
            int success = glfwInit();
            MAXY_CORE_ASSERT(success, "Can't initialize GLFW!");
            isGLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)props.GetWidth(), (int)props.GetHeight(), props.GetTitle().c_str(), NULL, NULL);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool state)
    {
        if (state)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = state;
    }

    bool WindowsWindow::IsVSync() const
    {
        return m_Data.VSync;
    }
}