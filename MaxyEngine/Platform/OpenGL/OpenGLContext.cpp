#include "mxpch.hpp"

#include "Platform/OpenGL/OpenGLContext.hpp"
#include "Core/Logger.hpp"

#include <glad/glad.h>

namespace Maxy
{
    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle)
        : m_WindowHandle(windowHandle)
    {
        MAXY_CORE_ASSERT(windowHandle, "Window handle is null!");
    }

    OpenGLContext::~OpenGLContext()
    {
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        MAXY_CORE_ASSERT(status, "Failed to initialize GLAD!");
        
        MAXY_CORE_INFO("OpenGL Renderer: {0}", glGetString(GL_RENDERER));
        MAXY_CORE_INFO("OpenGL Version: {0}", glGetString(GL_VERSION));
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}