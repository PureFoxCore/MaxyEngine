#include "mxpch.hpp"

#include "Core/Logger.hpp"
#include "Core/Application.hpp"
#include "Core/ImGUI/ImGUILayer.hpp"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "Core/Input.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "UI/Style.h"
#include "UI/Profiler.h"

namespace Maxy
{
    ImGUILayer::ImGUILayer()
        : Layer("ImGUILayer")
    {
    }

    ImGUILayer::~ImGUILayer()
    {
    }

    void ImGUILayer::OnAttach()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        ImGuiIO &io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_::ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_::ImGuiConfigFlags_NavEnableGamepad;
        io.ConfigFlags |= ImGuiConfigFlags_::ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_::ImGuiConfigFlags_ViewportsEnable;
        io.BackendFlags |= ImGuiBackendFlags_::ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_::ImGuiBackendFlags_HasSetMousePos;

        // ImGui::StyleColorsDark();
        Style::SetCustomImGUIStyle();

        Application &app = Application::Get();
        GLFWwindow *window = static_cast<GLFWwindow *>(app.GetWindow().GetNativeWindow());

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 130");
    }

    void ImGUILayer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGUILayer::OnImGUIRender()
    {
#ifdef MAXY_EDITOR
        if (ImGui::BeginMainMenuBar())
        {
            ImGui::MenuItem("Maxy", nullptr, false, false);

            if (ImGui::BeginMenu("Window"))
            {
                ImGui::MenuItem("Performance", "", &m_PerformanceWindowOpen);
                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();
        }
        
        Performance::OnImGUIRender(m_PerformanceWindowOpen);
#endif
    }

    void ImGUILayer::Begin()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGUILayer::End()
    {
        ImGuiIO &io = ImGui::GetIO();
        Application &app = Application::Get();

        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_::ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }
}