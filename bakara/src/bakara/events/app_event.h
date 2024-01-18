#pragma once

#include "event.h"

namespace Bk {
    class AppTickEvent : public Event 
    {
        AppTickEvent() = default;

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(AppEvent)
    };   

    class AppRenderEvent : public Event 
    {
        AppRenderEvent() = default;

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(AppEvent)
    };

    class AppUpdateEvent : public Event 
    {
        AppUpdateEvent() = default;

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(AppEvent)
    };
}