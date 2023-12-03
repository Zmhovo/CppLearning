#include <iostream>
#include "Log.h"

void LogOutput(const char* message)
{
	std::cout << message << std::endl;

}

void Log::SetLevel(Level level)
{
	m_LogLevel = level;
}

void Log::Error(const char* message)
{
	if (m_LogLevel >= LevelError)
		std::cout << "[ERROR]:" << message << std::endl;
}

void Log::Warn(const char* message)
{
	if (m_LogLevel >= LevelWarning)
		std::cout << "[WARNING]:" << message << std::endl;
}

void Log::Info(const char* message)
{
	if (m_LogLevel >= LevelInfo)
		std::cout << "[INFO]:" << message << std::endl;
}
