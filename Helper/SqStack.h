#ifndef SQSTACK_H
#define SQSTACK_H
#include<iostream>

#define MaxSize 100

typedef int ElemType;

typedef struct SqStack {
	ElemType *base;
	ElemType *top;
}SqStack;

bool InitStack(SqStack &S);

bool Push(SqStack &S, int e);

bool Pop(SqStack &S,int &e);

bool Pop(SqStack &S, char &e);

int GetTop(SqStack &S);

bool Empty(SqStack S);

void SqStackTest();

std::ostream& operator<<(std::ostream &out,SqStack &S);

//栈的相关应用

void binaryConversion(int n);

void hexConversion(int n);

bool palindrome(char *str);

#endif // !SQSTACK_H
