#pragma once

#include "bakara/io/mouse_codes.h"
#include "event.h"
#include "bakara/math/types.h"

namespace Bk 
{
    class MouseMoveEvent : public Event
	{
        public:
            MouseMoveEvent(const float x, const float y)
                : p_mouse_x(x), p_mouse_y(y) {}

            float GetX() const { return p_mouse_x; }
            float GetY() const { return p_mouse_y; }

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

            float GetDx() const { return p_dx; }
            float GetDY() const { return p_dy; }

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
            Code GetBtn() { return m_btn; }

            EVENT_CLASS_CATEGORY(MouseCategory | InputCategory)
        protected:
            MouseButtonEvent(Code btn)
                : m_btn(btn) {}
            Code m_btn;
	};

    class MouseButtonPressEvent : public MouseButtonEvent 
    {
        public: 
            MouseButtonPressEvent(Code btn) 
                : MouseButtonEvent(btn) {}
            
            EVENT_STRINGIFY("MouseButtonPressEvent %d", m_btn)
            EVENT_CLASS_TYPE(MouseButtonPress)
    };

    class MouseButtonReleaseEvent : public MouseButtonEvent 
    {
        public: 
            MouseButtonReleaseEvent(Code btn) 
                : MouseButtonEvent(btn) {}
            
            EVENT_STRINGIFY("MouseButtonReleaseEvent %d", m_btn)
            EVENT_CLASS_TYPE(MouseButtonRelease)
    };
}
