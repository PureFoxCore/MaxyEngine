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
        // auto[x, y] = Maxy::Input::GetMousePosition();
        // MAXY_INFO("{0}, {1}", x, y);
    }

    void OnEvent(Maxy::Event &event) override
    {
        // MAXY_TRACE("{0}", event);
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