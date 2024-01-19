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

#ifdef BK_ENABLE_ASSERT
    #define BK_CORE_MSG_ASSERT(check, msg, ...) if(!(check)) { BK_CORE_ERROR(msg, __VA_ARGS__); BK_DEBUGBREAK(); }
    #define BK_CORE_IMP_ASSERT(check, msg) if(!(check)) { BK_CORE_ERROR("Assertion [{0}] failed : {1}", BK_STRINGIFY(check), msg); BK_DEBUGBREAK(); }
    #define BK_CORE_ASSERT(check) if(!(check)) { BK_CORE_ERROR("Assertion [{0}] failed at {1}:{2}", BK_STRINGIFY(check), __FILE__, __LINE__); BK_DEBUGBREAK(); }

    #define BK_MSG_ASSERT(check, msg, ...) if(!(check)) { BK_ERROR(msg, __VA_ARGS__); BK_DEBUGBREAK(); }
    #define BK_IMP_ASSERT(check, msg) if(!(check)) { BK_ERROR("Assertion [{0}] failed : {1}", BK_STRINGIFY(check), msg); BK_DEBUGBREAK(); }
    #define BK_ASSERT(check) if(!(check)) { BK_ERROR("Assertion [{0}] failed at {1}:{2}", BK_STRINGIFY(check), __FILE__, __LINE__); BK_DEBUGBREAK(); }
#else
    #define BK_CORE_MSG_ASSERT(check, msg, ...) 
    #define BK_CORE_IMP_ASSERT(check, msg)
    #define BK_CORE_ASSERT(check)

    #define BK_MSG_ASSERT(check, msg, ...) 
    #define BK_IMP_ASSERT(check, msg) 
    #define BK_ASSERT(check)
#endif


