#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

#include <iostream>
#include <string>

template<typename T>

void Print(T value)
{
	std::cout << value << std::endl;
}

template<typename T,int N>

class Template
{
private:
	T m_Array[N];

public:
	int GetSize() const { return N };
};

#endif // !__TEMPLATE_H__