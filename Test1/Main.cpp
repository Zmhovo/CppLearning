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

	std::vector<Vertex> vertices;          //��̬����
	//vertices.push_back({ 1,2,3 });          push_back()���ڴ�����ʱ������{ 1,2,3 }���ٿ�������vertices
	//vertices.push_back({ 4,5,6 });
	//vertices.push_back({ 7,8,9 });
	//�Ż���������
	vertices.reserve(3);          //reserve()Ԥ����洢�ռ�
	vertices.emplace_back(1, 2, 3);          //emplace_back()ֱ����verticesβ������
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


	ConstTest constname1("First",0);          //��ջ�ϴ������󣬻����Ž������������ڽ���
	std::cout << constname1.GetName() << std::endl;
	
	ConstTest* constname2 = new ConstTest("Second",10);          //�ڶ��ϴ���������������ֱ����delete()
	std::cout << constname2->GetName() << std::endl;
	delete(constname2);


	{
		std::unique_ptr<SmartPointer> uniquePointer = std::make_unique<SmartPointer>();
		//Ҳ��ʹ��std::unique_ptr<SmartPointer> uniquePointer(new SmartPointer());          ��Ҫ��ʽת��������ʹ�á�= new SmartPointer()��
		//unique_ptr��ζ�Ų��ɱ����ƣ�������ʹ�á�std::unique_ptr<SmartPoniter> copy = uniquePoint��
		uniquePointer->Print();

	}

	{
		std::shared_ptr<SmartPointer> copy;
		{
			std::shared_ptr<SmartPointer> sharePointer = std::make_unique<SmartPointer>();
			//ͨ�����ü����ķ�ʽ����������Ϊ0ʱɾ����ָ��          ��ʱΪ1
			copy = sharePointer;          //��ʱΪ2
		}          //��ʱΪ1
	}          //��ʱΪ0

	{
		std::weak_ptr<SmartPointer> copy;
		{
			std::shared_ptr<SmartPointer> sharePointer = std::make_unique<SmartPointer>();
			//ͨ�����ü����ķ�ʽ����������Ϊ0ʱɾ����ָ��          ��ʱΪ1
			copy = sharePointer;          //weak_ptr�����������ü��� ��ʱΪ1
		}          //��ʱΪ0
	}


	std::cout << "" << std::endl;
	std::cout << "================================  Template  ================================" << std::endl;

	Template<std::string, 5> template_Array;
	std::cout << template_Array.GetSize() << std::endl;


	std::cout << "" << std::endl;
	std::cout << "================================  Thread  ================================" << std::endl;
	std::thread worker(DoWork);          //������һ��std::thread����worker����������һ�����߳�������Dowork����
	
	std::cin.get();

	s_Finished = true;

	worker.join();          //join()�����ȴ�work��ʾ���߳̽���
	std::cout << "Finished!" << std::endl;
	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;


	std::cout << "" << std::endl;
	std::cout << "================================  Time  ================================" << std::endl;
	using namespace std::literals::chrono_literals;
	
	auto start_time = std::chrono::high_resolution_clock::now();          //��ǰʱ��
	std::this_thread::sleep_for(2s);
	auto end_time = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> duration = end_time - start_time;          //duration�߾���
	
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
	std::sort(sort_vectors.begin(), sort_vectors.end());          //����������Ĭ����������

	for (int i = 0; i < sort_vectors.size(); i++)
	{
		std::cout << sort_vectors[i] << " ";
	}
	std::cout << "" << std::endl;

	std::cout << "" << std::endl;
	std::cout << "Waiting..." << std::endl;
	std::cin.get();
}