#pragma once 


#include "bakara/renderer/graphics_context.h"

struct GLFWwindow;

namespace Bk::Platform 
{
    class OpenglContext : public GraphicsContext
    {
        public:
            OpenglContext(GLFWwindow* window_handle);
            virtual ~OpenglContext() override { }
            void Init() override;
            void SwapBuffers() override;
            void SetViewport(int width, int height) override;
        private:
            GLFWwindow* window_handle;
    };
}