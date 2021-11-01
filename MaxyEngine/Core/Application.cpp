#include "mxpch.hpp"
#include "Core/Logger.hpp"
#include "Core/Application.hpp"

#include <glad/glad.h>

namespace Maxy
{
    Application *Application::s_Instance = nullptr;

    Application::Application()
    {
        MAXY_CORE_ASSERT(!s_Instance, "Application already exits!");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create(WindowProps(1280, 720, "Maxy Engine")));
        m_Window->SetEventCallback(MAXY_BIND_EVENT_FN(Application::OnEvent));
        // TODO(PureFoxCore): Make ImGUI layer removable
        m_ImGUILayer = new ImGUILayer();
        PushOverlay(m_ImGUILayer);

        glGenVertexArrays(1, &m_VertexArray);
        glBindVertexArray(m_VertexArray);

        glGenBuffers(1, &m_VertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

        float vertices[3 * 3] =
            {-0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f, 0.5f, 0.0f};

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

        glGenBuffers(1, &m_IndexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);

        unsigned int indices[3] = {0, 1, 2};
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // TODO(PureFoxCore): Load shaders
        std::string vertexSource = R"(
            #version 310 es

            layout(location = 0) in vec3 a_Position;

            void main()
            {
                gl_Position = vec4(a_Position, 1.0);
            }
        )";

        std::string fragmentSource = R"(
            #version 310 es

            #ifdef GL_ES
            precision mediump float;
            #endif

            layout(location = 0) out vec4 color;

            void main()
            {
                color = vec4(1.0, 0.2, 0.2, 1.0);
            }
        )";
        m_Shader.reset(new Shader(vertexSource, fragmentSource));
    }

    Application::~Application()
    {
    }

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *overlay)
    {
        m_LayerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }

    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            m_Shader->Bind();
            glBindVertexArray(m_VertexArray);
            glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

            for (Layer *layer : m_LayerStack)
                layer->OnUpdate();

            m_ImGUILayer->Begin();
            for (Layer *layer : m_LayerStack)
                layer->OnImGUIRender();
            m_ImGUILayer->End();

            m_Window->OnUpdate();
        }
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(MAXY_BIND_EVENT_FN(Application::OnWindowClose));

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            (*--it)->OnEvent(e);
            if (e.Handled)
                break;
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }
}