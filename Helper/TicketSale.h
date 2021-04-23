#pragma once

// ================================================================================
// 一个多线程实例 —— 火车票售卖系统


#include <windows.h>
#include <iostream>
#include <strstream>
#include <string>

using std::cout;
using std::string;
using std::endl;

#define NAME_LINE		40

// 线程函数的参数结构体，描述某一地区到另一地区的车票
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


// 将基本类型数据转换成字符串
template<class T>
string convertToString(const T val)
{
	string buff;
	std::strstream strio;
	strio << val;
	strio >> buff;
	return buff;
}


//  售票程序声明(一个线程函数)
DWORD WINAPI SaleTicket(LPVOID lpParam);


// 测试程序
void TestProg();


