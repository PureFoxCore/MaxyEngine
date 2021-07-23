#pragma once

#include <memory>

#include "Core/Core.h"
#include "Core/Window.h"
#include "Core/LayerStack.h"
#include "Core/Events/Event.h"
#include "Core/Renderer/Shader.h"
#include "Core/ImGUI/ImGUILayer.h"
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

        inline static Application &Get() { return *s_Instance; }
        inline Window &GetWindow() { return *m_Window; }

    private:
        bool OnWindowClose(WindowCloseEvent &e);

        unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
        std::unique_ptr<Shader> m_Shader;

        std::unique_ptr<Window> m_Window;
        ImGUILayer *m_ImGUILayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        static Application *s_Instance;
    };

    Application *CreateApplication();
}