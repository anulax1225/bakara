#pragma once

#include <bakara/math/base.h>

namespace Bk {
    enum class EventType 
    {
        None = 0,
        AppTick,
        AppUpdate,
        AppRender,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMove,
        KeyPress,
        KeyRelease,
        KeyTyped,
        MouseButtonPress,
        MouseButtonRelease,
        MouseMove,
        MouseScroll
    };

    enum class EventCategory 
    {
        None = 0,
        AppEvent = BIT_SHIFT(0),
        InputEvent = BIT_SHIFT(1),
        KeyboardEvent = BIT_SHIFT(2),
        MouseEvent = BIT_SHIFT(3),
        MouseButtonEvent = BIT_SHIFT(4)
    };

    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

    #define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class Event 
    {
        public:
            virtual ~Event() = default;

            bool handled = false;

            virtual EventType GetEventType() const = 0;
            virtual const char* GetName() const = 0;
            virtual int GetCategoryFlags() const = 0;
            virtual std::string ToString() const { return GetName(); }

            bool IsInCategory(EventCategory category)
            {
                return GetCategoryFlags() & (int)category == GetCategoryFlags();
            }
    };
    inline std::ostream& operator<<(std::ostream& os, Event& e);


	class EventDispatcher
	{
        public:
            EventDispatcher(Event& event);
            
            // F will be deduced by the compiler
            template<typename T, typename F>
            bool Dispatch(const F& func);
        private:
            Event& p_event;
	};
}