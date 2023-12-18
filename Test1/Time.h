#ifndef __TIME_H__
#define __TIME_H__

#include <iostream>
#include <thread>
#include <chrono>

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;
	std::chrono::duration<float> duration;

	Timer();

	~Timer();
};
#endif // !__TIME_H__
