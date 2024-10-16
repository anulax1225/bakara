#pragma once

#include "bakara/renderer/texture.h"

namespace Bk::Platform 
{
    class OpenglTexture2D : public Texture2D
    {
        public:
            OpenglTexture2D(const std::string& filePath);
            virtual ~OpenglTexture2D();

            virtual u32 GetWidth() override { return width; }
            virtual u32 GetHeight() override { return height; }
            virtual void Bind() override;
        private:
            u32 id;
            u32 width, height;
    }; 
}