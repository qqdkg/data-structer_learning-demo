#include "stdafx.h"
#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stack>
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
	Sedan_s se;
	cout << sizeof(se) << endl;
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
	cout << "�����복����n��" << endl;
	cin >> n;
	cout << "������������������" << endl;
	for (int i = 0; i < n; i++)
	{
		x[i].order = i;
		cin >> x[i].num;
	}
}

void FindMaxSub::FMSTest()
{
	Init();
	cout << "����ֵΪ��" << Find() << "��" << endl;
}


void test(char * p)
{
	int k = 0;
	do 																		//'\0'Ϊc���ַ���������
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
	cout << "������������ַ�����" << endl;
	cin >> n;
	cout << "��ֱ�������Ӧ�Ĵ������ַ�" << endl;
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
			str[i].bin[j] = s.top();													//ȡ�������Ƶ�ÿһλ
			s.pop();
		}
	}

	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "�ַ���" << str[i].ch << " ��Ӧ��ASCII�룺" << str[i].ascii << " ";
		cout << "�����Ʊ��룺";
		for (int j = 0; j < 8; j++)
		{
			cout << str[i].bin[j];
		}
		cout << endl;
	}
}

void EncodeingTank::Encoding()
{
	//=====��һ������������Ķ��������в���0
	int n_zero = 3 - ((n * 8) % 3);														//���ڼ������������ĩβ��Ҫ��0�ĸ���
	int binor = 1;																			//���������и�ֵλ�ñ��"Binaryorder"�ļ��"binor"
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			binArr[binor] = str[i].bin[j];												//��ÿ���ַ�����еĶ����Ʊ������ϵ����������������
			binor++;
		}
	}
	if (n_zero > 0 && n_zero < 3)													//ĩβ��0
	{
		for (int i = 1; i <= n_zero; i++)
		{
			binArr[binor] = 0;
			binor++;
		}
	}
	//===== �ڶ����������������з���Ϊ���ܺ�ı���
	ncode = ((n * 8) / 3);
	if (n_zero > 0)
		ncode++;																				//�����Ҫ��0��˵�����յı��������һ��
	binor = 1;																					//���������б��ָ��ͷ
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
			binor++;																				//���������б�Ǻ���
		}
		enumKey = (eKey)keynum;														//switchʹ��enum��Ϊcase���Ը�ֱ��
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
			cout << "���ܳ������ˡ�" << endl;
		}
	}

}

void EncodeingTank::ETest()
{
	Init();
	Encoding();
	cout << endl;
	cout << "���ܺ���ַ���Ϊ��";
	for (int i = 1; i <= ncode; i++)
	{
		cout << outch[i];
	}
	cout << endl << endl;
}
