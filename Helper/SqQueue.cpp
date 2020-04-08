#include "stdafx.h"
#include "SqQueue.h"

//��ʼ��
bool InitQueue(SqQueue & Q)
{
	Q.base = new int[Maxsize];				//�����ڴ�ռ�
	if (!Q.base)
		return false;
	Q.front = Q.rear = 0;
	return true;
}

//���
bool EnQueue(SqQueue & Q, int e)
{
	if ((Q.rear + 1) % Maxsize == Q.front)										//��β����һ���Ƕ���
		return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1)%Maxsize;													//���ƣ���ѭ��
	return true;
}

//����
bool DeQueue(SqQueue & Q, int & e)
{
	if (Q.front == Q.rear)
		return false;										//�ն�
	e = Q.base[Q.front];								//����Ԫ��
	Q.front=(Q.front+1)%Maxsize;				//����
	return true;
}

//����ͷԪ�أ�ָ�벻�ƶ�
int GetHead(SqQueue & Q)
{
	if(Q.front!=Q.rear)								//�ǿն���
		return Q.base[Q.front];
	return -1;
}

//���ض��г���
int QueueLength(SqQueue & Q)
{
	return (Q.rear - Q.front + Maxsize) % Maxsize;
}


