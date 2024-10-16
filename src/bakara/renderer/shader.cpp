#include "shader.h"
#include "bakara/renderer/renderer.h"
#include "bakatools/logging/assert.h"
#include "platforms/opengl/opengl_shader.h"

namespace Bk
{
    Ref<Shader> Shader::Create(std::string vertexSrc, std::string fragSrc)
    {
        switch(Renderer::GetAPI())
        {
            case Renderer::API::None: BK_MSG_ASSERT(false, "API not supported"); return nullptr;
            case Renderer::API::Opengl: return CreateRef<Platform::OpenglShader>(vertexSrc, fragSrc);
        }
        BK_MSG_ASSERT(false, "API not supported"); 
        return nullptr;
    }
}