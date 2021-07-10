#include "mxpch.h"

#include "Platform/Windows/WindowsWindow.h"
#include "Core/Events/Events.h"
#include "Core/Logger.h"

#include <glad/glad.h>

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
    
        MAXY_CORE_INFO("Creating window: [Title: {0}, Width: {1}, Height: {2}]", props.GetTitle(), props.GetWidth(), props.GetHeight());
    
        if (!isGLFWInitialized)
        {
            int success = glfwInit();
            MAXY_CORE_ASSERT(success, "Can't initialize GLFW!");

            glfwSetErrorCallback([](int errorCode, const char* description)
            {
                MAXY_CORE_ERROR("GLFW Error ({0}): {1}", errorCode, description);
            });

            isGLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)props.GetWidth(), (int)props.GetHeight(), props.GetTitle().c_str(), NULL, NULL);
        glfwMakeContextCurrent(m_Window);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        MAXY_CORE_ASSERT(status, "Failed to initialize GLAD!");
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        // Set GLFW callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int modes)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            
            if (action == GLFW_PRESS)
            {
                KeyPressedEvent event(key, 0);
                data.EventCallback(event);
            }
            else if (action == GLFW_RELEASE)
            {
                KeyReleasedEvent event(key);
                data.EventCallback(event);                
            }
            else if (action == GLFW_REPEAT)
            {
                KeyPressedEvent event(key, 1);
                data.EventCallback(event);                
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            if (action == GLFW_PRESS)
            {
                MouseButtonPressedEvent event(button);
                data.EventCallback(event);
            }
            else if (action == GLFW_RELEASE)
            {
                MouseButtonReleasedEvent event(button);
                data.EventCallback(event);
            }
        });
    
        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseMovedEvent event((float)xPos, (float)yPos);
            data.EventCallback(event);
        });
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