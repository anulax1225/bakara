#pragma once

#include "bakara.pch"

#define BK_BIND_EVENT_FN(fn) [this](Event& e) { fn(e); }
#define BK_BIND_DISPACHER_FN(event, fn) [this](event& e) -> bool{ return fn(e); }

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

    enum EventCategory 
    {
        None = 0,
        AppCategory = BK_BIT_SHIFT(0),
        InputCategory = BK_BIT_SHIFT(1),
        KeyboardCategory = BK_BIT_SHIFT(2),
        MouseCategory = BK_BIT_SHIFT(3),
        MouseButtonCategory = BK_BIT_SHIFT(4)
    };

    #define EVENT_CLASS_TYPE(type) static EventType get_static_type() { return EventType::type; }\
								virtual EventType get_event_type() const override { return get_static_type(); }\
								virtual const char* get_name() const override { return BK_STRINGIFY(type); }

    #define EVENT_CLASS_CATEGORY(category) virtual int get_category_flags() const override { return category; }
    
    #ifdef BK_DEBUG
        #define EVENT_STRINGIFY(str, ...) std::string ToString() const override { return Tools::string_format(str, __VA_ARGS__); }

        #define GET_EVENT_STRING(event) event.ToString()
    #else 
        #define EVENT_STRINGIFY(str, ...) 

        #define GET_EVENT_STRING(event) ""
    #endif

    class Event 
    {
        public:
            virtual ~Event() = default;

            bool handled = false;

            virtual EventType get_event_type() const = 0;
            virtual const char* get_name() const = 0;
            virtual int get_category_flags() const = 0;
        #ifdef BK_DEBUG
            virtual std::string ToString() const { return get_name(); }
        #endif
            bool is_in_category(EventCategory category) { return get_category_flags() & category; }
    };

	class EventDispatcher
	{
        public:
            EventDispatcher(Event& event)
            : p_event(event) {}
            
            // F will be deduced by the compiler
            template<typename T, typename F>
            bool dispatch(const F& func)
            {
                if (p_event.get_event_type() == T::get_static_type())
                {
                    p_event.handled |= func(static_cast<T&>(p_event));
                    return true;
                }
                return false;
            }

            inline Event& get_event() { return p_event; }
        private:
            Event& p_event;
	};
}