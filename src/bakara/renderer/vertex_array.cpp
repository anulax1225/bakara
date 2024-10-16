#include "bakara/renderer/renderer.h"
#include "bakatools/logging/assert.h"
#include "vertex_array.h"
#include "platforms/opengl/opengl_vertex_array.h"

namespace Bk
{
    VertexArray* VertexArray::Create()
    {
        switch (Renderer::GetAPI()) 
        {
            case Renderer::API::None: BK_MSG_ASSERT(false, "API not supported"); return nullptr;
            case Renderer::API::Opengl: return new Platform::OpenglVertexArray();
        }
    }
}