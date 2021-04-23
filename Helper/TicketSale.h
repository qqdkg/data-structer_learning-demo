#pragma once

// ================================================================================
// һ�����߳�ʵ�� ���� ��Ʊ����ϵͳ


#include <windows.h>
#include <iostream>
#include <strstream>
#include <string>

using std::cout;
using std::string;
using std::endl;

#define NAME_LINE		40

// �̺߳����Ĳ����ṹ�壬����ĳһ��������һ�����ĳ�Ʊ
typedef struct __TICKET
{
	int nCount;
	char strTicketName[NAME_LINE];
	__TICKET() : nCount(0)
	{
		memset(strTicketName, 0, NAME_LINE * sizeof(char));
	}
} TICKET;

typedef struct __THD_DATA
{
	TICKET *pTicket;
	char strThreadName[NAME_LINE];

	__THD_DATA() : pTicket(nullptr)
	{
		memset(strThreadName, 0, NAME_LINE * sizeof(char));
	}
} THD_DATA;


// ��������������ת�����ַ���
template<class T>
string convertToString(const T val)
{
	string buff;
	std::strstream strio;
	strio << val;
	strio >> buff;
	return buff;
}


//  ��Ʊ��������(һ���̺߳���)
DWORD WINAPI SaleTicket(LPVOID lpParam);


// ���Գ���
void TestProg();


