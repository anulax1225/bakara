#pragma once

#define BK_STRINGIFY(x) #x
#define BIT_SHIFT(x) (1 << x)

#define BK_BIND_EVENT_FN(fn) [this](Event& e) { fn(e); }
#define BK_BIND_DISPACHER_FN(event, fn) [this](event& e) -> bool{ return fn(e); }



