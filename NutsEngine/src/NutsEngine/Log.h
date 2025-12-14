
#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace NutsEngine {
	class NUTSENGINE_API Log
	{
	public:
		Log();
		~Log();

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


// Core log macros
#define NE_CORE_TRACE(...)    ::NutsEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NE_CORE_INFO(...)     ::NutsEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NE_CORE_WARN(...)     ::NutsEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NE_CORE_ERROR(...)    ::NutsEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NE_CORE_CRITICAL(...) ::NutsEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define NE_TRACE(...)         ::NutsEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NE_INFO(...)          ::NutsEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define NE_WARN(...)          ::NutsEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NE_ERROR(...)         ::NutsEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define NE_CRITICAL(...)      ::NutsEngine::Log::GetClientLogger()->critical(__VA_ARGS__)


