#include "mxpch.hpp"

#include "VulkanContext.hpp"
#include "Core/Logger.hpp"

// TODO(PureFoxCore): Implement vulkan API
namespace Maxy
{
    VulkanContext::VulkanContext(GLFWwindow *windowHandle)
        : m_WindowHandle(windowHandle)
    {
        MAXY_CORE_ASSERT(windowHandle, "Window handle is null!");
    }

    VulkanContext::~VulkanContext()
    {
    }

    void VulkanContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        // TODO(PureFoxCore): Implement Vulkan
        // ? CreateInstance(); 
        // ? CreateDebugCallback(); 
        // ? CreateWindowSurface(); 
        // ? FindPhysicalDevice(); 
        // ? CheckSwapChainSupport(); 
        // ? FindQueueFamilies(); 
        // ? CreateLogicalDevice(); 
        // ? CreateSemaphores(); 
        // ? CreateCommandPool(); 
        // ? CreateVertexBuffer(); 
        // ? CreateUniformBuffer(); 
        // ? CreateSwapChain(); 
        // ? CreateRenderPass(); 
        // ? CreateImageViews(); 
        // ? CreateFramebuffers(); 
        // ? CreateGraphicsPipeline(); 
        // ? CreateDescriptorPool(); 
        // ? CreateDescriptorSet(); 
        // ? CreateCommandBuffers(); 
    }

    void VulkanContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }

    void VulkanContext::SetVSync(const bool state)
    {
    }

    void VulkanContext::ShutDown()
    {
    }
}