#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace TheGameEngine {

	class ENGINE_API Log

	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}
 
//Log Macros
#define CORE_ERROR(...) ::TheGameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_WARN(...) ::TheGameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_INFO(...) ::TheGameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_TRACE(...) ::TheGameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_FATAL(...) ::TheGameEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define ERROR(...) ::TheGameEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define WARN(...) ::TheGameEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define INFO(...) ::TheGameEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TRACE(...) ::TheGameEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FATAL(...) ::TheGameEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)