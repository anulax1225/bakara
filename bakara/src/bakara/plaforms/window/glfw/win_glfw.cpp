#include "win_glfw.h"

namespace Bk {
    std::unique_ptr<Window> Window::create_window(const WindowPros& props)
    {
        return std::unique_ptr<Window>(new Plaform::WinGLFW(props));
    }

    namespace Plaform {
        static uint p_glfw_initialized = 0;

        static void glfw_error_callback(int error, const char* description) 
        {
            BK_CORE_CRITICAL("GLFW Error ({0}) {1}", error, description);
        }

        WinGLFW::WinGLFW(const WindowPros& props) 
        {
            p_data.title = props.title;
            p_data.width = props.width;
            p_data.height = props.height;

            BK_CORE_INFO("Creating window : {0} ({1}, {2})", props.title, props.width, props.height); 
            if (!p_glfw_initialized++) 
            {
                int success = glfwInit();
                BK_MSG_ASSERT(success, "Couldn't initialize glfw!")
                glfwSetErrorCallback(glfw_error_callback);
            }
            p_window = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
            glfwMakeContextCurrent(p_window);
            glfwSetWindowUserPointer(p_window, &p_data);
            set_vsync(true);
        }

        WinGLFW::~WinGLFW() 
        {
            shutdown();
        }

        void WinGLFW::on_update()  
        {
            glfwPollEvents();
            glfwSwapBuffers(p_window);
        }

        void WinGLFW::set_event_callback(const EventCallback callback)  
        {
            p_data.callback = callback;
        }

        void WinGLFW::set_vsync(bool enable)  
        {
            if (enable) { glfwSwapInterval(1); }
            else { glfwSwapInterval(0); }
            p_data.vsync = enable;
        }

        bool WinGLFW::is_vsync() const  
        {
            return p_data.vsync;
        }

        void WinGLFW::shutdown()
        {
            glfwDestroyWindow(p_window);
        }
    }
}
