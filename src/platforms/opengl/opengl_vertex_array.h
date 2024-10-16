#pragma once

#include "bakara/renderer/buffer.h"
#include "bakara/renderer/vertex_array.h"
#include "bakatools/container/types.h"
#include <vector>

namespace Bk::Platform
{

    class OpenglVertexArray : public VertexArray 
    {
        public:
            OpenglVertexArray();
            virtual ~OpenglVertexArray();
            virtual void Bind() override;
            virtual void Unbind() override;
            virtual void AddVertexBuffer(Ref<VertexBuffer> buf) override;
            virtual void SetIndexbuffer(Ref<IndexBuffer> buf) override;
            virtual std::vector<Ref<VertexBuffer>> GetVertexBuffers() override { return vBuffers; }
            virtual Ref<IndexBuffer> GetIndexbuffer() override { return iBuffer; }

        private:
            std::vector<Ref<VertexBuffer>> vBuffers;
            Ref<IndexBuffer> iBuffer;
            u32 id;
    };
}