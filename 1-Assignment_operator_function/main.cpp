#include <iostream>
#include "CMyString.h"
#include <string>

using namespace std;

int main() {

	string testStr = "abcd";
	CMyString str1((char*)testStr.c_str());
	CMyString str2(str1);
	CMyString str3("efgh");

	//// initial
	cout << "str1:";
	str1.show();
	cout << "str2:";
	str2.show();
	cout << "str3:";
	str3.show();

	//// test construct
	str2 = str3;
	cout << "str1:";
	str1.show();
	cout << "str2:";
	str2.show();
	cout << "str3:";
	str3.show();

	// test final
	str1 = str2 = str3 = CMyString("hhhh");
	cout << "str1:";
	str1.show();
	cout << "str2:";
	str2.show();
	cout << "str3:";
	str3.show();


	return 0;
}