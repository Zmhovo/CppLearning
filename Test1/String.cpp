#include "String.h"

void GetName()
{
	const char* name1 = "First";
	std::cout << name1 << std::endl;
	//const wchar_t * name1 = L"First";          ¿í×Ö·û
	//const char16_t * name1 = u"First";          utf_16×Ö·û
	//const char32_t * name1 = U"First";          utf_32×Ö·û


	char name2[7] = { 's','e','c','o','n','d',0 };
	std::cout << name2 << std::endl;

	name2[0] = 'S';
	std::cout << name2 << std::endl;

	std::string name3 = "Thir";
	std::cout << name3 << std::endl;
	std::cout << "name3's length:" << name3.length() << std::endl;

	name3 += "d";
	std::cout << name3 << std::endl;
	std::cout << "name3's length:" << name3.length() << std::endl;

	std::cout << name3.find("T") << std::endl;          //²éÕÒÊ×´Î³öÏÖÎ»ÖÃ
	std::cout << std::string::npos << std::endl;

	using namespace std::string_literals;
	std::wstring name4 = L"Four"s + L"th";

	const char* name5 = R"(name1
name2
name3
name4)";          //ºöÂÔ×ªÒå×Ö·û
	std::cout << name5 << std::endl;
}

void UpToLow(std::string& string)
{
	for (int i = 0; i < string.length(); i++)
	{
		if(string[i] >= 65 && string[i] <= 90)
		{
			string[i] += 32;
		}
	}
}
