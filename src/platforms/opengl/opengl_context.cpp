#include "bakatools/logging/assert.h"
#include "bakatools/logging/log.h"
#include "opengl_context.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Bk::Platform 
{
    OpenglContext::OpenglContext(GLFWwindow* window_handle)
    : window_handle(window_handle) {}

    void OpenglContext::Init() 
    {
        glfwMakeContextCurrent(window_handle);
        int success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        BK_CORE_MSG_ASSERT(success, "Couldn't load glad!")

        GLint majVers = 0, minVers = 0;
        glGetIntegerv(GL_MAJOR_VERSION, &majVers);
        glGetIntegerv(GL_MINOR_VERSION, &minVers);
        BK_CORE_INFO("Hardware info ");
        BK_CORE_INFO(" - Opengl Version    {0}.{1}", majVers, minVers);
        BK_CORE_INFO(" - GPU Vendor        {0}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
        BK_CORE_INFO(" - Renderer          {0}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
        BK_CORE_INFO(" - Renderer Version  {0}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
        BK_CORE_MSG_ASSERT(majVers > 4 || (majVers == 4 && minVers >= 2), "Bakara only support Opengl versions 4.2 or more.")
    }

    void OpenglContext::SwapBuffers() 
    {
        glfwSwapBuffers(window_handle);
    }

    void OpenglContext::SetViewport(int width, int height)
    {
        glViewport(0, 0, width, height);
    }
}