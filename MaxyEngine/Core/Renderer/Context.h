#pragma once

namespace Maxy
{
    namespace Renderer
    {
        class Context
        {
        public:
            virtual void Init() = 0;
            virtual void SwapBuffers() = 0;
        };
    }
}