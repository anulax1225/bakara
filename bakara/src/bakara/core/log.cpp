#include "log.h"

namespace Bk {

	std::shared_ptr<spdlog::logger> Log::core_logger;
	std::shared_ptr<spdlog::logger> Log::app_logger;

	void Log::init()
	{
		std::vector<spdlog::sink_ptr> log_sinks;
		log_sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		log_sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("bakara.log", true));

		log_sinks[0]->set_pattern("%^[%T] %n: %v%$");
		log_sinks[1]->set_pattern("[%T] [%l] %n: %v");

		core_logger = std::make_shared<spdlog::logger>("BAKARA", begin(log_sinks), end(log_sinks));
		spdlog::register_logger(core_logger);
		core_logger->set_level(spdlog::level::trace);
		core_logger->flush_on(spdlog::level::trace);

		app_logger = std::make_shared<spdlog::logger>("APP", begin(log_sinks), end(log_sinks));
		spdlog::register_logger(app_logger);
		app_logger->set_level(spdlog::level::trace);
		app_logger->flush_on(spdlog::level::trace);
	}

}