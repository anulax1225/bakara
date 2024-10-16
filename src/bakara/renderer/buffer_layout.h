#pragma once

#include "bakatools/container/types.h"
#include <initializer_list>
#include <vector>
#include <string>

namespace Bk
{
    class ShaderType
    {
        public:
            enum Type : u8
            {
                None = 0, 
                Bool, Int, Int2, Int3, Int4,
                Float, Float2, Float3, Float4,
                Mat3, Mat4
            };
            ShaderType() : type(None) {}
            ShaderType(Type type) : type(type) {}

            ShaderType& operator=(Type value) { type = value; return *this; }
            operator Type() const { return type; }
            bool operator==(Type type) { return type == this->type; }
            bool operator!=(Type type) { return type != this->type; }
            bool operator==(ShaderType value) { return value.type == this->type; }
            bool operator!=(ShaderType value) { return value.type != this->type; }

            u32 Size();
            u32 Count();
        private:
            Type type;
    };

    struct BufferElement
    {   
        std::string name;
        u32 offset;
        ShaderType type;
        bool normelized;

        BufferElement() = default;

        BufferElement(std::string name, ShaderType type, bool normelized = false)
        : name(name), type(type) {}

        BufferElement(ShaderType type, std::string name, bool normelized = false)
        : name(name), type(type), normelized(normelized) {}
    };

    class BufferLayout 
    {
        public:
            BufferLayout() = default;

            BufferLayout(const std::initializer_list<BufferElement>& elements)
            : elements(elements) { CalculteOffsetAndStride(); }

            inline u32 GetStride() { return stride; }
            inline std::vector<BufferElement>& GetElements() { return elements; }

            std::vector<BufferElement>::iterator begin() { return elements.begin(); }
            std::vector<BufferElement>::iterator end() { return elements.end(); }
        private:
            void CalculteOffsetAndStride();
            std::vector<BufferElement> elements;
            u32 stride;
    };
}