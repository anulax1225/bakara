#include "graphics_context.h"
#include "bakara/renderer/renderer.h"
#include "bakatools/logging/assert.h"
#include "platforms/opengl/opengl_context.h"

namespace Bk 
{
    Scope<GraphicsContext> GraphicsContext::Create(void *window_handle)
    {
        switch (Renderer::GetAPI()) 
        {
            case Renderer::API::None: BK_MSG_ASSERT(false, "API not supported"); return nullptr;
            case Renderer::API::Opengl: return CreateScope<Platform::OpenglContext>(window_handle);
        }
        BK_MSG_ASSERT(false, "API not supported"); 
        return nullptr;
    }
}