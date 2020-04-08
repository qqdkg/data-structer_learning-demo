#include "stdafx.h"
#include "DuQueue.h"
#include<iostream>

//初始化
void InitQueue(DuQueue & Q)
{
	Q.front = 0;
	Q.rear = 0;
}

//判断是否队满
bool isFull(DuQueue Q)
{
	if ((Q.rear + 1) % Maxsize == Q.front)							//如果rear+1==front，测队满要对maxsize取余
		return true;
	else
		return false;
}



//尾部入队
bool push_back(DuQueue & Q, ElemType e)
{
	if (isFull(Q))
		return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Maxsize;
	return true;
}

bool pop_back(DuQueue & Q, ElemType & x)
{
	if (isEmpty(Q))
		return false;
	Q.rear = (Q.rear - 1 + Maxsize) % Maxsize;		//队尾指针向前移动一位
	x = Q.base[Q.rear];											//取数据
	return true;
}

bool push_front(DuQueue & Q, ElemType e)
{
	if (isFull(Q))
		return false;
	Q.front = (Q.front - 1 + Maxsize) % Maxsize;
	Q.base[Q.front] = e;
	return true;
}

bool get_front(DuQueue & Q, ElemType & x)
{
	if (isEmpty(Q))
		return false;
	x = Q.base[Q.front];
	return true;
}

bool get_back(DuQueue & Q, ElemType & x)
{
	if (isEmpty(Q))
		return false;
	x = Q.base[(Q.rear - 1 + Maxsize) % Maxsize];
	return true;
}

void travers(DuQueue Q)
{
	if (isEmpty(Q))
	{
		std::cout << "DuQueue is empty,return!"<<std::endl;
		return;
	}
	int temp = Q.front;								//临时变量
	while (temp != Q.rear)
	{
		std::cout << Q.base[temp] << "\t";
		temp = (temp + 1) % Maxsize;
	}
	std::cout << std::endl << "traverse is over!" << std::endl;
}




