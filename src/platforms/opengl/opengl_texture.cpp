#include "opengl_texture.h"
#include "bakatools/logging/assert.h"
#include "bakatools/logging/log.h"

#include <stb_image.h>
#include <glad/glad.h>

namespace Bk::Platform 
{
    OpenglTexture2D::OpenglTexture2D(const std::string& filePath)
    {
        stbi_set_flip_vertically_on_load(true);
        int width, height, channels;
        stbi_uc* data = stbi_load(filePath.c_str(), &width, &height, &channels, 0);
        
        BK_CORE_MSG_ASSERT(data, "Coudn't load image data")
        BK_CORE_MSG_ASSERT(channels >= 3 && channels <= 4, "Image format not supported")

        this->width = (u32)width;
        this->height = (u32)height;

        GLenum internalFormat = 0, format = 0;
        if(channels == 4) { internalFormat = GL_RGBA8; format = GL_RGBA; }
        else { internalFormat = GL_RGB8; format = GL_RGB; }

        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);
        glTexStorage2D(GL_TEXTURE_2D, 1, internalFormat, this->width, this->height);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, this->width, this->height, format, GL_UNSIGNED_BYTE, data);
        
        stbi_image_free(data);
    }

    OpenglTexture2D::~OpenglTexture2D()
    {
        glDeleteTextures(1, &id);
    }

    void OpenglTexture2D::Bind(u32 slot) 
    {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, id);
    }
}