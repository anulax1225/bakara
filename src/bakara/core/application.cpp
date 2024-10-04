#include "application.h"

namespace Bk {
    Application* Application::p_instance = nullptr;

    Application::Application() 
    { 
        BK_CORE_MSG_ASSERT(p_instance == nullptr, "Application already exists, can not create two application.")
        Application::p_instance = this;
        h_window = std::unique_ptr<Window>(Window::CreateWindow());
        imgui_layer = new ImguiLayer();
        PushOverlay(imgui_layer);
        h_window->SetEventCallback(BK_BIND_EVENT_FN(OnEvent));
        p_running = true;
    }

    Application::~Application() { }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<MouseButtonPressEvent>(BK_BIND_DISPACHER_FN(MouseButtonPressEvent, Mouse::ButtonCallback));
        dispatcher.dispatch<MouseButtonReleaseEvent>(BK_BIND_DISPACHER_FN(MouseButtonReleaseEvent, Mouse::ButtonCallback));
        dispatcher.dispatch<MouseScrollEvent>(BK_BIND_DISPACHER_FN(MouseScrollEvent, Mouse::WheelCallback));
        dispatcher.dispatch<MouseMoveEvent>(BK_BIND_DISPACHER_FN(MouseMoveEvent, Mouse::CursorCallback));
        dispatcher.dispatch<KeyPressEvent>(BK_BIND_DISPACHER_FN(KeyPressEvent, Keyboard::KeyCallback));
        dispatcher.dispatch<KeyReleaseEvent>(BK_BIND_DISPACHER_FN(KeyReleaseEvent, Keyboard::KeyCallback));
        if (!(dispatcher.dispatch<WindowCloseEvent>(BK_BIND_DISPACHER_FN(WindowCloseEvent, OnWindowClose)) 
        || dispatcher.dispatch<WindowResizeEvent>(BK_BIND_DISPACHER_FN(WindowResizeEvent, OnWindowResize))))
        {
            for(auto it = p_layer_stack.ReverseBegin(); it != p_layer_stack.ReverseEnd(); it++)
            {
                (*it)->OnEvent(e);
            }
        }
    }

    void Application::Close()
    {
        h_window->Close();
        p_running = false;
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        Close();
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent& e)
    {
        return true;
    }

    void Application::Run() 
    {
        while (p_running)
        {
            for (Layer* layer : p_layer_stack)
                layer->OnUpdate();

            imgui_layer->Begin();
            for (Layer* layer : p_layer_stack)
                layer->ImguiRender();
            imgui_layer->End();
            


            h_window->OnUpdate();
        }
    }
}
