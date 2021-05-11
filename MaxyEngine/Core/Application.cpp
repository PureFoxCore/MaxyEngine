#include "mxpch.h"
#include "Core/Application.h"
#include "Core/Logger.h"

namespace Maxy
{
#define BIND_EVENT_FN(event) std::bind(&event, this, std::placeholders::_1)

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create(WindowProps(1280, 720, "Maxy Engine")));
        m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
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

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

        MAXY_CORE_TRACE("Window Event: {0}", e);
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }
}