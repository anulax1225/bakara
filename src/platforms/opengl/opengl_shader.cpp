#include "opengl_shader.h"
#include "bakatools/file_system/file.h"
#include "bakatools/logging/assert.h"
#include "bakara/math/types.h"
#include "bakatools/logging/log.h"
#include <unordered_map>

namespace Bk::Platform 
{   
    static GLenum ShaderTypeFromString(std::string type)
    {
        if (type == "vertex") return GL_VERTEX_SHADER;
        else if (type == "fragment" || type == "pixel") return GL_FRAGMENT_SHADER;
        BK_CORE_MSG_ASSERT(false, "An known shader type")  
        return 0;
    }

    OpenglShader::OpenglShader(const std::string& filePath)
    {
        File file = File(filePath);
        BK_CORE_MSG_ASSERT(file.exists(), "Shader file not found")
        std::string filename = file.name();
        size_t pos = filename.find_last_of(".");
        name = pos == std::string::npos ? filename : filename.substr(0, pos); 
        std::string source = file.read();
        auto sources = PreProcess(source);
        Compile(sources);

    }

    OpenglShader::OpenglShader(const std::string& name, const std::string& vertexSrc, const std::string& fragSrc)
    : name(name)
    {
        Compile({
            { GL_VERTEX_SHADER, vertexSrc },
            { GL_FRAGMENT_SHADER, fragSrc }
        });
    }

    std::unordered_map<GLenum, std::string> OpenglShader::PreProcess(std::string source)
    {
        std::unordered_map<GLenum, std::string> sources;
        const std::string token("#type");
        size_t pos = source.find(token, 0);
        BK_CORE_MSG_ASSERT(pos != std::string::npos, "Not shader found in file")
        while (pos != std::string::npos)
        {
            size_t eol = source.find_first_of("\n", pos);
            BK_CORE_MSG_ASSERT(eol != std::string::npos, "Syntax Error in shader file");
            size_t begin = pos + token.length() + 1;
            std::string type = source.substr(begin, eol - begin);
            GLenum glType = ShaderTypeFromString(type);
            size_t nextLine = source.find_first_not_of("\n", eol);
            pos = source.find(token, nextLine);
            sources[glType] = (pos == std::string::npos) ? source.substr(nextLine) : source.substr(nextLine, pos - nextLine);
        }
        return sources;
    }

    void OpenglShader::Compile(std::unordered_map<GLenum, std::string> sources)
    {
        std::vector<GLuint> shaders;
        id = glCreateProgram();
        for(auto& kv : sources)
        {
            GLenum type = kv.first;
            const GLchar* shaderSrc = kv.second.c_str();
            GLuint shader = glCreateShader(type);
            glShaderSource(shader, 1, &shaderSrc, NULL);
            glCompileShader(shader);
            int info;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &info);
            if(!info) {
                std::vector<char> infoLog;
                glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info);
                infoLog.resize(info);
                glGetShaderInfoLog(shader, infoLog.size(), NULL, infoLog.data());
                BK_CORE_ERROR("Shader Error : {0}", std::string(infoLog.data(),infoLog.size()));
                BK_MSG_ASSERT(false, "Error with shader compilation")
            }
            glAttachShader(id, shader);
            shaders.push_back(shader);
        }
        glLinkProgram(id);
        int info;
        glGetProgramiv(id, GL_LINK_STATUS, &info);
        if(!info) {
            std::vector<char> infoLog;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &info);
            infoLog.resize(info);
            glGetProgramInfoLog(id, infoLog.size(), NULL, infoLog.data());
            BK_CORE_ERROR("Shader Error : {0}", std::string(infoLog.data(),infoLog.size()));
            BK_MSG_ASSERT(false, "Error when link sharder in a program")
        }
        for(auto shader : shaders) glDeleteShader(shader);
    }

    OpenglShader::~OpenglShader()
    {
        glDeleteProgram(id);
    }

    void OpenglShader::Bind() 
    {
        glUseProgram(id);
    }

    void OpenglShader::Unbind() 
    {
        glUseProgram(0);
    }

    void OpenglShader::Set(const std::string name, int val) 
    {
        glUniform1i(glGetUniformLocation(id, name.c_str()), val);
    }

    void OpenglShader::Set(const std::string name, bool value) 
    {
        glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
    }

    void OpenglShader::Set(const std::string name, float val) 
    {
        glUniform1f(glGetUniformLocation(this->id, name.c_str()), val);
    }

    void OpenglShader::Set(const std::string name, float v1, float v2, float v3) 
    {
        glUniform3f(glGetUniformLocation(id, name.c_str()), v1, v2, v3);
    }

    void OpenglShader::Set(const std::string name, Vec3 v) 
    {
        this->Set(name, v.x, v.y, v.z);
    }

    void OpenglShader::Set(const std::string name, float v1, float v2, float v3, float v4) 
    {
        glUniform4f(glGetUniformLocation(id, name.c_str()), v1, v2, v3, v4);
    }

    void OpenglShader::Set(const std::string name, Vec4 v) 
    {
        this->Set(name, v.x, v.y, v.z, v.w);
    }

    void OpenglShader::Set(const std::string name, Mat3 val) 
    {
        glUniformMatrix3fv(glGetUniformLocation(this->id, name.c_str()), 1, GL_FALSE, glm::value_ptr(val));
    }

    void OpenglShader::Set(const std::string name, Mat4 val) 
    {
        glUniformMatrix4fv(glGetUniformLocation(this->id, name.c_str()), 1, GL_FALSE, glm::value_ptr(val));
    }

}