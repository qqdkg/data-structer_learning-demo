#include "stdafx.h"
#include "LinkQueue.h"

//初始化
void InitQueue(LinkQueue & Q)
{
	Q.front = Q.rear = new Qnode;						//创建节点，头指针和尾指针指向节点
	Q.front = NULL;
}

//入队
void EnQueue(LinkQueue & Q, int e)
{
	Qptr s = new Qnode;
	s->data = e;
	s->data = NULL;
	Q.rear->next = s;								//把新节点接入链表
	Q.rear = s;										//指针移位
}

//出队
bool DeQueue(LinkQueue &Q, int & e)
{
	Qptr p;
	if (Q.front = Q.rear)
		return false;												//空队
	p = Q.front->next;
	e = p->data;
	Q.front = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;										//如果Q中只有一个元素
	delete p;
	return true;
}

//取首元素
int GetHead(LinkQueue & Q)
{
	if (Q.front != Q.rear)
		return Q.front->data;
	return -1;
}

