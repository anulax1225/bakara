#include "application.h"

namespace Bk {
    Application* Application::p_instance = nullptr;

    Application::Application() 
    { 
        BK_CORE_MSG_ASSERT(p_instance == nullptr, "Application already exists, can not create two application.")
        Application::p_instance = this;
        h_window = std::unique_ptr<Window>(Window::create_window());
        imgui_layer = new ImguiLayer();
        push_overlay(imgui_layer);
        h_window->set_event_callback(BK_BIND_EVENT_FN(on_event));
        p_running = true;
    }

    Application::~Application() { }

    void Application::on_event(Event& e)
    {
        EventDispatcher dispatcher(e);
        if (!(dispatcher.dispatch<WindowCloseEvent>(BK_BIND_DISPACHER_FN(WindowCloseEvent, on_window_close)) ||
		dispatcher.dispatch<WindowResizeEvent>(BK_BIND_DISPACHER_FN(WindowResizeEvent, on_window_resize))))
        {
            for(auto it = p_layer_stack.rbegin(); it != p_layer_stack.rend(); it++)
            {
                (*it)->on_event(e);
            }
        }
    }

    void Application::close()
    {
        h_window->close();
        p_running = false;
    }

    bool Application::on_window_close(WindowCloseEvent& e)
    {
        close();
        return true;
    }

    bool Application::on_window_resize(WindowResizeEvent& e)
    {
        return true;
    }

    void Application::run() 
    {
        while (p_running)
        {
            for (Layer* layer : p_layer_stack)
                layer->on_update();

            imgui_layer->begin();
            for (Layer* layer : p_layer_stack)
                layer->imgui_render();
            imgui_layer->end();

            h_window->on_update();
        }
    }
}
