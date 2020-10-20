#include "stdafx.h"
#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stack>
#include <vector>
#include "YJHelper.h"
using namespace std;



typedef unsigned char BYTE;
typedef enum Color {
	RED = 0X01,
	Bc,
	G,
	Y,
	BL
}color_e;

typedef struct Seden {
	bool a;
	color_e co;
	bool is;
	double p;
	BYTE se;
}Sedan_s;

void HelloWorld()
{
	/*Sedan_s se;
	cout << sizeof(se) << endl;*/
}

int FindMaxSub::Find()
{
	int temp = 0;;
	for (int i = 0; i < n; i++)
		for (int t = i; t < n; t++)
		{
			if (temp <= (x[i].num - x[t].num))
			{
				temp = (x[i].num - x[t].num);
			}
		}
	return temp;
}

void FindMaxSub::Init()
{
	cout << "请输入车厢数n：" << endl;
	cin >> n;
	cout << "请输入各个车厢的人数" << endl;
	for (int i = 0; i < n; i++)
	{
		x[i].order = i;
		cin >> x[i].num;
	}
}

void FindMaxSub::FMSTest()
{
	Init();
	cout << "最大差值为：" << Find() << "人" << endl;
}


void test(char * p)
{
	int k = 0;
	do 																		//'\0'为c的字符串结束符
	{
		if (k == 0 && *p != ' ')
		{
			*p = toupper(*p);
			k = 1;
		}
		else if (*p != ' ')
			k = 1;
		else
			k = 0;
		*p++;
	} while (*p != '\0');
}

void mainTest()
{
	char str[81];
	cout << "Please input a English text line :" << endl;
	gets_s(str, sizeof(str));
	cout << endl;
	cout << "The original text line is :" << endl;
	puts(str);
	cout << endl;
	test(str);
	cout << "The new text line is :" << endl;
	puts(str);
	cout << endl;
}

void EncodeingTank::Init()
{
	cout << "请输入待加密字符个数" << endl;
	cin >> n;
	cout << "请分别输入相应的带编码字符" << endl;
	stack<int> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> str[i].ch;
		str[i].ascii = (int)str[i].ch;
		int ascii = str[i].ascii;
		for (int j = 0; j < 8; j++)
		{
			if (ascii != 0)
			{
				int a = ascii % 2;
				ascii = ascii / 2;
				s.push(a);
			}
			else
			{
				s.push(0);
			}
		}
		for (int j = 0; j < 8; j++)
		{
			str[i].bin[j] = s.top();													//取出二进制的每一位
			s.pop();
		}
	}

	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "字符：" << str[i].ch << " 对应的ASCII码：" << str[i].ascii << " ";
		cout << "二进制编码：";
		for (int j = 0; j < 8; j++)
		{
			cout << str[i].bin[j];
		}
		cout << endl;
	}
}

void EncodeingTank::Encoding()
{
	//=====第一步，生成整体的二进制序列并补0
	int n_zero = 3 - ((n * 8) % 3);														//用于计算二进制序列末尾需要补0的个数
	int binor = 1;																			//二进制序列赋值位置标记"Binaryorder"的简称"binor"
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			binArr[binor] = str[i].bin[j];												//将每个字符结点中的二进制编码整合到总体二进制序列中
			binor++;
		}
	}
	if (n_zero > 0 && n_zero < 3)													//末尾补0
	{
		for (int i = 1; i <= n_zero; i++)
		{
			binArr[binor] = 0;
			binor++;
		}
	}
	//===== 第二步，将二进制序列翻译为加密后的编码
	ncode = ((n * 8) / 3);
	if (n_zero > 0)
		ncode++;																				//如果需要补0，说明最终的编码量会多一个
	binor = 1;																					//二进制序列标记指向头
	for (int i = 1; i <= ncode; i++)
	{
		int keynum = 0;
		for (int j = 1; j <= 3; j++)
		{
			if (j == 1 && binArr[binor] == 1)
				keynum = keynum + 4;
			if (j == 2 && binArr[binor] == 1)
				keynum = keynum + 2;
			if (j == 3 && binArr[binor] == 1)
				keynum = keynum + 1;
			binor++;																				//二进制序列标记后移
		}
		enumKey = (eKey)keynum;														//switch使用enum作为case可以更直观
		switch (keynum) {
		case ch_A:
			outch[i] = 'A';
			break;
		case ch_B:
			outch[i] = 'B';
			break;
		case ch_C:
			outch[i] = 'C';
			break;
		case ch_D:
			outch[i] = 'D';
			break;
		case ch_a:
			outch[i] = 'a';
			break;
		case ch_b:
			outch[i] = 'b';
			break;
		case ch_c:
			outch[i] = 'c';
			break;
		case ch_d:
			outch[i] = 'd';
			break;
		default:
			cout << "可能出问题了。" << endl;
		}
	}
}

void EncodeingTank::ETest()
{
	Init();
	Encoding();
	cout << endl;
	cout << "加密后的字符串为：";
	for (int i = 1; i <= ncode; i++)
	{
		cout << outch[i];
	}
	cout << endl << endl;
}


string Solution::MyCompress(string str)
{
	// write your code here
	int index;
	int count = 1;
	string compressStr = "";
	int compressIndex = 0;

	if (str.size() == 0)
		return str;

	for (index = 0; index<str.size(); index++)
	{

		if (1 == count)
		{
			compressStr += str[index];
			compressIndex++;
		}
		if (str[index] == str[index + 1])
		{
			count++;
			continue;
		}
		if (count != 1)
		{
			compressStr += to_string(count);
		}
		compressIndex++;
		count = 1;
	}

	if (compressStr.size() >= str.size())
		return str;
	else
		return compressStr;
}

string Solution::dkgCompress(string pcStr)
{
	string pressStr;
	int count = 1;
	int cpindex = 0;																		//字符复制位置

	if (pcStr.size() == 0)
		return pcStr;

	for (int i = 1; i < pcStr.size(); i++)
	{
		if (pcStr[cpindex] != pcStr[i])
		{
			//如果当前复制位置与遍历位置的字符不相等，只有两种情况
			//1.当前赋值位置的字符指出现了一次（count == 1），此时直接将当前赋值位置的字符复制给压缩字符串
			//2.当前赋值位置的字符出现了不止一次。则将赋值位置的字符和其出现的次数count加入压缩字符串
			if (count == 1)
			{
				pressStr += pcStr[cpindex];
				cpindex = i;
			}
			else
			{
				pressStr += pcStr[cpindex];
				pressStr += to_string(count);
				cpindex = i;															//当前赋值位置字符去到i位置
				count = 1;															//count置为1
			}
		}
		else
		{
			count++;
		}
	}

	//处理结尾部分
	if (count == 1)
	{
		pressStr += pcStr[cpindex++];
	}
	else
	{
		pressStr += pcStr[cpindex++];
		pressStr += to_string(count);
	}

	return pressStr;
}

void Solution::Test()
{
	string str;
	Solution s;
	cin >> str;
	cout << s.dkgCompress(str) << endl;
}

long long findMidTank::MidFactor(long long llVal)
{
	vector<long long> numArr;
	for (long long i = 1; i <= llVal; i++)
	{
		if (llVal % i == 0)
			numArr.push_back(i);
	}
	int index = numArr.size() / 2;
	return numArr.at(index);
}

void findMidTank::findMidTest()
{
	long long llVal;
	cin >> llVal;
	cout << MidFactor(llVal) << endl;
}


