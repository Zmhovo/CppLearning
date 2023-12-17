#ifndef __THREAD_H__
#define __THREAD_H__

#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
	using namespace std::literals::chrono_literals;          //引入名称空间以使用std::this_thread::sleep_for()

	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;

	while (!s_Finished)
	{
		std::cout << "Working...Press Enter key to finish.\n";
		std::this_thread::sleep_for(2s);          //等待2s
	}
}

#endif // !__THREAD_H__
