#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <iostream>
#include <array>
#include <vector>

class Array
{
public:
	static const int exampleSize = 5;          //定义数组大小
	int example[exampleSize];          //创建数组1

	std::array<int, 5> another;          //创建数组2

	Array();
	~Array();

};

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z);
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex);          //重载“<<”

#endif // !__ARRAY_H__
