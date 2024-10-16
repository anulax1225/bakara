#pragma once 

#include "bakara/renderer/renderer_api.h"
#include "bakara/renderer/vertex_array.h"

namespace Bk 
{
    class OpenglRendererAPI : public RendererAPI
    {
        public:
            virtual void Clear(float red, float green, float blue, float alpha) override;
            virtual void DrawIndexed(Ref<VertexArray> va) override;
    };
}