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

	//Array
	std::cout << "Array" << std::endl;

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

	Template<std::string, 5> template_Array;
	std::cout << template_Array.GetSize() << std::endl;

	std::cout << "" << std::endl;

	std::cout << "" << std::endl;
	std::cout << "Waiting..." << std::endl;
	std::cin.get();
}