#pragma once

#include "log.h"

#define BK_STRINGIFY(x) #x
#define BIT_SHIFT(x) (1 << x)



#ifdef BK_DEBUG
    #if defined(BK_PLATFORM_WINDOWS)
        #define BK_DEBUGBREAK() __debugbreak()
    #elif defined(BK_PLATFORM_LINUX)
        #include <signal.h>
        #define BK_DEBUGBREAK() raise(SIGTRAP)
    #else 
        #error "Plaform doesn't support debug yet"
    #endif
    #define BK_ENABLE_ASSERT
#else 
    #define BK_DEBUGBREAK()
#endif


