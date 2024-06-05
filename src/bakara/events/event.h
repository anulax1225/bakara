#pragma once

#include <bakara/core/base.h>
#include <bkpch.h>

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
        AppCategory = BIT_SHIFT(0),
        InputCategory = BIT_SHIFT(1),
        KeyboardCategory = BIT_SHIFT(2),
        MouseCategory = BIT_SHIFT(3),
        MouseButtonCategory = BIT_SHIFT(4)
    };

    #define EVENT_CLASS_TYPE(type) static EventType get_static_type() { return EventType::type; }\
								virtual EventType get_event_type() const override { return get_static_type(); }\
								virtual const char* get_name() const override { return BK_STRINGIFY(type); }

    #define EVENT_CLASS_CATEGORY(category) virtual int get_category_flags() const override { return category; }
    
    #ifdef BK_DEBUG
        #define EVENT_STRINGIFY(str, ...) std::string to_string() const override { return Tools::string_format(str, __VA_ARGS__); }

        #define GET_EVENT_STRING(event) event.to_string()
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
            virtual std::string to_string() const { return get_name(); }
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