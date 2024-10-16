#pragma once 

#include "bakara/math/types.h"
#include "mouse_codes.h"

namespace Bk 
{
    class Mouse {
        public:
            static Vec2 GetPosition();
            static bool ButtonUp(Code button);
            static bool ButtonDown(Code button);
            static bool ButtonRepeat(Code button);
    };
}