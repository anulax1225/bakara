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
        BK_CORE_INFO("Event : {0}", EVENT_STRING(e));
    }

    void Application::run() 
    {
        while (p_running)
        {
            p_window->on_update();
        }
    }
}
