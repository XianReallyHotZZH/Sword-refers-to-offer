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

	// Ҫ���صĸ�ֵ�����
	CMyString& operator=(const CMyString& str);

	void show() {

		cout << this->m_pData << endl;
	}


private:
	
	char* m_pData;

};

/****************************************
---version1.0
---�ؼ��㣺
---1.��ֵ�������������Ӧ��Ϊ�����͵����ã�
---2.����Ӧ��Ϊ�����͵ĳ������ã�
---3.�ж������ʵ���Ƿ�Ϊ��ǰʵ����
---4.�������ڴ��ʱ��ǵ��ͷ����е��ڴ棻
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
---fix bug��"Exception Safety"
---bug�����ͷţ�����䣬�п��ܵ����ͷź�û����Ч������µĿռ������new�׳��쳣��ʹ��CMyString��ʵ�����ٱ�����Ч��״̬
---method������һ����ʱ���������Ű���ʱ������m_pData�������m_pData������Ȼ����ʱ�����Զ��������������ͷű������ڴ�
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

