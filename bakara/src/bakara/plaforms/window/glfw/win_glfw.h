#pragma once
#include <bkpch.h>
#include <bakara/io/window.h>
#include <bakara/events/events.h>
#include <mutex>
#include <GLFW/glfw3.h>


namespace Bk::Plaform {
    class WinGLFW : public Window
    {
        public:
            WinGLFW(const WindowPros& props);
            virtual ~WinGLFW();

            inline uint get_width() const override { return p_data.width; }
            inline uint get_height() const override { return p_data.height; }
        
            void on_update() override;
            void set_event_callback(const EventCallback callback) override;

            void set_vsync(bool enable) override;
            bool is_vsync() const override;

            void close() override;
            void open() override;
        
        private:
            GLFWwindow* p_window;
            bool p_shutdown;

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