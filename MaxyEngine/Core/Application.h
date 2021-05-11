#pragma once

#include <memory>
#include "Core/Core.h"
#include "Core/Window.h"
#include "Core/Events/Event.h"
#include "Core/Events/ApplicationEvent.h"

namespace Maxy
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& e);
    private:
        bool OnWindowClose(WindowCloseEvent& e);
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    Application* CreateApplication();
}