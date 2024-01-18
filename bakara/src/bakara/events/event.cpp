#include "event.h"

namespace Bk {
    EventDispatcher::EventDispatcher(Event& event) 
    {
        p_event = event;
    }

    bool ventDispatcher::Dispatch(const F& func)
    {
        if (p_event.GetEventType() == T::GetStaticType())
        {
            p_event.handled |= func(static_cast<T&>(p_event));
            return true;
        }
        return false;
    }

    inline std::ostream& operator<<(std::ostream& os, Event& e)  
    {
        return os << e.ToString();
    }

}