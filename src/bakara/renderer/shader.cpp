#include "shader.h"
#include "bakara/renderer/renderer.h"
#include "bakatools/logging/assert.h"
#include "platforms/opengl/opengl_shader.h"

namespace Bk
{
    Shader* Shader::Create(std::string vertexSrc, std::string fragSrc)
    {
        switch(Renderer::GetAPI())
        {
            case Renderer::API::None: BK_MSG_ASSERT(false, "API not supported"); return nullptr;
            case Renderer::API::Opengl: return new Platform::OpenglShader(vertexSrc, fragSrc);
        }
    }
}