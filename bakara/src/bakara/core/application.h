#pragma once

#include <bkpch.h>
#include "window.h"
#include <bakara/events/event.h>

namespace Bk {

    #define BK_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

    class Application 
    {
        public:
            Application();
            virtual ~Application();
            void on_event(Event& e);
            void run();
        private:
            std::unique_ptr<Window> p_window;
            bool p_running = true;
    };

    std::unique_ptr<Application> create_app();
}