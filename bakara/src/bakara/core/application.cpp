#include "application.h"

namespace Bk {
    Application::Application() 
    { 
        p_window = Window::create_window();
        p_window->set_event_callback(BK_BIND_EVENT_FN(Application::on_event));
    }

    Application::~Application() { }

    void Application::on_event(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowCloseEvent>(BK_BIND_EVENT_FN(Application::on_window_close));
		dispatcher.dispatch<WindowResizeEvent>(BK_BIND_EVENT_FN(Application::on_window_resize));
        BK_CORE_INFO("Event : {0}", EVENT_STRING(e));
    }

    void Application::on_window_close(WindowCloseEvent& e)
    {
        p_window.close();
    }

    void Application::on_window_resize(WindowResizeEvent& e)
    {
        
    }

    void Application::run() 
    {
        while (p_running)
        {
            p_window->on_update();
        }
    }
}
