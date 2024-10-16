#pragma once 

namespace Bk 
{
    class GraphicsContext
    {
        public:
            virtual ~GraphicsContext() {}
            virtual void Init() = 0;
            virtual void SwapBuffers() = 0;
            virtual void SetViewport(int width, int height) = 0;
    };
}