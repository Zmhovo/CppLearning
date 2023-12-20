#ifndef __UNION_H__
#define __UNION_H__

#include <iostream>

struct Union1
{
	union          //通常union是匿名使用的，匿名union不能含有成员函数
	{
		float a;
		int b;
	};
};

struct Union2
{
	float x, y;
};

struct Union3
{
	union
	{
		struct          //此处匿名的struct是一种数据结构
		{
			float x, y, z, w;
		};
		struct
		{
			Union2 a, b;          //a与x、y，b与z、w占用了相同的内存
		};
	};
	//等价于
	//float x, y, z, w;
	//
	//Union2& Get()
	//{
	//	  return *(Union2*)&x;
	//}
};

void PrintUnion2(const Union2& union2);

#endif // !__UNION_H__
