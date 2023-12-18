#include <iostream>
#include <GLFW/glfw3.h>

#include "Log.h"
#include "Player.h"
#include "Entity.h"
#include "Array.h"
#include "String.h"
#include "Const.h"
#include "SmartPointer.h"
#include "Template.h"
#include "Thread.h"
#include "Time.h"
#include "Sort.h"



int main() 
{
	PlayerSon player1;

	player1.Move(1, -1);
	std::cout << player1.GetName() << std::endl;
	player1.PrintName();


	std::cout << "" << std::endl;


	Log log;
	log.SetLevel(Log::LevelWarning);
	log.Warn("Warning!");
	

	log.SetLevel(Log::LevelInfo);
	log.Info("Info");


	std::cout << "" << std::endl;


	Entity e1;
	Entity::x = 4;
	Entity::y = 6;

	e1.Print();


	std::cout << "" << std::endl;
	std::cout << "================================  Array  ================================" << std::endl;

	Array arr;
	std::cout << arr.example[2] << std::endl;
	arr.example[2] = 88;
	std::cout << arr.example[2] << std::endl;
	std::cout << arr.another[2] << std::endl;
	
	std::array<int, 3> arr2 = { 0, 0 ,0 };
	arr2[0] = 2;
	arr2[1] = 4;
	arr2[2] = 6;
	std::cout << arr2.size() << std::endl;

	std::vector<Vertex> vertices;          //动态数组
	//vertices.push_back({ 1,2,3 });          push_back()用于创建临时对象存放{ 1,2,3 }，再拷贝放入vertices
	//vertices.push_back({ 4,5,6 });
	//vertices.push_back({ 7,8,9 });
	//优化上述代码
	vertices.reserve(3);          //reserve()预分配存储空间
	vertices.emplace_back(1, 2, 3);          //emplace_back()直接在vertices尾部插入
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9);

	for (int i = 0; i < vertices.size(); i++)
	{
		std::cout << vertices[i] << std::endl;
	}

	std::cout << "" << std::endl;


	GetName();

	std::string UpName = "ZMH";
	UpToLow(UpName);
	std::cout << UpName << std::endl;


	std::cout << "" << std::endl;


	ConstTest constname1("First",0);          //在栈上创建对象，花括号结束即生命周期结束
	std::cout << constname1.GetName() << std::endl;
	
	ConstTest* constname2 = new ConstTest("Second",10);          //在堆上创建对象，生命周期直到被delete()
	std::cout << constname2->GetName() << std::endl;
	delete(constname2);


	{
		std::unique_ptr<SmartPointer> uniquePointer = std::make_unique<SmartPointer>();
		//也可使用std::unique_ptr<SmartPointer> uniquePointer(new SmartPointer());          需要显式转换，不可使用“= new SmartPointer()”
		//unique_ptr意味着不可被复制，即不可使用“std::unique_ptr<SmartPoniter> copy = uniquePoint”
		uniquePointer->Print();

	}

	{
		std::shared_ptr<SmartPointer> copy;
		{
			std::shared_ptr<SmartPointer> sharePointer = std::make_unique<SmartPointer>();
			//通过引用计数的方式，在引用数为0时删除该指针          此时为1
			copy = sharePointer;          //此时为2
		}          //此时为1
	}          //此时为0

	{
		std::weak_ptr<SmartPointer> copy;
		{
			std::shared_ptr<SmartPointer> sharePointer = std::make_unique<SmartPointer>();
			//通过引用计数的方式，在引用数为0时删除该指针          此时为1
			copy = sharePointer;          //weak_ptr不会增加引用计数 此时为1
		}          //此时为0
	}


	std::cout << "" << std::endl;
	std::cout << "================================  Template  ================================" << std::endl;

	Template<std::string, 5> template_Array;
	std::cout << template_Array.GetSize() << std::endl;


	std::cout << "" << std::endl;
	std::cout << "================================  Thread  ================================" << std::endl;
	std::thread worker(DoWork);          //创建了一个std::thread对象worker，并启动了一个新线程来运行Dowork函数
	
	std::cin.get();

	s_Finished = true;

	worker.join();          //join()——等待work表示的线程结束
	std::cout << "Finished!" << std::endl;
	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;


	std::cout << "" << std::endl;
	std::cout << "================================  Time  ================================" << std::endl;
	using namespace std::literals::chrono_literals;
	
	auto start_time = std::chrono::high_resolution_clock::now();          //当前时间
	std::this_thread::sleep_for(2s);
	auto end_time = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> duration = end_time - start_time;          //duration高精度
	
	std::cout << duration.count() << "s" << std::endl;

	{
		Timer timer;
		for (int i = 0; i < 10; i++)
		{
			std::cout << i << " ";
		}
		std::cout << "" << std::endl;
	}


	std::cout << "" << std::endl;
	std::cout << "================================  Sort  ================================" << std::endl;
	std::vector<int> sort_vectors = { 3,1,6,5,2 };
	std::sort(sort_vectors.begin(), sort_vectors.end());          //对于整数，默认升序排序

	for (int i = 0; i < sort_vectors.size(); i++)
	{
		std::cout << sort_vectors[i] << " ";
	}
	std::cout << "" << std::endl;

	std::cout << "" << std::endl;
	std::cout << "Waiting..." << std::endl;
	std::cin.get();
}