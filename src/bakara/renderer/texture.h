#pragma once

#include "bakatools/container/types.h"
#include <string>

namespace Bk 
{
    class Texture 
    {
        public:
            virtual ~Texture() {}
            virtual u32 GetWidth() = 0;
            virtual u32 GetHeight() = 0;
            virtual void Bind() = 0;
    };

    class Texture2D : public Texture
    {
        public:
            static Ref<Texture2D> Create(const std::string& filePath);
    };
}