#pragma once

#include <memory>

#include "Core/Core.h"
#include "Core/Window.h"
#include "Core/LayerStack.h"
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
        void OnEvent(Event &e);

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);

        inline static Application& Get() { return *s_Instance; }
        inline Window &GetWindow() { return *m_Window; }

    private:
        bool OnWindowClose(WindowCloseEvent &e);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
        static Application *s_Instance;
    };

    Application *CreateApplication();
}