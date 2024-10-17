#pragma once 

#include "bakara/renderer/renderer_api.h"
#include "bakara/renderer/vertex_array.h"
#include "bakatools/container/types.h"

namespace Bk 
{
    class OpenglRendererAPI : public RendererAPI
    {
        public:
            virtual void Init() override;
            virtual void Clear(float red, float green, float blue, float alpha) override;
            virtual void SetViewport(u32 width, u32 height) override;
            virtual void DrawIndexed(Ref<VertexArray> va) override;
    };
}