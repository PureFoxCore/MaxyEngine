#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Maxy
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

// Core log macros
#define MAXY_CORE_TRACE(...)    ::Maxy::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define MAXY_CORE_INFO(...)     ::Maxy::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define MAXY_CORE_WARN(...)     ::Maxy::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define MAXY_CORE_ERROR(...)    ::Maxy::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define MAXY_CORE_CRITICAL(...) ::Maxy::Logger::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MAXY_TRACE(...)         ::Maxy::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define MAXY_INFO(...)          ::Maxy::Logger::GetClientLogger()->info(__VA_ARGS__)
#define MAXY_WARN(...)          ::Maxy::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define MAXY_ERROR(...)         ::Maxy::Logger::GetClientLogger()->error(__VA_ARGS__)
#define MAXY_CRITICAL(...)      ::Maxy::Logger::GetClientLogger()->critical(__VA_ARGS__)

#ifdef MAXY_ENABLE_ASSERTS
    #define MAXY_ASSERT(condition, ...) { if (!(condition)) MAXY_ERROR(__VA_ARGS__); }
    #define MAXY_CORE_ASSERT(condition, ...) { if (!(condition)) MAXY_CORE_ERROR(__VA_ARGS__); }
#else
    #define MAXY_ASSERT(condition, ...)
    #define MAXY_CORE_ASSERT(condition, ...)
#endif