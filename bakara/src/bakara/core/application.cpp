#include "application.h"

namespace Bk {
    Application::Application() 
    { 
        h_window = Window::create_window();
        h_window->set_event_callback(BK_BIND_EVENT_FN(on_event));
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

    bool Application::on_window_close(WindowCloseEvent& e)
    {
        h_window->close();
        p_running = false;
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
            h_window->on_update();
        }
    }
}
