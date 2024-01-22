#pragma once

#include <bkpch.h>
#include <bakara/io/window.h>
#include <bakara/events/events.h>

namespace Bk {

    #define BK_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

    class Application 
    {
        public:
            Application();
            virtual ~Application();
            void on_event(Event& e);
            void on_window_close(WindowCloseEvent& e);
            void on_window_resize(WindowResizeEvent& e);
            void run();
        private:
            std::unique_ptr<Window> p_window;
            bool p_running = true;
    };

    std::unique_ptr<Application> create_app();
}