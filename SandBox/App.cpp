#include <Maxy.hpp>
#include <sstream>

class ExampleLayer : public Maxy::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnImGUIRender() override
    {
        ImGui::Begin("Read file");
        static char InputPath[128];
        static std::string inputText;
        ImGui::InputText("File path", InputPath, 128);
        if (ImGui::Button("Go", ImVec2(120, 20)))
        {
            inputText.clear();
            inputText = Maxy::FileSystem::ReadFile(InputPath);
        }
        ImGui::Text("%s", inputText.c_str());
        ImGui::End();

        ImGui::Begin("Read binary file");
        static char inputBinPath[128];
        static std::string inputBinText;
        ImGui::InputText("File path", inputBinPath, 128);
        if (ImGui::Button("Go", ImVec2(120, 20)))
        {
            inputBinText.clear();
            inputBinText = Maxy::FileSystem::ReadBinaryFile(inputBinPath);
        }
        ImGui::Text("%s", inputBinText.c_str());
        ImGui::End();

        ImGui::Begin("Write file");
        static char outputPath[128];
        static char outputText[512];
        ImGui::InputText("File path", outputPath, 128);
        ImGui::InputText("Content", outputText, 512);
        if (ImGui::Button("Go", ImVec2(120, 20)))
        {
            Maxy::FileSystem::WriteFile(outputPath, outputText);
        }
        ImGui::End();

        ImGui::Begin("Write binary file");
        static char outputBinPath[128];
        static char outputBinText[512];
        ImGui::InputText("File path", outputBinPath, 128);
        ImGui::InputText("Content", outputBinText, 512);
        if (ImGui::Button("Go", ImVec2(120, 20)))
        {
            Maxy::FileSystem::WriteBinaryFile(outputBinPath, outputBinText);
        }
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