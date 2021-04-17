#pragma once

#include "Core.h"

namespace Maxy
{
    namespace Core
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
}