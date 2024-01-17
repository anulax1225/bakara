#pragma once

#include <bkpch.h>

namespace Bk {
    class Application 
    {
        public:
            Application();
            virtual ~Application();
        
            void run();
    };

    std::unique_ptr<Application> create_app();
}