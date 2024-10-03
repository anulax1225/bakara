#pragma once 

#include "bakara.pch"
#include "mouse_codes.h"
#include "bakara/events/mouse_event.h"
namespace Bk 
{
    class Mouse {
        public:
            //GLFW callback function
            static bool cursor_callback(MouseMoveEvent& e);
            static bool button_callback(MouseButtonEvent& e);
            static bool wheel_callback(MouseScrollEvent& e);

            //Mouse position assesors
            static Vec2 get_position();

            //Mouse scroll assesors
            static double get_dx();
            static double get_dy();
            static double get_scroll_dx();
            static double get_scroll_dy();

            //Mouse buttons assesors
            static bool button(MouseCode button);
            static bool button_up(MouseCode button);
            static bool button_down(MouseCode button);

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