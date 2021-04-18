#pragma once

#include "Core/Core.h"

namespace Maxy
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    private:
        
    };

    Application* CreateApplication();
}