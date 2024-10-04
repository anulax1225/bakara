#pragma once 

#include "bakara.pch"
#include "key_codes.h"
#include "bakara/events/key_event.h"

namespace Bk 
{
    class Keyboard {
        public:
            
            static bool KeyCallback(KeyEvent& e);
            //Assesors
            static bool KeyDown(KeyCode key);
            static bool KeyWentUp(KeyCode key);
            static bool KeyWentDown(KeyCode key);

        private:
            //Keys state
            static std::vector<bool> keys;
            static std::vector<bool> keysChanged;
            //Assesor
            static bool keyChanged(KeyCode key);
    };
}