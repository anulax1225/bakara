#pragma once

#include "bakatools/container/types.h"
#include "event.h"

namespace Bk {
    class WindowResizeEvent : public Event 
    {
        public:
            WindowResizeEvent(u32 width, u32 height)
            : p_width(width), p_height(height) {};

            u32 GetWidth() const { return p_width; }
            u32 GetHeight() const { return p_height; }

            EVENT_STRINGIFY("WindowResizeEvent : %d %d", p_width, p_height)

            EVENT_CLASS_TYPE(WindowResize)
            EVENT_CLASS_CATEGORY(AppCategory)

        private: 
            u32 p_width;
            u32 p_height;
    };  

    class WindowCloseEvent : public Event 
    {
        public:
            WindowCloseEvent() = default;

            EVENT_CLASS_TYPE(WindowClose)
            EVENT_CLASS_CATEGORY(AppCategory)
            EVENT_STRINGIFY("Window closing%s", ".")
    };
}