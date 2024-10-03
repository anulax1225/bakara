#pragma once 

#include "bakara.pch"
#include "bakara/renderer/graphics_context.h"

struct GLFWwindow;

namespace Bk::Platform 
{
    class OpenglContext : public GraphicsContext
    {
        public:
            OpenglContext(GLFWwindow* window_handle);
            void init() override;
            void swap_buffers() override;
        private:
            GLFWwindow* window_handle;
    };
}