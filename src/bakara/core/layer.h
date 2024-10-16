#pragma once 

#include "bakara/core/deltatime.h"
#include "bakara/events/event.h"
#include <string>

namespace Bk {
    class Layer 
    {
        public:
            Layer(const std::string& name = "Layer");
            ~Layer() {}

            virtual void OnAttach() {}
            virtual void OnDetach() {}
            virtual void OnEvent(Event& e) {}
            virtual void OnUpdate(DeltaTime dt) {}
            virtual void ImguiRender() {}
            const std::string ToString() const { return name; }
        protected:
            std::string name;
    }; 
}