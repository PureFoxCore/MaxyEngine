#pragma once

#include "Core/Window.hpp"

#include "Platform/Renderer/OpenGL/OpenGLContext.hpp"

namespace Maxy
{
    class DesktopWindow : public Window
    {
    public:
        DesktopWindow(const WindowProps &props);
        virtual ~DesktopWindow();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }

        inline void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool state) override;
        bool IsVSync() const override;

        inline virtual void *GetNativeWindow() const override { return m_Window; }

    private:
        virtual void Init(const WindowProps &props);
        virtual void Shutdown();

    private:
        GLFWwindow *m_Window;

        Renderer::Context *m_Context;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
}