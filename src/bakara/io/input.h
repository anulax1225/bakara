#pragma once 

#include "bakarapch.h"
#include "io_codes.h"

namespace Bk 
{
    class Input
    {
        static bool key_down(KeyCode key);
        static bool key_released(KeyCode key);
        static bool key_pressed(KeyCode key);

        static bool mouse_button_down(MouseCode btn);
        static bool mouse_button_released(MouseCode btn);
        static bool mouse_button_pressed(MouseCode btn);

        static Vec2 mouse_position();
    };
}