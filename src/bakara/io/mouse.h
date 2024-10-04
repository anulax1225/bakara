#pragma once 

#include "bakara.pch"
#include "mouse_codes.h"
#include "bakara/events/mouse_event.h"
namespace Bk 
{
    class Mouse {
        public:
            //GLFW callback function
            static bool CursorCallback(MouseMoveEvent& e);
            static bool ButtonCallback(MouseButtonEvent& e);
            static bool WheelCallback(MouseScrollEvent& e);

            //Mouse position assesors
            static Vec2 GetPosition();

            //Mouse scroll assesors
            static double GetDX();
            static double GetDY();
            static double GetScrollDX();
            static double GetScrollDY();

            //Mouse buttons assesors
            static bool Button(MouseCode button);
            static bool ButtonUp(MouseCode button);
            static bool ButtonDown(MouseCode button);

        private:
            static double x;
            static double y;

            static double lastX;
            static double lastY;

            static double dX;
            static double dY;

            static double scrollDX;
            static double scrollDY;

            static bool firstMouse;

            static std::vector<bool> buttons;
            static std::vector<bool> buttonsChanged;

            static bool buttonChanged(MouseCode button);
    };
}