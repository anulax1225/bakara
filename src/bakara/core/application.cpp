#include "application.h"
#include "bakara/core/window.h"
#include "bakara/events/window_event.h"
#include "bakara/renderer/renderer.h"
#include "bakatools/logging/assert.h"
#include "bakara/events/dispacher.h"

namespace Bk {
    Application* Application::p_instance = nullptr;

    Application::Application(std::string title, u32 width, u32 height) 
    { 
        BK_CORE_MSG_ASSERT(p_instance == nullptr, "Application already exists, can not create two application.")
        Application::p_instance = this;

        h_window = std::unique_ptr<Window>(Window::CreateWindow(WindowProps(title, width, height)));
        h_window->SetEventCallback(BK_BIND_EVENT_FN(OnEvent));

        Renderer::Init();

        imgui_layer = new ImguiLayer();
        PushOverlay(imgui_layer);
    }

    Application::~Application() { }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        if (!dispatcher.dispatch<WindowCloseEvent>(BK_BIND_DISPACHER_FN(WindowCloseEvent, OnWindowClose)))
        {
            dispatcher.dispatch<WindowResizeEvent>(BK_BIND_DISPACHER_FN(WindowResizeEvent, OnWindowResize));
            for(auto it = p_layer_stack.ReverseBegin(); it != p_layer_stack.ReverseEnd(); it++)
            {
                (*it)->OnEvent(e);
            }
        }
    }

    void Application::Close()
    {
        p_running = false;
    }

    bool Application::OnWindowResize(WindowResizeEvent& e)
    {
        isMinimized = !e.GetWidth() && !e.GetHeight();
        Renderer::ResizeFrame(e.GetWidth(), e.GetHeight());
        return false;
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        Close();
        return true;
    }

    void Application::Run() 
    {
        while (p_running)
        {
            if (!isMinimized)
                for (Layer* layer : p_layer_stack)
                    layer->OnUpdate(h_window->GetTime());
                
            imgui_layer->Begin();
            for (Layer* layer : p_layer_stack)
                layer->ImguiRender();
            imgui_layer->End();
            h_window->OnUpdate();
        }
    }
}
