#include "mxpch.hpp"

#include "Core/Logger.hpp"
#include "Core/Application.hpp"
#include "Core/ImGUI/ImGUILayer.hpp"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "Core/Input.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Maxy
{
    ImGUILayer::ImGUILayer()
        : Layer("ImGUILayer")
    {
    }

    ImGUILayer::~ImGUILayer()
    {
    }

    void SetCustomImGUIStyle()
    {
        ImGuiStyle &style = ImGui::GetStyle();

        // Rounding
        style.WindowRounding = 8.0f;
        style.ChildRounding = 0.0f;
        style.PopupRounding = 8.0f;
        style.FrameRounding = 4.0f;
        style.TabRounding = 5.0f;
        style.GrabRounding = 3.0f;
        style.ScrollbarRounding = 3.0f;

        // Colors
        style.Colors[ImGuiCol_Text] = ImVec4(1.000f, 1.000f, 1.000f, 1.000f);
        style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.500f, 0.500f, 0.500f, 1.000f);

        style.Colors[ImGuiCol_WindowBg] = ImVec4(0.078f, 0.078f, 0.078f, 1.000f);
        style.Colors[ImGuiCol_ChildBg] = ImVec4(0.078f, 0.078f, 0.078f, 1.000f);
        style.Colors[ImGuiCol_PopupBg] = ImVec4(0.055f, 0.055f, 0.071f, 1.000f);

        style.Colors[ImGuiCol_Border] = ImVec4(1.000f, 1.000f, 1.000f, 0.314f);
        style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.000f, 0.000f, 0.000f, 0.000f);

        style.Colors[ImGuiCol_FrameBg] = ImVec4(1.000f, 1.000f, 1.000f, 0.137f);
        style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.235f);
        style.Colors[ImGuiCol_FrameBgActive] = ImVec4(1.000f, 1.000f, 0.996f, 0.314f);

        style.Colors[ImGuiCol_TitleBg] = ImVec4(0.118f, 0.118f, 0.118f, 1.000f);
        style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.157f, 0.157f, 0.157f, 1.000f);
        style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.118f, 0.118f, 0.118f, 1.000f);

        style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.118f, 0.118f, 0.118f, 1.000f);

        style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.000f);
        style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(1.000f, 0.933f, 1.000f, 0.392f);
        style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.510f);
        style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.000f, 1.000f, 1.000f, 0.647f);

        style.Colors[ImGuiCol_CheckMark] = ImVec4(1.000f, 1.000f, 1.000f, 0.784f);

        style.Colors[ImGuiCol_SliderGrab] = ImVec4(1.000f, 1.000f, 1.000f, 0.314f);
        style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(1.000f, 1.000f, 1.000f, 0.706f);

        style.Colors[ImGuiCol_Button] = ImVec4(1.000f, 1.000f, 1.000f, 0.137f);
        style.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.000f, 0.980f, 0.980f, 0.235f);
        style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.000f, 1.000f, 1.000f, 0.314f);

        style.Colors[ImGuiCol_Header] = ImVec4(1.000f, 1.000f, 1.000f, 0.137f);
        style.Colors[ImGuiCol_HeaderHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.196f);
        style.Colors[ImGuiCol_HeaderActive] = ImVec4(1.000f, 1.000f, 0.996f, 0.314f);

        style.Colors[ImGuiCol_Separator] = ImVec4(1.000f, 1.000f, 1.000f, 0.196f);
        style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.588f);
        style.Colors[ImGuiCol_SeparatorActive] = ImVec4(1.000f, 1.000f, 1.000f, 1.000f);

        style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.000f, 1.000f, 1.000f, 0.196f);
        style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.392f);
        style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.000f, 1.000f, 1.000f, 0.588f);

        style.Colors[ImGuiCol_Tab] = ImVec4(1.000f, 1.000f, 1.000f, 0.118f);
        style.Colors[ImGuiCol_TabHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.235f);
        style.Colors[ImGuiCol_TabActive] = ImVec4(1.000f, 1.000f, 1.000f, 0.196f);
        style.Colors[ImGuiCol_TabUnfocused] = ImVec4(1.000f, 1.000f, 1.000f, 0.118f);
        style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(1.000f, 1.000f, 1.000f, 0.196f);

        style.Colors[ImGuiCol_DockingPreview] = ImVec4(1.000f, 1.000f, 1.000f, 0.588f);
        style.Colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.392f);

        style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.510f);

        style.Colors[ImGuiCol_NavHighlight] = ImVec4(1.000f, 1.000f, 1.000f, 0.588f);

        style.Colors[ImGuiCol_PlotLines] = ImVec4(1.000f, 0.773f, 0.451f, 1.000f);
        style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.000f, 0.380f, 0.380f, 1.000f);
        style.Colors[ImGuiCol_PlotHistogram] = ImVec4(1.000f, 0.773f, 0.451f, 1.000f);
        style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.000f, 0.380f, 0.380f, 1.000f);
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

        ImGui::StyleColorsDark();

        SetCustomImGUIStyle();

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
        static bool state = true;
        ImGui::ShowDemoWindow(&state);
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