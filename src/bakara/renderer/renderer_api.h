#pragma once 

#include "bakara/renderer/vertex_array.h"

namespace Bk 
{
    class RendererAPI
    {
        public:
            virtual ~RendererAPI() {}

            virtual void Init() = 0;
            virtual void Clear(float red, float green, float blue, float alpha) = 0;
            virtual void SetViewport(u32 width, u32 height) = 0;
            virtual void DrawIndexed(Ref<VertexArray> va) = 0;
    };
}