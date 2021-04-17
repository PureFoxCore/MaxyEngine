#pragma once

#include <spdlog/spdlog.h>

namespace Maxy
{
    namespace Core
    {
        class Logger
        {
        public:
            static void Init();
            inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
            inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }
        private:
            static std::shared_ptr<spdlog::logger> s_CoreLogger;
            static std::shared_ptr<spdlog::logger> s_ClientLogger;
        };
    }
}

// Core log macros
#define MAXY_CORE_TRACE(...)    ::Maxy::Core::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define MAXY_CORE_INFO(...)     ::Maxy::Core::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define MAXY_CORE_WARN(...)     ::Maxy::Core::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define MAXY_CORE_ERROR(...)    ::Maxy::Core::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define MAXY_CORE_CRITICAL(...) ::Maxy::Core::Logger::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MAXY_TRACE(...)         ::Maxy::Core::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define MAXY_INFO(...)          ::Maxy::Core::Logger::GetClientLogger()->info(__VA_ARGS__)
#define MAXY_WARN(...)          ::Maxy::Core::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define MAXY_ERROR(...)         ::Maxy::Core::Logger::GetClientLogger()->error(__VA_ARGS__)
#define MAXY_CRITICAL(...)      ::Maxy::Core::Logger::GetClientLogger()->critical(__VA_ARGS__)