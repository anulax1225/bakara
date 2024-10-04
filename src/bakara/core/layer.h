#pragma once 
#include "bakara.pch"
#include <bakara/events/events.h>

namespace Bk {
    class Layer 
    {
        public:
            Layer(const std::string& name = "Layer");
            ~Layer() {}

            virtual void OnAttach() {}
            virtual void OnDetach() {}
            virtual void OnEvent(Event& e) {}
            virtual void OnUpdate() {}
            virtual void ImguiRender() {}
            const std::string ToString() const { return name; }
        protected:
            std::string name;
    }; 
}