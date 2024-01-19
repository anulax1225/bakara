#pragma once

#include "base.h"
#include "string_fmt.h"

#ifdef BK_ENABLE_ASSERT
    #define BK_CORE_VA_MSG_ASSERT(check, msg, ...) if(!(check)) { BK_CORE_ERROR(Bk::format("Assertion [%s] failed at %s:%d\n\tError : %s", BK_STRINGIFY(check), __FILE__, __LINE__, msg), __VA_ARGS__); BK_DEBUGBREAK(); }
    #define BK_CORE_MSG_ASSERT(check, msg) if(!(check)) { BK_CORE_ERROR("Assertion [{0}] failed at {1}:{2}\n\tError : {3}", BK_STRINGIFY(check), __FILE__, __LINE__, msg); BK_DEBUGBREAK(); }
    #define BK_CORE_ASSERT(check) if(!(check)) { BK_CORE_ERROR("Assertion [{0}] failed at {1}:{2}", BK_STRINGIFY(check), __FILE__, __LINE__); BK_DEBUGBREAK(); }

    #define BK_VA_MSG_ASSERT(check, msg, ...) if(!(check)) { BK_ERROR(Bk::format("Assertion [%s] failed at %s:%d\n\tError : %s", BK_STRINGIFY(check), __FILE__, __LINE__, msg), __VA_ARGS__); BK_DEBUGBREAK(); }
    #define BK_MSG_ASSERT(check, msg) if(!(check)) { BK_ERROR("Assertion [{0}] failed at {1}:{2}\n\tError : {3}", BK_STRINGIFY(check), __FILE__, __LINE__, msg); BK_DEBUGBREAK(); }
    #define BK_ASSERT(check) if(!(check)) { BK_ERROR("Assertion [{0}] failed at {1}:{2}", BK_STRINGIFY(check), __FILE__, __LINE__); BK_DEBUGBREAK(); }
#else
    #define BK_CORE_MSG_ASSERT(check, msg, ...) 
    #define BK_CORE_IMP_ASSERT(check, msg)
    #define BK_CORE_ASSERT(check)

    #define BK_MSG_ASSERT(check, msg, ...) 
    #define BK_IMP_ASSERT(check, msg) 
    #define BK_ASSERT(check)
#endif