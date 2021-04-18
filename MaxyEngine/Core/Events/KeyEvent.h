#pragma once

#include "Core/Events/Event.h"
#include <sstream>

namespace Maxy
{
    class KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keycode)
            : m_KeyCode(keycode) { }
        int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) { }

        inline int GetRepeatCount() const { return m_RepeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Key pressed: [" << m_KeyCode << "] with repeats: [" << m_RepeatCount << "]";
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::KeyPressed)
    private:
        int m_RepeatCount;
    };

        class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode) { }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Key released: [" << m_KeyCode << "]";
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::KeyReleased)
    };
}