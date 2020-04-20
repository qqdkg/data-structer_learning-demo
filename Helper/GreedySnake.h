#ifndef GREEDYSNAKE_H
#define GREEDYSNAKE_H

typedef struct {
	int x;
	int y;
} Position;//位置

void Init(int n);

void Print(int start,int endi);//start/endi为开始和结束下标

//n：原问题规模、m:地图矩阵
void Solve(int n);

void GreedySnakeTest();



#endif // !GREEDYSNAKE_H

