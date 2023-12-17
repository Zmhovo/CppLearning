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

	Template<std::string, 5> template_Array;
	std::cout << template_Array.GetSize() << std::endl;

	std::cout << "" << std::endl;

	std::cout << "" << std::endl;
	std::cout << "Waiting..." << std::endl;
	std::cin.get();
}