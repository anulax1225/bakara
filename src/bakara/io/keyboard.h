#pragma once 

#include "key_codes.h"

namespace Bk 
{
    class Keyboard 
    {
        public:
            static bool KeyRepeat(Code key);
            static bool KeyUp(Code key);
            static bool KeyDown(Code key);
    };
}