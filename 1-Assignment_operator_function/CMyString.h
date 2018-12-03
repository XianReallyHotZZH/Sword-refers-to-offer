#pragma once

#ifndef CMYSTRING_H_
#define CMYSTRING_H_

#include <iostream>
#include <string>

using namespace std;

class CMyString {

public:

	CMyString(char* pData = nullptr) {
		if (pData != nullptr) {
			m_pData = new char[strlen(pData) + 1];
			strcpy(m_pData, pData);
		}
		else {
			m_pData = nullptr;
		}
	}

	CMyString(const CMyString& str) {
		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);
	}

	~CMyString() {
		delete[] m_pData;
	}

	// 要重载的赋值运算符
	CMyString& operator=(const CMyString& str);

	void show() {

		cout << this->m_pData << endl;
	}


private:
	
	char* m_pData;

};

/****************************************
---version1.0
---关键点：
---1.赋值运算符返回类型应该为该类型的引用；
---2.输入应该为该类型的常量引用；
---3.判断输入的实例是否为当前实例；
---4.分配新内存的时候记得释放已有的内存；
*****************************************/
//CMyString& CMyString::operator=(const CMyString& str) {
//
//	if (this == &str)
//		return *this;
//
//	delete[] m_pData;
//	m_pData = nullptr;
//
//	m_pData = new char[strlen(str.m_pData) + 1];
//	strcpy(m_pData, str.m_pData);
//
//	return *this;
//}

/****************************************
---version2.0
---fix bug："Exception Safety"
---bug：先释放，后分配，有可能导致释放后没有有效分配出新的空间而导致new抛出异常，使得CMyString的实例不再保持有效的状态
---method：创建一个临时变量，接着把临时变量的m_pData和自身的m_pData交换，然后临时变量自动调用析构函数释放本来的内存
*****************************************/
CMyString& CMyString::operator=(const CMyString& str) {

	if (this != &str) {

		CMyString strTemp(str);

		char* pTemp = strTemp.m_pData;
		strTemp.m_pData = this->m_pData;
		this->m_pData = pTemp;
	}

	return *this;
}


#endif // !CMYSTRING_H_

