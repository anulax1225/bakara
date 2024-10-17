#include "shader.h"
#include "bakara/renderer/renderer.h"
#include "bakatools/logging/assert.h"
#include "platforms/opengl/opengl_shader.h"

namespace Bk
{
    Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragSrc)
    {
        switch(Renderer::GetAPI())
        {
            case Renderer::API::None: BK_MSG_ASSERT(false, "API not supported"); return nullptr;
            case Renderer::API::Opengl: return CreateRef<Platform::OpenglShader>(name, vertexSrc, fragSrc);
        }
        BK_MSG_ASSERT(false, "API not supported"); 
        return nullptr;
    }
    Ref<Shader> Shader::Create(const std::string& filePath)
    {
        switch(Renderer::GetAPI())
        {
            case Renderer::API::None: BK_MSG_ASSERT(false, "API not supported"); return nullptr;
            case Renderer::API::Opengl: return CreateRef<Platform::OpenglShader>(filePath);
        }
        BK_MSG_ASSERT(false, "API not supported"); 
        return nullptr;
    }

    void ShaderLibrary::Add(const std::string& name, const Ref<Shader>& shader)
    {
        BK_CORE_MSG_ASSERT(!Exists(name), "Shader already exists in library")
        shaders[name] = shader;
    }

    void ShaderLibrary::Add(const Ref<Shader>& shader)
    {
        const auto& name = shader->GetName();
        Add(shader->GetName(), shader);
    }

    Ref<Shader> ShaderLibrary::Load(const std::string& filePath)
    {
        Ref<Shader> shader = Shader::Create(filePath);
        Add(shader);
        return shader;
    }

    Ref<Shader> ShaderLibrary::Load(const std::string& name, const  std::string filePath)
    {
        Ref<Shader> shader = Shader::Create(filePath);
        Add(name, shader);
        return shader;
    }

    Ref<Shader> ShaderLibrary::Get(const std::string& name)
    {
        BK_CORE_MSG_ASSERT(Exists(name), "Shader not found")
        return shaders[name];
    }
}