#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string>
#include "Log.h"

class Player
{
public:
	int x, y, speed;

	Player();          //构造函数

	Player(int a, int b, int s);          //重载构造函数

	~Player();          //析构函数

	virtual void Move(int xa, int ya);          //虚函数

	virtual std::string GetName() = 0;          //接口(纯虚函数)，强制子类实现
};



class PlayerSon : public Player        //继承
{
public:
	const char* Name;

	PlayerSon();

	void Move(int xa, int ya) override;          //虚函数

	std::string GetName() override;          //子类实现纯虚函数

	void PrintName();
};

#endif