#pragma once

#include "event.h"
#include <bakara/math/type.h>
#include <bakara/core/io_codes.h>

namespace Bk 
{
    class MouseMoveEvent : public Event
	{
        public:
            MouseMoveEvent(const float x, const float y)
                : p_mouse_x(x), p_mouse_y(y) {}

            float get_x() const { return p_mouse_x; }
            float get_y() const { return p_mouse_y; }

            Vec2 get_pos() const { return Vec2(p_mouse_x, p_mouse_y); }


            EVENT_STRINGIFY("MouseMouveEvent : (%f, %f)", p_mouse_x, p_mouse_y)

            EVENT_CLASS_TYPE(MouseMove)
            EVENT_CLASS_CATEGORY(MouseCategory | InputCategory)
        private:
            float p_mouse_x;
            float p_mouse_y;
	};

    class MouseScrollEvent : public Event
	{
        public:
            MouseScrollEvent(const float x, const float y)
                : p_dx(x), p_dy(y) {}

            float get_dx() const { return p_dx; }
            float get_dy() const { return p_dy; }

            EVENT_STRINGIFY("MouseScrollEvent : (%f, %f)", p_dx, p_dy)

            EVENT_CLASS_TYPE(MouseMove)
            EVENT_CLASS_CATEGORY(MouseCategory | InputCategory | MouseButtonCategory)
        private:
            float p_dx;
            float p_dy;
	};

    class MouseButtonEvent : public Event
	{
        public:
            MouseCode get_btn() { return m_btn; }

            EVENT_CLASS_CATEGORY(MouseCategory | InputCategory)
        protected:
            MouseButtonEvent(MouseCode btn)
                : m_btn(btn) {}
            MouseCode m_btn;
	};

    class MouseButtonPressEvent : public MouseButtonEvent 
    {
        public: 
            MouseButtonPressEvent(MouseCode btn) 
                : MouseButtonEvent(btn) {}
            
            EVENT_STRINGIFY("MouseButtonPressEvent %d", m_btn)
            EVENT_CLASS_TYPE(MouseButtonPress)
    };

    class MouseButtonReleaseEvent : public MouseButtonEvent 
    {
        public: 
            MouseButtonReleaseEvent(MouseCode btn) 
                : MouseButtonEvent(btn) {}
            
            EVENT_STRINGIFY("MouseButtonReleaseEvent %d", m_btn)
            EVENT_CLASS_TYPE(MouseButtonRelease)
    };
}
