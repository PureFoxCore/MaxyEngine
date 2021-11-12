#include <Maxy.hpp>

class ExampleLayer : public Maxy::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnImGUIRender() override
    {
        ImGui::Begin("GuiWindow");
        static char path[128];
        static std::string text;
        ImGui::InputText("File path", path, 128);
        if (ImGui::Button("Go", ImVec2(120, 20)))
        {
            text.clear();
            text = Maxy::FileSystem::ReadFile(path);
        }
        ImGui::Text("%s", text.c_str());

        ImGui::End();
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