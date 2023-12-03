#include "Const.h"

ConstTest::ConstTest()
	:m_Name("First"), m_DebugCount(0)          //��Ա��ʼ���б�
{
}

ConstTest::ConstTest(const String& name, int debugCount)
	:m_Name(name),m_DebugCount(debugCount)
{
}

const std::string& ConstTest::GetName() const
{ 
	//m_Name = "Second";          const������ı�ʵ�����Ա
	m_DebugCount++;          //mutable���ƹ�const�ı�ʵ�����Ա

	return m_Name;
}
