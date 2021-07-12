#include "mxpch.h"

#include "Core/ImGUI/ImGUILayer.h"
#include "Platform/OpenGL/imguiOpenGL.h"
#include "Core/Application.h"

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

    void ImGUILayer::OnAttach()
    {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO &io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_::ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_::ImGuiBackendFlags_HasSetMousePos;

        io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
        io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
        io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
        io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
        io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
        io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
        io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
        io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
        io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
        io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
        io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
        io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
        io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
        io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
        io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
        io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
        io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
        io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
        io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

        ImGui_ImplOpenGL3_Init("#version 130");
    }

    void ImGUILayer::OnDetach()
    {
    }

    void ImGUILayer::OnUpdate()
    {
        ImGuiIO &io = ImGui::GetIO();

        Application &app = Application::Get();
        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);
        ImGui::EndFrame();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGUILayer::OnEvent(Event &event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<MouseButtonPressedEvent>(MAXY_BIND_EVENT_FN(ImGUILayer::OnMouseButtonPressedEvent));
        dispatcher.Dispatch<MouseButtonReleasedEvent>(MAXY_BIND_EVENT_FN(ImGUILayer::OnMouseButtonReleasedEvent));
        dispatcher.Dispatch<MouseMovedEvent>(MAXY_BIND_EVENT_FN(ImGUILayer::OnMouseMovedEvent));
        dispatcher.Dispatch<MouseScrolledEvent>(MAXY_BIND_EVENT_FN(ImGUILayer::OnMouseScrolledEvent));

        dispatcher.Dispatch<KeyPressedEvent>(MAXY_BIND_EVENT_FN(ImGUILayer::OnKeyPressedEvent));
        dispatcher.Dispatch<KeyReleasedEvent>(MAXY_BIND_EVENT_FN(ImGUILayer::OnKeyReleasedEvent));
        dispatcher.Dispatch<KeyTypedEvent>(MAXY_BIND_EVENT_FN(ImGUILayer::OnKeyTypedEvent));

        dispatcher.Dispatch<WindowResizeEvent>(MAXY_BIND_EVENT_FN(ImGUILayer::OnWindowResizeEvent));
    }

    bool ImGUILayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent &event)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[event.GetMouseButton()] = true;

        return false;
    }

    bool ImGUILayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &event)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[event.GetMouseButton()] = false;

        return false;
    }

    bool ImGUILayer::OnMouseMovedEvent(MouseMovedEvent &event)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.MousePos = ImVec2(event.GetX(), event.GetY());

        return false;
    }

    bool ImGUILayer::OnMouseScrolledEvent(MouseScrolledEvent &event)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseWheel += event.GetYOffset();
        io.MouseWheelH += event.GetXOffset();

        return false;
    }

    bool ImGUILayer::OnKeyPressedEvent(KeyPressedEvent &event)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.KeysDown[event.GetKeyCode()] = true;

        io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
        io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
        io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
        io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];

        return false;
    }

    bool ImGUILayer::OnKeyReleasedEvent(KeyReleasedEvent &event)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.KeysDown[event.GetKeyCode()] = false;

        return false;
    }

    bool ImGUILayer::OnKeyTypedEvent(KeyTypedEvent &event)
    {
        ImGuiIO &io = ImGui::GetIO();
        int keycode = event.GetKeyCode();
        
        if (keycode > 0 &&  keycode < 0x10000)
            io.AddInputCharacter((unsigned short)keycode);
        return false;
    }

    bool ImGUILayer::OnWindowResizeEvent(WindowResizeEvent &event)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.DisplaySize = ImVec2(event.GetWidth(), event.GetHeight());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

        glViewport(0, 0, event.GetWidth(), event.GetHeight());

        return false;
    }
}