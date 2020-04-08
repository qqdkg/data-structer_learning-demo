#include "stdafx.h"
#include "SqQueue.h"

//初始化
bool InitQueue(SqQueue & Q)
{
	Q.base = new int[Maxsize];				//分配内存空间
	if (!Q.base)
		return false;
	Q.front = Q.rear = 0;
	return true;
}

//入队
bool EnQueue(SqQueue & Q, int e)
{
	if ((Q.rear + 1) % Maxsize == Q.front)										//队尾的下一个是队首
		return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1)%Maxsize;													//后移，可循环
	return true;
}

//出队
bool DeQueue(SqQueue & Q, int & e)
{
	if (Q.front == Q.rear)
		return false;										//空队
	e = Q.base[Q.front];								//保存元素
	Q.front=(Q.front+1)%Maxsize;				//后移
	return true;
}

//返回头元素，指针不移动
int GetHead(SqQueue & Q)
{
	if(Q.front!=Q.rear)								//非空队列
		return Q.base[Q.front];
	return -1;
}

//返回队列长度
int QueueLength(SqQueue & Q)
{
	return (Q.rear - Q.front + Maxsize) % Maxsize;
}


