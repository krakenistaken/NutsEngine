#include "nepch.h"
#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace NutsEngine {

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    Log::Log() {}
    Log::~Log() {}

    void Log::Init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        // Core logger (single-threaded renkli konsol)
        auto core_sink = std::make_shared<spdlog::sinks::stdout_color_sink_st>();
        s_CoreLogger = std::make_shared<spdlog::logger>("NutsEngine", core_sink);
        spdlog::register_logger(s_CoreLogger);
        s_CoreLogger->set_level(spdlog::level::trace);

        // Client logger (single-threaded renkli konsol)
        auto client_sink = std::make_shared<spdlog::sinks::stdout_color_sink_st>();
        s_ClientLogger = std::make_shared<spdlog::logger>("App", client_sink);
        spdlog::register_logger(s_ClientLogger);
        s_ClientLogger->set_level(spdlog::level::trace);
    }

}

