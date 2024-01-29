#pragma once

#include <bkpch.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Bk {

	class Log
	{
        public:
            static void init();

            static std::shared_ptr<spdlog::logger>& get_core_logger() { return p_core_logger; }
            static std::shared_ptr<spdlog::logger>& get_app_logger() { return p_app_logger; }
        private:
            static std::shared_ptr<spdlog::logger> p_core_logger;
            static std::shared_ptr<spdlog::logger> p_app_logger;
	};
    #ifdef BK_DEBUG
        #define BK_CORE_TRACE(...)    ::Bk::Log::get_core_logger()->trace(__VA_ARGS__)
        #define BK_CORE_INFO(...)     ::Bk::Log::get_core_logger()->info(__VA_ARGS__)
        #define BK_CORE_WARN(...)     ::Bk::Log::get_core_logger()->warn(__VA_ARGS__)
        #define BK_CORE_ERROR(...)    ::Bk::Log::get_core_logger()->error(__VA_ARGS__)
        #define BK_CORE_CRITICAL(...) ::Bk::Log::get_core_logger()->critical(__VA_ARGS__)

        #define BK_TRACE(...)         ::Bk::Log::get_app_logger()->trace(__VA_ARGS__)
        #define BK_INFO(...)          ::Bk::Log::get_app_logger()->info(__VA_ARGS__)
        #define BK_WARN(...)          ::Bk::Log::get_app_logger()->warn(__VA_ARGS__)
        #define BK_ERROR(...)         ::Bk::Log::get_app_logger()->error(__VA_ARGS__)
        #define BK_CRITICAL(...)      ::Bk::Log::get_app_logger()->critical(__VA_ARGS__)
    #else
        #define BK_CORE_TRACE(...)    
        #define BK_CORE_INFO(...)     
        #define BK_CORE_WARN(...)     
        #define BK_CORE_ERROR(...)    
        #define BK_CORE_CRITICAL(...) 

        #define BK_TRACE(...)         
        #define BK_INFO(...)          
        #define BK_WARN(...)          
        #define BK_ERROR(...)         
        #define BK_CRITICAL(...)       
    #endif
}