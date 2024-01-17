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
            static void Init();

            static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger; }
            static std::shared_ptr<spdlog::logger>& GetAppLogger() { return AppLogger; }
        private:
            static std::shared_ptr<spdlog::logger> CoreLogger;
            static std::shared_ptr<spdlog::logger> AppLogger;
	};

    #define BK_CORE_TRACE(...)    ::Bk::Log::GetCoreLogger()->trace(__VA_ARGS__)
    #define BK_CORE_INFO(...)     ::Bk::Log::GetCoreLogger()->info(__VA_ARGS__)
    #define BK_CORE_WARN(...)     ::Bk::Log::GetCoreLogger()->warn(__VA_ARGS__)
    #define BK_CORE_ERROR(...)    ::Bk::Log::GetCoreLogger()->error(__VA_ARGS__)
    #define BK_CORE_CRITICAL(...) ::Bk::Log::GetCoreLogger()->critical(__VA_ARGS__)

    // Client log macros
    #define BK_TRACE(...)         ::Bk::Log::GetAppLogger()->trace(__VA_ARGS__)
    #define BK_INFO(...)          ::Bk::Log::GetAppLogger()->info(__VA_ARGS__)
    #define BK_WARN(...)          ::Bk::Log::GetAppLogger()->warn(__VA_ARGS__)
    #define BK_ERROR(...)         ::Bk::Log::GetAppLogger()->error(__VA_ARGS__)
    #define BK_CRITICAL(...)      ::Bk::Log::GetAppLogger()->critical(__VA_ARGS__)

}