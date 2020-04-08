#ifndef DUQUEUE_H
#define DUQUEUE_H

#define Maxsize 100
typedef int ElemType;

typedef struct SqQueue {

	ElemType base[Maxsize];
	int front, rear;
}DuQueue;

void InitQueue(DuQueue &Q);

bool isFull(DuQueue Q);

bool isEmpty(DuQueue Q) { return !isFull(Q); }

bool push_back(DuQueue &Q,ElemType e);

bool pop_back(DuQueue &Q,ElemType &x);

bool push_front(DuQueue &Q,ElemType e);

bool get_front(DuQueue &Q, ElemType &x);

bool get_back(DuQueue &Q, ElemType &x);

int length(DuQueue Q) { return (Q.rear - Q.front + Maxsize) % Maxsize; }

void travers(DuQueue Q);

#endif // !DuQueue
