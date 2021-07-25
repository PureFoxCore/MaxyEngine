#pragma once

#include "Core/Events/Event.hpp"
#include "Core/WindowProps.hpp"

namespace Maxy
{
    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event &)>;

        virtual ~Window(){};

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
        virtual void SetVSync(bool state) = 0;
        virtual bool IsVSync() const = 0;

        virtual void *GetNativeWindow() const = 0;

        static Window *Create(const WindowProps &props);
    };
}