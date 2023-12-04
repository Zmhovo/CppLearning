#ifndef __CONST_H__
#define __CONST_H__

#include <iostream>
#include <string>

using String = std::string;

class ConstTest
{
private :
	String m_Name;
	mutable int m_DebugCount;          //mutable:�ɸı��
public:
	ConstTest();

	ConstTest(const String& name, int debugCount);

	const String& GetName() const;
};

#endif // !__CONST_H__

