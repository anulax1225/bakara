#pragma once
#include "bakara.pch"
#include "bakara/core/window.h"
#include "bakara/events/events.h"
#include "platforms/opengl/opengl_context.h"

struct GLFWwindow;

namespace Bk::Platform {
    class WinGLFW : public Window
    {
        public:
            WinGLFW(const WindowProps& props);
            virtual ~WinGLFW();

            inline uint get_width() const override { return p_data.width; }
            inline uint get_height() const override { return p_data.height; }
        
            void on_update() override;
            void set_event_callback(const EventCallback callback) override;

            void set_vsync(bool enable) override;
            bool is_vsync() const override;

            void close() override;
            void open() override;

            void* get_native_window() override { return p_window; }
            /*! \fn Bk::Window::is_open
            Indicates if the window is opened
            @return Open flag
            */
            bool is_open() override { return h_is_open; }
        private:
            bool h_is_open; //!< indicaste if the window is opened or not
            bool p_shutdown;

            GLFWwindow* p_window;
            OpenglContext* context;
            struct WindowData 
            {
                std::string title;
                uint width;
                uint height;
                bool vsync;
                EventCallback callback;
            };
            WindowData p_data;
            
            void init_event_callbacks();
            void init();
            void shutdown();
    };
}