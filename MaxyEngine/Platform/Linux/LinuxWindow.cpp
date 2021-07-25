#include "mxpch.hpp"

#include "Platform/Linux/LinuxWindow.hpp"
#include "Core/Events/Events.hpp"
#include "Core/Logger.hpp"

namespace Maxy
{
    static bool isGLFWInitialized = false;

#ifdef MAXY_PLATFORM_LINUX
    Window *Window::Create(const WindowProps &props)
    {
        return new LinuxWindow(props);
    }
#endif

    LinuxWindow::LinuxWindow(const WindowProps &props)
    {
        Init(props);
    }

    LinuxWindow::~LinuxWindow()
    {
        Shutdown();
    }

    void LinuxWindow::Init(const WindowProps &props)
    {
        m_Data.Title = props.GetTitle();
        m_Data.Width = props.GetWidth();
        m_Data.Height = props.GetHeight();

        MAXY_CORE_INFO("Creating window: [Title: {0}, Width: {1}, Height: {2}]", props.GetTitle(), props.GetWidth(), props.GetHeight());

        if (!isGLFWInitialized)
        {
            int success = glfwInit();
            MAXY_CORE_ASSERT(success, "Can't initialize GLFW!");

            glfwSetErrorCallback([](int errorCode, const char *description)
                                 { MAXY_CORE_ERROR("GLFW Error ({0}): {1}", errorCode, description); });

            isGLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)props.GetWidth(), (int)props.GetHeight(), props.GetTitle().c_str(), NULL, NULL);

        m_Context = new OpenGLContext(m_Window);
        m_Context->Init();

        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        // Set GLFW callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height)
                                  {
                                      WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                                      data.Width = width;
                                      data.Height = height;

                                      WindowResizeEvent event(width, height);
                                      data.EventCallback(event);
                                  });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window)
                                   {
                                       WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                                       WindowCloseEvent event;
                                       data.EventCallback(event);
                                   });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int modes)
                           {
                               WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

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

        glfwSetCharCallback(m_Window, [](GLFWwindow *window, unsigned int keycode)
                            {
                                WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                                KeyTypedEvent event(keycode);
                                data.EventCallback(event);
                            });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods)
                                   {
                                       WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

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

        glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xOffset, double yOffset)
                              {
                                  WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                                  MouseScrolledEvent event((float)xOffset, (float)yOffset);
                                  data.EventCallback(event);
                              });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double xPos, double yPos)
                                 {
                                     WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                                     MouseMovedEvent event((float)xPos, (float)yPos);
                                     data.EventCallback(event);
                                 });
    }

    void LinuxWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void LinuxWindow::OnUpdate()
    {
        glfwPollEvents();
        m_Context->SwapBuffers();
    }

    void LinuxWindow::SetVSync(bool state)
    {
        if (state)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = state;
    }

    bool LinuxWindow::IsVSync() const
    {
        return m_Data.VSync;
    }
}