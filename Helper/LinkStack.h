#ifndef LINKSTACK_H
#define LINKSTACK_H
#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct Snode {
	ElemType data;
	struct Snode *next;					//这里需要是指针否则会提示“不能使用不完整的类型”
}Snode,*LinkStack;

bool InitStack(LinkStack &S);

bool Push(LinkStack &S, int e);

bool Pop(LinkStack &S,int &e);

int GetTop(LinkStack &S);

void LinkStackTest();

ostream& operator<<(ostream &out,LinkStack &S);

#endif // !LINKSTACK_H
