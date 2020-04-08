#include "stdafx.h"
#include "LinkStack.h"

//����һ����ջS
bool InitStack(LinkStack &S)
{
	S = NULL;
	return true;
}

bool Push(LinkStack & S, int e)
{
	LinkStack p;
	p = new Snode;
	p->data = e;
	p->next = S;								//����ǰ�ڵ�ŵ�S֮��
	S = p;											//ջ��ָ��ǰ��
	return true;
}

bool Pop(LinkStack & S, int & e)
{
	LinkStack p;
	if (S == NULL)
		return false;									//��ջ
	e = S->data;
	p = S;												//ץȡջ��
	S = S->next;										//ջ������
	delete p;											//ɾ���ɵ�ջ��
	return true;
}

int GetTop(LinkStack & S)
{
	if (S != NULL)									//�ǿ�ջ
		return S->data;							//����ջ��Ԫ��
	else
		return -1;
	return 0;
}

void LinkStackTest()
{
	LinkStack S;
	InitStack(S);
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	std::cout << "��ջ˳��Ϊ:" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl << "��ջ˳��Ϊ:" << std::endl;
	for (int i = 0; i < 10; i++)
		Push(S, arr[i]);
	std::cout << S << std::endl;
	if (S==NULL)
		std::cout << "��ջ�����" << std::endl;
}

ostream & operator<<(ostream & out, LinkStack & S)
{
	// TODO: �ڴ˴����� return ���
	int e;
	while (S != NULL)
	{
		Pop(S,e);
		out << e<< " ";
	}
	return out;
}
