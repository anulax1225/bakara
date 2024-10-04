#include "glfw_window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string.h>

namespace Bk {
    Window* Window::CreateWindow(const WindowProps& props)
    {
        return new Platform::WinGLFW(props);
    }

    namespace Platform {
        static uint p_glfw_Initialized = 0;

        static void glfw_error_callback(int error, const char* description) 
        {
            BK_CORE_CRITICAL("GLFW Error ({0}) {1}", error, description);
        }

        WinGLFW::WinGLFW(const WindowProps& props) 
        {
            p_data.title = props.title;
            p_data.width = props.width;
            p_data.height = props.height;
            Init();
        }

        WinGLFW::~WinGLFW() 
        {
            delete context;
            Close();
        }

        void WinGLFW::Init()
        {
            h_IsOpen = true;
            BK_CORE_INFO("Creating window : {0} ({1}, {2})", p_data.title, p_data.width, p_data.height); 
            if (!p_glfw_Initialized++) 
            {
                int success = glfwInit();
                BK_CORE_MSG_ASSERT(success, "Couldn't Initialize glfw!")
                glfwSetErrorCallback(glfw_error_callback);
            }
            p_window = glfwCreateWindow((int)p_data.width, (int)p_data.height, p_data.title.c_str(), nullptr, nullptr);
            context = new OpenglContext(p_window);
            context->Init();
            glfwSetWindowUserPointer(p_window, &p_data);
            SetVsync(true);

            InitEventCallbacks();
        }

        void WinGLFW::InitEventCallbacks()
        {
            glfwSetFramebufferSizeCallback(p_window, [](GLFWwindow* window, int width, int height)
                {
                    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                    WindowResizeEvent e(data.width = (uint)width, data.height = (uint)height);
                    data.callback(e);
                });
            glfwSetWindowCloseCallback(p_window, [](GLFWwindow* window)
                {
                    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                    WindowCloseEvent e;
                    data.callback(e);
                });
            glfwSetKeyCallback(p_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
                {
                    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                    switch(action)
                    {
                        case GLFW_PRESS:
                            {
                                KeyPressEvent e(key);
                                data.callback(e);
                            }
                            break;
                        case GLFW_RELEASE:
                            {
                                KeyReleaseEvent e(key);
                                data.callback(e);
                            }
                            break;
                        case GLFW_REPEAT:
                            {
                                KeyPressEvent e(key, true);
                                data.callback(e);                            
                            }
                            break;
                    }
                });
            glfwSetMouseButtonCallback(p_window, [](GLFWwindow* window, int button, int action, int mods)
                {
                    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                    switch(action)
                    {
                        case GLFW_PRESS:
                            {
                                MouseButtonPressEvent e(button);
                                data.callback(e);
                            }
                            break;
                        case GLFW_RELEASE:
                            {
                                MouseButtonReleaseEvent e(button);
                                data.callback(e);
                            }
                            break;
                    }
                });
            glfwSetScrollCallback(p_window, [](GLFWwindow* window, double offset_x, double offset_y)
                {

                    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                    MouseScrollEvent e((float)offset_x, (float)offset_y);
                    data.callback(e);
                });
            glfwSetCursorPosCallback(p_window, [](GLFWwindow* window, double pos_x, double pos_y)
                {

                    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                    MouseMoveEvent e((float)pos_x, (float)pos_y);
                    data.callback(e);
                });
        }

        void WinGLFW::OnUpdate()  
        {
            glfwPollEvents();
            context->SwapBuffers();
            if (h_IsOpen)
            {
                if (p_Shutdown && h_IsOpen) { Shutdown(); }
            }
        }

        void WinGLFW::SetEventCallback(const EventCallback callback)  
        {
            p_data.callback = callback;
        }

        void WinGLFW::SetVsync(bool enable)  
        {
            if (h_IsOpen) 
            {
                if (enable) { glfwSwapInterval(1); }
                else { glfwSwapInterval(0); }
                p_data.vsync = enable;
            }
        }

        bool WinGLFW::IsVsync() const  
        {
            return p_data.vsync;
        }
        
        void WinGLFW::Shutdown() 
        {
            h_IsOpen = false;
            p_Shutdown = false;
            glfwDestroyWindow(p_window);
        }

        void WinGLFW::Close()
        {
            p_Shutdown = true;
        }

        void WinGLFW::Open()
        {
            if (!h_IsOpen) 
            { 
                Init(); 
            }
        }

    }
}
