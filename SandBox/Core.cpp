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
        // MAXY_INFO("ExampleLayer::Update()");
    }

    void OnEvent(Maxy::Event &event) override
    {
        MAXY_TRACE("{0}", event);
    }
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