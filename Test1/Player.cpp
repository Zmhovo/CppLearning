#include "Player.h"

Player::Player()
{
	x = 0;
	y = 0;
	speed = 1;
}

Player::Player(int a, int b, int s)
{
	x = a;
	y = b;
	speed = s;
}

Player::~Player()
{
	LogOutput("ÒÑÏú»Ù");
}

void Player::Move(int xa, int ya)
{
	x += xa;
	y += ya;
}

PlayerSon::PlayerSon()
{
	Name = "son's name";
}

void PlayerSon::Move(int xa, int ya)
{
	x += xa;
	y += ya;
}

std::string PlayerSon::GetName()
{
	return std::string(Name);
}

void PlayerSon::PrintName()
{
	std::cout << Name << std::endl;
}

