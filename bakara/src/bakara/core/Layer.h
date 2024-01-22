#pragma once 
#include <bkpch.h>

namespace Bk {
    class Layer 
    {
        public:
            Layer(const std::string& name = "Layer");
            virtual ~Layer() {}

            virtual void on_attach() {}
            virtual void on_detach() {}
            virtual void on_event() {}
            virtual void on_update() {}
        private:
            std::string name;
    }; 
}