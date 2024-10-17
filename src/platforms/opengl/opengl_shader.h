#pragma once 

#include "bakara/renderer/shader.h"
#include <glad/glad.h>
#include <string>
#include <unordered_map>

namespace Bk::Platform 
{
    class OpenglShader : public Shader
    {
        public:
            OpenglShader(const std::string& filePath);
            OpenglShader(const std::string& name, const std::string& vertexSrc, const std::string& fragSrc);
            virtual ~OpenglShader();

            virtual const std::string& GetName() override { return name; } 

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
            std::string name;
            std::unordered_map<GLenum, std::string> PreProcess(std::string source);
            void Compile(std::unordered_map<GLenum, std::string> sources);
    };
}