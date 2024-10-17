#pragma once 

#include "bakatools/container/types.h"
namespace Bk 
{
    class GraphicsContext
    {
        public:
            virtual ~GraphicsContext() {}
            virtual void Init() = 0;
            virtual void SwapBuffers() = 0;

            static Scope<GraphicsContext> Create(void* window_handle);
    };
}