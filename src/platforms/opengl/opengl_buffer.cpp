#include "opengl_buffer.h"  
#include <glad/glad.h>

namespace Bk::Platform
{
    OpenglVertexBuffer::OpenglVertexBuffer(float* vertices, u32 size)
    {
        glGenBuffers(1, &id);
        glBindBuffer(GL_ARRAY_BUFFER, id);  
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW); 
    }

    OpenglVertexBuffer::~OpenglVertexBuffer() 
    {
        glDeleteBuffers(1, &id);
    }

    void OpenglVertexBuffer::Bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, id); 
    }

    void OpenglVertexBuffer::Unbind() 
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }


    OpenglIndexBuffer::OpenglIndexBuffer(u32* indices, u32 count)
    : count(count)
    {
        glGenBuffers(1, &id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(u32), indices, GL_STATIC_DRAW);
    }

    OpenglIndexBuffer::~OpenglIndexBuffer() 
    {
        glDeleteBuffers(1, &id);
    }

    void OpenglIndexBuffer::Bind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id); 
    }

    void OpenglIndexBuffer::Unbind() 
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    u32 OpenglIndexBuffer::GetCount()
    {
        return count;
    }
}