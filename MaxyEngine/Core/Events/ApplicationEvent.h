#pragma once

#include "Core/Events/Event.h"
#include <sstream>

namespace Maxy
{
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(uint width, uint height) 
            : m_Width(width), m_Height(height) { }

        inline uint GetWidth() const { return m_Width; }
        inline uint GetHeight() const { return m_Height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Window resize: [" << m_Width << ", " << m_Height << "]";
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    private:
        uint m_Width, m_Height;
    };

    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() { }

        EVENT_CLASS_TYPE(EventType::WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AppTickEvent : public Event
    {
    public:
        AppTickEvent() { }

        EVENT_CLASS_TYPE(EventType::AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() { }

        EVENT_CLASS_TYPE(EventType::AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() { }

        EVENT_CLASS_TYPE(EventType::AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}
