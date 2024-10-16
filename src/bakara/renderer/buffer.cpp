#include "buffer.h"
#include "bakara/renderer/renderer.h"
#include "bakatools/logging/assert.h"
#include "platforms/opengl/opengl_buffer.h"

namespace Bk
{
    VertexBuffer* VertexBuffer::Create(float *vertices, u32 size)
    {
        switch (Renderer::GetAPI()) 
        {
            case Renderer::API::None: BK_MSG_ASSERT(false, "API not supported"); return nullptr;
            case Renderer::API::Opengl: return new Platform::OpenglVertexBuffer(vertices, size);
        }
    }

    IndexBuffer* IndexBuffer::Create(u32* indices, u32 count)
    {
        switch (Renderer::GetAPI()) 
        {
            case Renderer::API::None: BK_MSG_ASSERT(false, "API not supported"); return nullptr;
            case Renderer::API::Opengl: return new Platform::OpenglIndexBuffer(indices, count);
        }
    }
}