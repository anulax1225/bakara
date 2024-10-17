#pragma once 

#include "bakara/math/types.h"
#include "bakatools/container/types.h"
#include <string>
#include <unordered_map>

namespace Bk
{
    class Shader 
    {
        public:
            virtual ~Shader() {}

            virtual const std::string& GetName() = 0;

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

            static Ref<Shader> Create(const std::string& name, const std::string& vertexSrc, const std::string& fragSrc);
            static Ref<Shader> Create(const std::string& filePath);
    };

    class ShaderLibrary
    {
        public:
            inline bool Exists(const std::string& name) { return shaders.find(name) != shaders.end(); }

            void Add(const std::string& name, const Ref<Shader>& shader);
            void Add(const Ref<Shader>& shader);
            Ref<Shader> Load(const std::string& filePath);
            Ref<Shader> Load(const std::string& name, const  std::string filePath);

            Ref<Shader> Get(const std::string& name);
            inline Ref<Shader> operator[](const std::string& name) { return Get(name); }
        private:
            std::unordered_map<std::string, Ref<Shader>> shaders;
    };
}