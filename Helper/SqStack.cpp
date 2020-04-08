#include "stdafx.h"
#include "SqStack.h"

//˳��ջ��ʼ��
bool InitStack(SqStack & S)
{
	S.base = new int[MaxSize];
	if (!S.base)													//����ڴ����ʧ��
		return false;
	S.top = S.base;									//ջ��ָ���ʼΪ����ַ����ʾ��ջ
	return true;
}

//��ջ
bool Push(SqStack &S, int e)
{
	if (S.top - S.base >= MaxSize)
		return false;
	*S.top = e;
	S.top++;
	return true;
}

//��ջeΪ����ֵ
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
		return *(S.top - 1);						//����ջ�е�һ��Ԫ�أ�ջ��ָ�벻��
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
	std::cout << "��ջ˳��Ϊ:" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << " ";
	std::cout <<std::endl<< "��ջ˳��Ϊ:" << std::endl;
	for (int i = 0; i < 10; i++)
		Push(S,arr[i]);
	std::cout << S<<std::endl;
	if (S.top == S.base)
		std::cout << "��ջ�����"<<std::endl;
}

std::ostream & operator<<(std::ostream & out, SqStack &S)
{
	// TODO: �ڴ˴����� return ���
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

//������ת������
void binaryConversion(int n)
{
	SqStack S;
	int e;									//���ڽ��յ����ı���
	InitStack(S);						//��ʼ��һ��ջ
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

//ʮ������ת������
void hexConversion(int n)
{
	SqStack S;
	InitStack(S);					//��ʼ��һ��ջ
	int e;								//���յ���
	while (n)
	{
		Push(S, n % 16);
		n = n / 16;
	}
	while (!Empty(S))
	{
		Pop(S, e);
		if(e<=9)
			std::cout << e;			//�������
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

//�����ж�
bool palindrome(char * str)
{
	SqStack S;
	int len, i;							// ���ȼ�¼��������������
	char e;								//������¼����
	len = strlen(str);
	InitStack(S);						//ջ��ʼ��
	for (i = 0; i < len / 2; i++)
	{
		Push(S, str[i]);				//��char���͵����ݸ�ֵ����int��������
	}
	if (len % 2 == 1)				//������������������ĵ�
		 i++;
	while (!Empty(S))
	{
		Pop(S, e);
		if (e != str[i])
		{
			std::cout << "����ǻ���";
			return false;
		}
		else
			i++;
	}
	std::cout << "����Ϊ����";
	return true;
}

