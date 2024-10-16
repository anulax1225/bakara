#pragma once 

#include "bakara/renderer/buffer.h"
#include "bakatools/container/types.h"

namespace Bk
{
    class VertexArray 
    {
        public:
            virtual ~VertexArray() {}
            virtual void Bind() = 0;
            virtual void Unbind() = 0;
            virtual void AddVertexBuffer(Ref<VertexBuffer> buf) = 0;
            virtual void SetIndexbuffer(Ref<IndexBuffer> buf) = 0;

            virtual std::vector<Ref<VertexBuffer>> GetVertexBuffers() = 0;
            virtual Ref<IndexBuffer> GetIndexbuffer() = 0;
            static VertexArray* Create();
    };
}