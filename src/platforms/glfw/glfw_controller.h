#pragma once

#include "bakara/io/controller.h"

namespace Bk 
{
    namespace Platform 
    {
        class ControllerGLFW : public Controller 
        {
            public:
                ControllerGLFW() = delete;
                ControllerGLFW(int i);
                
                void Update() override;
                float Axes(Code axis) override;
                unsigned char Button(Code button) override;
                int GetAxesCount() override;
                int GetButtonCount() override;
                bool IsPresent() override;
                const char* GetName() override;
            
            private:
                int present;
                int id;
                const char* name;

                int axesCount;
                const float* axes;

                int buttonCount;
                const unsigned char* buttons;
        };
    }
}