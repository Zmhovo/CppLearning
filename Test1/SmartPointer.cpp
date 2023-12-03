#include "SmartPointer.h"

SmartPointer::SmartPointer()
{
	std::cout << "Created!" << std::endl;
}

SmartPointer::~SmartPointer()
{
	std::cout << "Destoryed!" << std::endl;
}

void SmartPointer::Print()
{
	std::cout << "Printed!" << std::endl;
}
