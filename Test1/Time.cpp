#include "Time.h"

Timer::Timer()
{
	start_time = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
	end_time = std::chrono::high_resolution_clock::now();
	duration = end_time - start_time;

	std::cout << "Timer took " << duration.count() * 1000.0f << "ms" << std::endl;
}
