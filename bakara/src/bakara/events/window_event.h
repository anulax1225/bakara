#pragma once

#include <bkpch.h>
#include <format>
#include "event.h"

namespace Bk {
    class WindowResizeEvent : public Event 
    {
        public:
            WindowResizeEvent(uint width, uint height)
            : p_width(width), p_height(height) {};

            uint get_width() const { return p_width; }
            uint get_height() const { return p_height; }

            EVENT_STRINGIFY("WindowResizeEvent : %d %d", p_width, p_height)

            EVENT_CLASS_TYPE(WindowResize)
            EVENT_CLASS_CATEGORY(AppCategory)

        private: 
            uint p_width;
            uint p_height;
    };  

    class WindowCloseEvent : public Event 
    {
        WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(AppCategory)
    };
}