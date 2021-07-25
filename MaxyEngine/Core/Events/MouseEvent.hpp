#pragma once

#include "Core/Events/Event.hpp"
#include <sstream>

namespace Maxy
{
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y)
            : m_MouseX(x), m_MouseY(y) { }

        inline float GetX() const { return m_MouseX; }
        inline float GetY() const { return m_MouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse moved: [" << m_MouseX << ", " << m_MouseY << "]";
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_MouseX, m_MouseY;
    };

    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float offsetX, float offsetY)
            : m_OffsetX(offsetX), m_OffsetY(offsetY) { }
        
        inline float GetXOffset() const { return m_OffsetX; }
        inline float GetYOffset() const { return m_OffsetY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse scrolled: [" << m_OffsetX << ", " << m_OffsetY << "]";
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_OffsetX, m_OffsetY;
    };

    class MouseButonEvent : public Event
    {
    public:
        inline int GetMouseButton() const { return m_Button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        MouseButonEvent(int button)
            : m_Button(button) { }

        int m_Button;
    };

    class MouseButtonPressedEvent : public MouseButonEvent
    {
    public:
        MouseButtonPressedEvent(int button)
            : MouseButonEvent(button) { }

        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "Mouse button pressed: [" << m_Button << "]";
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::MouseButtonPressed)
    };

        class MouseButtonReleasedEvent : public MouseButonEvent
    {
    public:
        MouseButtonReleasedEvent(int button)
            : MouseButonEvent(button) { }

        std::string ToString() const override 
        {
            std::stringstream ss;
            ss << "Mouse button released: [" << m_Button << "]";
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::MouseButtonReleased)
    };
}