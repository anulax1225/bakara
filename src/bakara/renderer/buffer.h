#pragma once 
#include "bakara/renderer/buffer_layout.h"
#include "bakatools/container/types.h"

namespace Bk
{
    class VertexBuffer 
    {
        public:
            virtual ~VertexBuffer() {}
            virtual void Bind() = 0;
            virtual void Unbind() = 0;
            virtual void SetLayout(BufferLayout layout) = 0;
            virtual BufferLayout& GetLayout() = 0;
            static Ref<VertexBuffer> Create(float* vertices, u32 size);
    };
    
    class IndexBuffer 
    {
        public:
            virtual ~IndexBuffer() {}
            virtual void Bind() = 0;
            virtual void Unbind() = 0;
            virtual u32 GetCount() = 0;
            static Ref<IndexBuffer> Create(u32* indices, u32 count);
    };
}