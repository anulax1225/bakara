#include "glfw_window.h"
#include "bakara/core/deltatime.h"
#include "bakara/events/key_event.h"
#include "bakara/events/mouse_event.h"
#include "bakara/events/window_event.h"
#include "bakatools/logging/assert.h"

#include <GLFW/glfw3.h>

namespace Bk {
    Window* Window::CreateWindow(const WindowProps& props)
    {
        return new Platform::GlfwWindow(props);
    }

    namespace Platform {
        GlfwWindowData::~GlfwWindowData()
        {
            delete context;
        }

        static uint p_glfw_Initialized = 0;

        static void glfw_error_callback(int error, const char* description) 
        {
            BK_CORE_CRITICAL("GLFW Error ({0}) {1}", error, description);
        }

        GlfwWindow::GlfwWindow(const WindowProps& props) 
        {
            p_data.title = props.title;
            p_data.width = props.width;
            p_data.height = props.height;
            Init();
        }

        GlfwWindow::~GlfwWindow() 
        {
            Close();
        }

        void GlfwWindow::Init()
        {
            h_IsOpen = true;
            BK_CORE_INFO("Creating window '{0}' ({1}, {2})", p_data.title, p_data.width, p_data.height); 
            if (!p_glfw_Initialized++) 
            {
                int success = glfwInit();
                BK_CORE_MSG_ASSERT(success, "Couldn't Initialize glfw!")
                glfwSetErrorCallback(glfw_error_callback);
            }
            p_window = glfwCreateWindow((int)p_data.width, (int)p_data.height, p_data.title.c_str(), nullptr, nullptr);
            p_data.context = new OpenglContext(p_window);
            p_data.context->Init();
            p_data.context->SetViewport(p_data.width, p_data.height);
            glfwSetWindowUserPointer(p_window, &p_data);
            SetVsync(true);

            InitEventCallbacks();
        }

        void GlfwWindow::InitEventCallbacks()
        {
            glfwSetFramebufferSizeCallback(p_window, [](GLFWwindow* window, int width, int height)
                {
                    GlfwWindowData& data = *(GlfwWindowData*)glfwGetWindowUserPointer(window);
                    data.context->SetViewport(width, height);
                    WindowResizeEvent e(data.width = (uint)width, data.height = (uint)height);
                    data.callback(e);
                });
            glfwSetWindowCloseCallback(p_window, [](GLFWwindow* window)
                {
                    GlfwWindowData& data = *(GlfwWindowData*)glfwGetWindowUserPointer(window);
                    WindowCloseEvent e;
                    data.callback(e);
                });
            glfwSetKeyCallback(p_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
                {
                    GlfwWindowData& data = *(GlfwWindowData*)glfwGetWindowUserPointer(window);
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
                    GlfwWindowData& data = *(GlfwWindowData*)glfwGetWindowUserPointer(window);
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
                    GlfwWindowData& data = *(GlfwWindowData*)glfwGetWindowUserPointer(window);
                    MouseScrollEvent e((float)offset_x, (float)offset_y);
                    data.callback(e);
                });
            glfwSetCursorPosCallback(p_window, [](GLFWwindow* window, double pos_x, double pos_y)
                {

                    GlfwWindowData& data = *(GlfwWindowData*)glfwGetWindowUserPointer(window);
                    MouseMoveEvent e((float)pos_x, (float)pos_y);
                    data.callback(e);
                });
        }

        void GlfwWindow::OnUpdate()  
        {
            float time = glfwGetTime();
            dt = DeltaTime(time - lastFrameTime);
            lastFrameTime = time;
            glfwPollEvents();
            p_data.context->SwapBuffers();
            if (h_IsOpen)
            {
                if (p_Shutdown && h_IsOpen) { Shutdown(); }
            }
        }

        void GlfwWindow::SetEventCallback(const EventCallback callback)  
        {
            p_data.callback = callback;
        }

        void GlfwWindow::SetVsync(bool enable)  
        {
            if (h_IsOpen) 
            {
                if (enable) { glfwSwapInterval(1); }
                else { glfwSwapInterval(0); }
                p_data.vsync = enable;
            }
        }

        bool GlfwWindow::IsVsync() const  
        {
            return p_data.vsync;
        }
        
        void GlfwWindow::Shutdown() 
        {
            h_IsOpen = false;
            p_Shutdown = false;
            glfwDestroyWindow(p_window);
        }

        void GlfwWindow::Close()
        {
            p_Shutdown = true;
        }

        void GlfwWindow::Open()
        {
            if (!h_IsOpen) 
            { 
                Init(); 
            }
        }

    }
}
