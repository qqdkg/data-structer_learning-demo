#ifndef LINKSTACK_H
#define LINKSTACK_H
#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct Snode {
	ElemType data;
	struct Snode *next;					//������Ҫ��ָ��������ʾ������ʹ�ò����������͡�
}Snode,*LinkStack;

bool InitStack(LinkStack &S);

bool Push(LinkStack &S, int e);

bool Pop(LinkStack &S,int &e);

int GetTop(LinkStack &S);

void LinkStackTest();

ostream& operator<<(ostream &out,LinkStack &S);

#endif // !LINKSTACK_H
