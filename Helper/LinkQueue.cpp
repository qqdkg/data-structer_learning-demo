#include "stdafx.h"
#include "LinkQueue.h"

//��ʼ��
void InitQueue(LinkQueue & Q)
{
	Q.front = Q.rear = new Qnode;						//�����ڵ㣬ͷָ���βָ��ָ��ڵ�
	Q.front = NULL;
}

//���
void EnQueue(LinkQueue & Q, int e)
{
	Qptr s = new Qnode;
	s->data = e;
	s->data = NULL;
	Q.rear->next = s;								//���½ڵ��������
	Q.rear = s;										//ָ����λ
}

//����
bool DeQueue(LinkQueue &Q, int & e)
{
	Qptr p;
	if (Q.front = Q.rear)
		return false;												//�ն�
	p = Q.front->next;
	e = p->data;
	Q.front = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;										//���Q��ֻ��һ��Ԫ��
	delete p;
	return true;
}

//ȡ��Ԫ��
int GetHead(LinkQueue & Q)
{
	if (Q.front != Q.rear)
		return Q.front->data;
	return -1;
}

