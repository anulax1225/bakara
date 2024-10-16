#include "opengl_shader.h"
#include "bakatools/logging/log.h"
#include "bakara/math/types.h"
#include <glad/glad.h>

namespace Bk::Platform 
{
    OpenglShader::OpenglShader(std::string vertexSrc, std::string fragSrc)
    {
        int success;
        char infoLog[512];
        //Creating a shader program
        id = glCreateProgram();
        //Compile shader
        GLuint ret = glCreateShader(GL_VERTEX_SHADER);
        const GLchar* shader = vertexSrc.c_str();
        glShaderSource(ret, 1, &shader, NULL);
        glCompileShader(ret);
        glGetShaderiv(ret, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(ret, 512, NULL, infoLog);
            BK_INFO("Error with fragment shader compilating : {0}", infoLog); 
        }
        glAttachShader(id, ret);
        
        GLuint ret1 = glCreateShader(GL_FRAGMENT_SHADER);
        shader = fragSrc.c_str();
        glShaderSource(ret1, 1, &shader, NULL);
        glCompileShader(ret1);
        glGetShaderiv(ret1, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(ret1, 512, NULL, infoLog);
            BK_INFO("Error with fragment shader compilating : {0}", infoLog); 
        }
        glAttachShader(id, ret1);
        glLinkProgram(id);

        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(id, 512, NULL, infoLog);
            BK_INFO("Error when link sharder in a program : {0}", infoLog); 
        }

        glDeleteShader(ret);
        glDeleteShader(ret1);
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
        glUniformMatrix3fv(glGetUniformLocation(this->id, name.c_str()), 1, GL_FALSE, Math::value_ptr(v));
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