#include "Const.h"

ConstTest::ConstTest()
	:m_Name("First"), m_DebugCount(0)          //成员初始化列表
{
}

ConstTest::ConstTest(const String& name, int debugCount)
	:m_Name(name),m_DebugCount(debugCount)
{
}

const std::string& ConstTest::GetName() const
{ 
	//m_Name = "Second";          const不允许改变实际类成员
	m_DebugCount++;          //mutable可绕过const改变实际类成员

	return m_Name;
}
