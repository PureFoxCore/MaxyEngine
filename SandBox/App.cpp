#include <Maxy.h>

class ExampleLayer : public Maxy::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    // void OnUpdate() override
    // {
    // }

    // void OnImGUIRender() override
    // {
    // }

    // void OnEvent(Maxy::Event &event) override
    // {
    // }
};

class SandBox : public Maxy::Application
{
public:
    SandBox()
    {
        PushLayer(new ExampleLayer());
    }

    ~SandBox()
    {
    }
};

Maxy::Application *Maxy::CreateApplication()
{
    return new SandBox;
}