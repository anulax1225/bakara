#include "application.h"

namespace Bk {
    Application::Application() 
    { 
        p_window = Window::create_window();
    }

    Application::~Application() { }

    void Application::run() 
    {
        while (p_running)
        {
            p_window->on_update();
        }
    }
}
