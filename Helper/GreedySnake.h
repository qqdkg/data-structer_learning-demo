#ifndef GREEDYSNAKE_H
#define GREEDYSNAKE_H

typedef struct {
	int x;
	int y;
} Position;//λ��

void Init(int n);

void Print(int start,int endi);//start/endiΪ��ʼ�ͽ����±�

//n��ԭ�����ģ��m:��ͼ����
void Solve(int n);

void GreedySnakeTest();



#endif // !GREEDYSNAKE_H

