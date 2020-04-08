#ifndef LINKQUEUE_H
#define LINKQUEUE_H

typedef int ElemType;

typedef struct Qnode {
	ElemType data;
	struct Qnode *next;
}Qnode,*Qptr;

//¡¥∂”¡–
typedef struct {
	Qnode *front;
	Qnode *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q);
void EnQueue(LinkQueue &Q, int e);
bool DeQueue(LinkQueue &Q, int &e);
int GetHead(LinkQueue &Q);

#endif // !LINKQUEUE_H
