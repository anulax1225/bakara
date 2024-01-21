#pragma once

#include <bkpch.h>
#include "window.h"

namespace Bk {
    class Application 
    {
        public:
            Application();
            virtual ~Application();
        
            void run();
        private:
            std::unique_ptr<Window> p_window;
            bool p_running = true;
    };

    std::unique_ptr<Application> create_app();
}