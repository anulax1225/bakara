#pragma once

#include <bkpch.h>
#include <bakara/io/window.h>
#include <bakara/events/events.h>

namespace Bk {

    #define BK_BIND_EVENT_FN(fn) [this](Event& e) { fn(e); }
    #define BK_BIND_DISPACHER_FN(event, fn) [this](event& e) -> bool{ return fn(e); }

    class Application 
    {
        public:
            Application();
            virtual ~Application();
            void on_event(Event& e);
            bool on_window_close(WindowCloseEvent& e);
            bool on_window_resize(WindowResizeEvent& e);
            void run();
        private:
            std::unique_ptr<Window> p_window;
            bool p_running = true;
    };

    std::unique_ptr<Application> create_app();
}