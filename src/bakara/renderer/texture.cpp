#include "bakara/renderer/renderer.h"
#include "bakatools/logging/assert.h"
#include "texture.h"
#include "platforms/opengl/opengl_texture.h"

namespace Bk
{
    Ref<Texture2D> Texture2D::Create(const std::string& filePath)
    {
        switch (Renderer::GetAPI()) 
        {
            case Renderer::API::None: BK_MSG_ASSERT(false, "API not supported"); return nullptr;
            case Renderer::API::Opengl: return CreateRef<Platform::OpenglTexture2D>(filePath);
        }
        BK_MSG_ASSERT(false, "API not supported"); 
        return nullptr;
    }
}