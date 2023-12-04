#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string>
#include "Log.h"

class Player
{
public:
	int x, y, speed;

	Player();          //���캯��

	Player(int a, int b, int s);          //���ع��캯��

	~Player();          //��������

	virtual void Move(int xa, int ya);          //�麯��

	virtual std::string GetName() = 0;          //�ӿ�(���麯��)��ǿ������ʵ��
};



class PlayerSon : public Player        //�̳�
{
public:
	const char* Name;

	PlayerSon();

	void Move(int xa, int ya) override;          //�麯��

	std::string GetName() override;          //����ʵ�ִ��麯��

	void PrintName();
};

#endif