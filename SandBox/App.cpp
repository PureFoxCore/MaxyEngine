#include <Maxy.h>

class ExampleLayer : public Maxy::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override
    {
    }

    void OnEvent(Maxy::Event &event) override
    {
        if (event.GetEventType() == Maxy::EventType::KeyPressed)
        {
            Maxy::KeyPressedEvent e = (Maxy::KeyPressedEvent &)event;
            MAXY_TRACE("{0}", (char)e.GetKeyCode());
        }
    }
};

class SandBox : public Maxy::Application
{
public:
    SandBox()
    {
        PushLayer(new ExampleLayer());
        PushLayer(new Maxy::ImGUILayer());
    }

    ~SandBox()
    {
    }
};

Maxy::Application *Maxy::CreateApplication()
{
    return new SandBox;
}