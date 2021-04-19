#include "mxpch.h"
#include "Core/Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Maxy
{
    std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

    void Logger::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        
        s_CoreLogger = spdlog::stdout_color_mt("Maxy");
        s_CoreLogger->set_level(spdlog::level::level_enum::trace);
        
        s_ClientLogger = spdlog::stdout_color_mt("App");
        s_ClientLogger->set_level(spdlog::level::level_enum::trace);
    }
}