#ifndef __UNION_H__
#define __UNION_H__

#include <iostream>

struct Union1
{
	union          //ͨ��union������ʹ�õģ�����union���ܺ��г�Ա����
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
		struct          //�˴�������struct��һ�����ݽṹ
		{
			float x, y, z, w;
		};
		struct
		{
			Union2 a, b;          //a��x��y��b��z��wռ������ͬ���ڴ�
		};
	};
	//�ȼ���
	//float x, y, z, w;
	//
	//Union2& Get()
	//{
	//	  return *(Union2*)&x;
	//}
};

void PrintUnion2(const Union2& union2);

#endif // !__UNION_H__
