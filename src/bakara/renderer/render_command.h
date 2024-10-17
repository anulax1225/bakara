#pragma once 

#include "bakara/math/types.h"
#include "bakara/renderer/renderer_api.h"
#include "bakara/renderer/vertex_array.h"

namespace Bk 
{
    class RenderCommand
    {
        public:
            static inline void Init() { rendererAPI->Init(); }
            static inline void Clear(Vec4 color) { rendererAPI->Clear(color.r, color.g, color.b, color.a); }
            static inline void Clear(float red, float green, float blue, float alpha) { rendererAPI->Clear(red, green, blue, alpha); }
            static inline void SetViewport(u32 width, u32 height) { rendererAPI->SetViewport(width, height); }
            static inline void DrawIndexed(Ref<VertexArray> va) { rendererAPI->DrawIndexed(va); }
        private:
            static RendererAPI* rendererAPI;
    };
}