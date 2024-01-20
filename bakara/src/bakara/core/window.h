#pragma once 

#include <bkpch.h>
#include <bakara/events/event.h>

namespace Bk {
    struct WindowPros 
    {
        std::string title;
        uint width;
        uint height;

        WindowPros(std::string title = "Bakara engine", uint width = 1000, uint height = 800)
            : title(title), width(width), height(height) {}
    };

    class Window 
    {
        public: 
            using EventCallback = std::function<void(Event& e)>;
            virtual ~Window(){}

            virtual uint get_width() const = 0;
            virtual uint get_height() const = 0;
            
            virtual void on_update() = 0;
            virtual void set_event_callback(const EventCallback callback) = 0;

            virtual void set_vsync(bool enable) = 0;
            virtual bool is_vsync() const = 0;

            static std::unique_ptr<Window> create_window(const WindowPros& props = WindowPros());
    };
}