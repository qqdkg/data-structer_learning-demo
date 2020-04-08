#include "stdafx.h"
#include "SqStack.h"

//顺序栈初始化
bool InitStack(SqStack & S)
{
	S.base = new int[MaxSize];
	if (!S.base)													//如果内存分配失败
		return false;
	S.top = S.base;									//栈顶指针初始为基地址，表示空栈
	return true;
}

//入栈
bool Push(SqStack &S, int e)
{
	if (S.top - S.base >= MaxSize)
		return false;
	*S.top = e;
	S.top++;
	return true;
}

//出栈e为返回值
bool Pop(SqStack & S, int &e)
{
	if (S.top == S.base)
		return false;
	S.top--;
	e = *S.top;
	return true;
}

bool Pop(SqStack & S, char & e)
{
	if (S.top == S.base)
		return false;
	S.top--;
	e = *S.top;
	return true;
}

int GetTop(SqStack & S)
{
	if (S.top != S.base)
		return *(S.top - 1);						//返回栈中第一个元素，栈顶指针不变
	else
		return -1;
}

bool Empty(SqStack S)
{
	if (S.top == S.base)
		return true;
	return false;
}

void SqStackTest()
{
	SqStack S;
	InitStack(S);
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	std::cout << "入栈顺序为:" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << " ";
	std::cout <<std::endl<< "出栈顺序为:" << std::endl;
	for (int i = 0; i < 10; i++)
		Push(S,arr[i]);
	std::cout << S<<std::endl;
	if (S.top == S.base)
		std::cout << "堆栈已清空"<<std::endl;
}

std::ostream & operator<<(std::ostream & out, SqStack &S)
{
	// TODO: 在此处插入 return 语句
	if (S.top > S.base)
	{
		S.top--;
		while (S.top > S.base)
		{
			out << *(S.top) << " ";
			S.top--;
		}
		std::cout << *(S.top) << " ";
	}
	return out;
}

//二进制转换程序
void binaryConversion(int n)
{
	SqStack S;
	int e;									//用于接收弹出的变量
	InitStack(S);						//初始化一个栈
	while (n)
	{
		Push(S, n % 2);
		n = n / 2;
	}
	while (!Empty(S))
	{
		Pop(S, e);
		std::cout << e ;
	}

}

//十六进制转换程序
void hexConversion(int n)
{
	SqStack S;
	InitStack(S);					//初始化一个栈
	int e;								//接收弹出
	while (n)
	{
		Push(S, n % 16);
		n = n / 16;
	}
	while (!Empty(S))
	{
		Pop(S, e);
		if(e<=9)
			std::cout << e;			//输出接收
		else
		{
			switch (e)
			{
			case 10:std::cout << "A"; break;
			case 11:std::cout << "B"; break;
			case 12:std::cout << "C"; break;
			case 13:std::cout << "D"; break;
			case 14:std::cout << "E"; break;
			case 15:std::cout << "F"; break;
			}
		}
	}
}

//回文判断
bool palindrome(char * str)
{
	SqStack S;
	int len, i;							// 长度记录变量，计数变量
	char e;								//弹出记录变量
	len = strlen(str);
	InitStack(S);						//栈初始化
	for (i = 0; i < len / 2; i++)
	{
		Push(S, str[i]);				//把char类型的数据赋值给了int类型数据
	}
	if (len % 2 == 1)				//如果是奇数，跳过中心点
		 i++;
	while (!Empty(S))
	{
		Pop(S, e);
		if (e != str[i])
		{
			std::cout << "输入非回文";
			return false;
		}
		else
			i++;
	}
	std::cout << "输入为回文";
	return true;
}

