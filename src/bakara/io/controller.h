#pragma once

#include "controller_codes.h"

namespace Bk 
{
    class Controller {
        public:
            virtual void Update() = 0;
            virtual float Axes(Code axis) = 0;
            virtual unsigned char Button(Code button) = 0;
            virtual int GetAxesCount() = 0;
            virtual int GetButtonCount() = 0;
            virtual bool IsPresent() = 0;
            virtual const char* GetName() = 0;
    };

}