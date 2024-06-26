#pragma once 
#include <bakarapch.h>
#include <bakara/events/events.h>

namespace Bk {
    class Layer 
    {
        public:
            Layer(const std::string& name = "Layer");
            ~Layer() {}

            virtual void on_attach() {}
            virtual void on_detach() {}
            virtual void on_event(Event& e) {}
            virtual void on_update() {}
            virtual void imgui_render() {}
            const std::string to_string() const { return name; }
        protected:
            std::string name;
    }; 
}