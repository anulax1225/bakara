#include "buffer.h"
#include "bakara/renderer/renderer.h"
#include "bakatools/container/types.h"
#include "bakatools/logging/assert.h"
#include "platforms/opengl/opengl_buffer.h"

namespace Bk
{
    Ref<VertexBuffer> VertexBuffer::Create(float *vertices, u32 size)
    {
        switch (Renderer::GetAPI()) 
        {
            case Renderer::API::None: BK_MSG_ASSERT(false, "API not supported"); return nullptr;
            case Renderer::API::Opengl: return CreateRef<Platform::OpenglVertexBuffer>(vertices, size);
        }
        BK_MSG_ASSERT(false, "API not supported"); 
        return nullptr;
    }

    Ref<IndexBuffer> IndexBuffer::Create(u32* indices, u32 count)
    {
        switch (Renderer::GetAPI()) 
        {
            case Renderer::API::None: BK_MSG_ASSERT(false, "API not supported"); return nullptr;
            case Renderer::API::Opengl: return CreateRef<Platform::OpenglIndexBuffer>(indices, count);
        }
        BK_MSG_ASSERT(false, "API not supported"); 
        return nullptr;
    }
}