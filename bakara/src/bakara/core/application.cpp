#include "application.h"

namespace Bk {
    Application::Application() 
    { 
        p_window = Window::create_window();
        p_window->set_event_callback(BK_BIND_EVENT_FN(on_event));
    }

    Application::~Application() { }

    void Application::on_event(Event& e)
    {
        EventDispatcher dispatcher(e);
        if (!(dispatcher.dispatch<WindowCloseEvent>(BK_BIND_DISPACHER_FN(WindowCloseEvent, on_window_close)) ||
		dispatcher.dispatch<WindowResizeEvent>(BK_BIND_DISPACHER_FN(WindowResizeEvent, on_window_resize))))
        {
            for(auto it = layer_stack.rbegin(); it != layer_stack.rend(); it++)
            {
                (*it)->on_event(e);
            }
        }
    }

    bool Application::on_window_close(WindowCloseEvent& e)
    {
        p_window->close();

        return true;
    }

    bool Application::on_window_resize(WindowResizeEvent& e)
    {
        BK_CORE_INFO("Event : {0}", GET_EVENT_STRING(e));
        return true;
    }

    void Application::run() 
    {
        while (p_running)
        {
            p_window->on_update();
            if (!p_window->is_open()) p_window->open();
        }
    }
}
