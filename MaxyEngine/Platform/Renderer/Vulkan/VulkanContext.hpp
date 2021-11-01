#pragma once

#include "Core/Renderer/Context.hpp"

#include <GLFW/glfw3.h>

namespace Maxy
{
    class VulkanContext : public Renderer::Context
    {
    public:
        VulkanContext(GLFWwindow *windowHandle);
        ~VulkanContext();

        void Init() override;
        void SwapBuffers() override;
        void SetVSync(const bool state) override;
        void ShutDown() override;

    private:
        GLFWwindow *m_WindowHandle;
    };
}