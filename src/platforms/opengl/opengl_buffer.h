#pragma once

#include "bakara/renderer/buffer.h"
#include "bakara/renderer/buffer_layout.h"

namespace Bk::Platform 
{
    class OpenglVertexBuffer : public VertexBuffer
    {
        public:
            OpenglVertexBuffer(float* vertices, u32 size);
            virtual ~OpenglVertexBuffer();
            virtual void Bind() override;
            virtual void Unbind() override;
            virtual void SetLayout(BufferLayout layout) override { this->layout = layout; }
            virtual BufferLayout& GetLayout() override { return layout; }
        private:
            BufferLayout layout;
            u32 id;
    };   

    class OpenglIndexBuffer : public IndexBuffer
    {
        public:
            OpenglIndexBuffer(u32* vertices, u32 count);
            virtual ~OpenglIndexBuffer();
            virtual void Bind() override;
            virtual void Unbind() override;
            virtual u32 GetCount() override;

        private:
            u32 id;
            u32 count;
    };
}