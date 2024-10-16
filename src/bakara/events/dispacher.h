#pragma once

#include "bakara/events/event.h"

namespace Bk {
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