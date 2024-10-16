#include "platforms/opengl/opengl_vertex_array.h"
#include "bakara/renderer/buffer.h"
#include "bakara/renderer/buffer_layout.h"
#include "bakatools/logging/assert.h"
#include <glad/glad.h>

namespace Bk::Platform
{
    static GLenum OpenglTypeFromShaderType(ShaderType type)
    {
        switch(type)
        {
            case ShaderType::None:   BK_MSG_ASSERT(false, "Shader type not supported"); return GL_NONE;
            case ShaderType::Float:  return GL_FLOAT;
            case ShaderType::Float2: return GL_FLOAT;
            case ShaderType::Float3: return GL_FLOAT;
            case ShaderType::Float4: return GL_FLOAT;
            case ShaderType::Mat3:   return GL_FLOAT;
            case ShaderType::Mat4:   return GL_FLOAT;
            case ShaderType::Int:    return GL_INT;
            case ShaderType::Int2:   return GL_INT;
            case ShaderType::Int3:   return GL_INT;
            case ShaderType::Int4:   return GL_INT;
            case ShaderType::Bool:   return GL_BOOL;
        }
    }

    OpenglVertexArray::OpenglVertexArray()
    {
        glGenVertexArrays(1, &id);
    }

    OpenglVertexArray::~OpenglVertexArray()
    {
        glDeleteVertexArrays(1, &id);
    }

    void OpenglVertexArray::Bind()
    {
        glBindVertexArray(id);
    }

    void OpenglVertexArray::Unbind()
    {
        glBindVertexArray(0);
    }

    void OpenglVertexArray::AddVertexBuffer(Ref<VertexBuffer> buf)
    {
        BK_MSG_ASSERT(!buf->GetLayout().GetElements().empty(), "Vertex Buffer layout empty");
        glBindVertexArray(id);
        u32 index = 0;
        u32 stride = buf->GetLayout().GetStride();
        for(auto& element : buf->GetLayout())
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, 
            element.type.Count(), 
            OpenglTypeFromShaderType(element.type), 
            element.normelized ? GL_TRUE : GL_FALSE, 
            stride, 
            (const void*)(u64)element.offset);
            index++;
        }
        vBuffers.push_back(buf);
        glBindVertexArray(0);
    }

    void OpenglVertexArray::SetIndexbuffer(Ref<IndexBuffer> buf)
    {
        glBindVertexArray(id);
        buf->Bind();
        iBuffer = buf;
        glBindVertexArray(0);
    }
}