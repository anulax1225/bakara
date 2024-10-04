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
        BK_CORE_INFO("Opengl Version : {0}.{1}", majVers, minVers);
    }

    void OpenglContext::SwapBuffers() 
    {
        glfwSwapBuffers(window_handle);
    }

}