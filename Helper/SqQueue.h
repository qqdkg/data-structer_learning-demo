#ifndef SQQUEUE_H
#define SQQUEUE_H


#define Maxsize 100
typedef int ElemType;


//ѭ�����нṹ
typedef struct SqQueue {
	ElemType *base;
	int front, rear;
}SqQueue;

bool InitQueue(SqQueue &Q);
bool EnQueue(SqQueue &Q, int e);
bool DeQueue(SqQueue &Q,int &e);
int GetHead(SqQueue &Q);
int QueueLength(SqQueue &Q);


#endif // !SQQUEUE_H
