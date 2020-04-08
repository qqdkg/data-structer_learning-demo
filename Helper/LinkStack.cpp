#include "stdafx.h"
#include "LinkStack.h"

//构造一个空栈S
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
	p->next = S;								//将当前节点放到S之后
	S = p;											//栈顶指针前移
	return true;
}

bool Pop(LinkStack & S, int & e)
{
	LinkStack p;
	if (S == NULL)
		return false;									//空栈
	e = S->data;
	p = S;												//抓取栈顶
	S = S->next;										//栈顶后移
	delete p;											//删除旧的栈顶
	return true;
}

int GetTop(LinkStack & S)
{
	if (S != NULL)									//非空栈
		return S->data;							//返回栈顶元素
	else
		return -1;
	return 0;
}

void LinkStackTest()
{
	LinkStack S;
	InitStack(S);
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	std::cout << "入栈顺序为:" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl << "出栈顺序为:" << std::endl;
	for (int i = 0; i < 10; i++)
		Push(S, arr[i]);
	std::cout << S << std::endl;
	if (S==NULL)
		std::cout << "堆栈已清空" << std::endl;
}

ostream & operator<<(ostream & out, LinkStack & S)
{
	// TODO: 在此处插入 return 语句
	int e;
	while (S != NULL)
	{
		Pop(S,e);
		out << e<< " ";
	}
	return out;
}
