#pragma once
#include <iostream>

void LogOutput(const char* message);

class Log
{
public:
	enum Level
	{
		LevelError = 0, LevelWarning, LevelInfo
	};
	
private:
	Level m_LogLevel = LevelInfo;

public:
	void SetLevel(Level level);

	void Error(const char* message);          //´íÎó

	void Warn(const char* message);          //¾¯¸æ

	void Info(const char* message);          //ÏûÏ¢
};