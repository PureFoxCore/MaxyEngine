#include "mxpch.h"
#include "Core/Application.h"

namespace Maxy
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create(WindowProps(1280, 720, "Maxy Engine")));
    }
    
    Application::~Application()
    {

    }

    void Application::Run()
    {
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }
}