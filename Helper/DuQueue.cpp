#include "stdafx.h"
#include "DuQueue.h"
#include<iostream>

//��ʼ��
void InitQueue(DuQueue & Q)
{
	Q.front = 0;
	Q.rear = 0;
}

//�ж��Ƿ����
bool isFull(DuQueue Q)
{
	if ((Q.rear + 1) % Maxsize == Q.front)							//���rear+1==front�������Ҫ��maxsizeȡ��
		return true;
	else
		return false;
}



//β�����
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
	Q.rear = (Q.rear - 1 + Maxsize) % Maxsize;		//��βָ����ǰ�ƶ�һλ
	x = Q.base[Q.rear];											//ȡ����
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
	int temp = Q.front;								//��ʱ����
	while (temp != Q.rear)
	{
		std::cout << Q.base[temp] << "\t";
		temp = (temp + 1) % Maxsize;
	}
	std::cout << std::endl << "traverse is over!" << std::endl;
}




