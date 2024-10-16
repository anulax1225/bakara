#pragma once 

#include "bakara/renderer/shader.h"

namespace Bk::Platform 
{
    class OpenglShader : public Shader
    {
        public:
            OpenglShader(std::string vertexSrc, std::string fragSrc);
            virtual ~OpenglShader();

            virtual void Bind() override;
            virtual void Unbind() override;

            virtual void Set(const std::string name, int val) override;
            virtual void Set(const std::string name, bool val) override;
            virtual void Set(const std::string name, float val) override;
            virtual void Set(const std::string name, float v1, float v2, float v3) override;
            virtual void Set(const std::string name, Vec3 v) override;
            virtual void Set(const std::string name, float v1, float v2, float v3, float v4) override;
            virtual void Set(const std::string name, Vec4 v) override;
            virtual void Set(const std::string name, Mat3 val) override;
            virtual void Set(const std::string name, Mat4 val) override;
        
        private:
            unsigned int id;
    };
}