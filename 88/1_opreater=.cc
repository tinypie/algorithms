//
//写一个类的赋值运算符函数
#include <iostream>
using namespace std;

class CmyString {
public:
	CmyString(char *pData = NULL);
	~CmyString();
	CmyString(const CmyString & str);
private:
	char *pData;
};

//这是一个异常不安全的，但多数教科书上是这么说的
CmyString &CmyString::operator=(const CmyString &str)
{
	if (this == &str)
		return *this;
	
	delete[] pData;
	pData = new char[strlen(str.pData)+1];
	strcpy(pData, str.pData);

	return *this;
}

// 考虑异常安全的解法
CmyString &CmyString::operator=(const CmyString &str)
{
	if (this != &str) {
		CmyString tmp(str);
		char *ptmp = tmp.pData;
		tmp.pData = pData;
		pData = ptmp;
	}

	return *this;
}


