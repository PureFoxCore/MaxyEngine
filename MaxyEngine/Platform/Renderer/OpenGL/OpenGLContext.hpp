#pragma once

#include "Core/Renderer/Context.hpp"

#include <GLFW/glfw3.h>

namespace Maxy
{
    class OpenGLContext : public Renderer::Context
    {
    public:
        OpenGLContext(GLFWwindow *windowHandle);
        ~OpenGLContext();

        void Init() override;
        void SwapBuffers() override;
        void SetVSync(const bool state) override;
        void ShutDown() override {};

    private:
        GLFWwindow *m_WindowHandle;
    };
}