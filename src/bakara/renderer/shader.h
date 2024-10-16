#pragma once 

#include "bakara/math/types.h"
#include <string>

namespace Bk
{
    class Shader 
    {
        public:
            virtual ~Shader() {}

            virtual void Bind() = 0;
            virtual void Unbind() = 0;

            virtual void Set(const std::string name, int val) = 0;
            virtual void Set(const std::string name, bool val) = 0;
            virtual void Set(const std::string name, float val) = 0;
            virtual void Set(const std::string name, float v1, float v2, float v3) = 0;
            virtual void Set(const std::string name, Vec3 v) = 0;
            virtual void Set(const std::string name, float v1, float v2, float v3, float v4) = 0;
            virtual void Set(const std::string name, Vec4 v) = 0;
            virtual void Set(const std::string name, Mat3 val) = 0;
            virtual void Set(const std::string name, Mat4 val) = 0;

            static Shader* Create(std::string vertexSrc, std::string fragSrc);
    };
}