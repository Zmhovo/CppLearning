#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

#include <iostream>
#include <string>

template<typename T>

void Print(T value)
{
	std::cout << value << std::endl;
}

template<int N>

class Template
{
private:
	int m_Array[N];

public:
	int GetSize() const { return N };
};

#endif // !__TEMPLATE_H__