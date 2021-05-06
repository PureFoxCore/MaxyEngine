#pragma once

#include <memory>
#include "Core/Core.h"
#include "Core/Window.h"

namespace Maxy
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    Application* CreateApplication();
}