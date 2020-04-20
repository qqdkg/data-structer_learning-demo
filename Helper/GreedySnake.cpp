#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include"GreedySnake.h"
using namespace std;

int m[30][30];//地图
Position here_g, next_g;
Position DIR[4] = { 0,1,1,0,0,-1,-1,0 };//右、下、左、上方向数组

void Init(int n)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < n; j++)
			m[i][j] = 0;											//初始化中心方格矩阵为0

	for (int j = 0; j <= n + 1; j++)
		m[0][j] = m[n + 1][j] = -1;						//初始化上下拦阻边界为-1
	
	for (int i = 0; i < n + 1; i++)
		m[i][0] = m[i][n + 1] = -1;						//初始化左右拦阻边界为-1
}

void Print(int start, int endi)
{
	for (int i = start; i <= endi; i++)
	{
		cout << m[i][start];
		for (int j = start + 1; j <= endi; j++)
			cout << "\t" << m[i][j];
		cout << endl;
	}
	cout << endl;
}

void Solve(int n)
{
	here_g.x = 1;		//左上角有蛋糕的位置
	here_g.y = 1;
	int dirIndex = 0;
	int num = 1;
	m[1][1] = 1;
	while (num < n*n)
	{
		next_g.x = here_g.x + DIR[dirIndex].x;
		next_g.y = here_g.y + DIR[dirIndex].y;
		if (m[next_g.x][next_g.y] == 0)									//判断下一个位置有没有蛋糕
		{
			m[next_g.x][next_g.y] = ++num;							//吃了蛋糕拉出来的数字加一
			here_g = next_g;
		}
		else
			dirIndex = (dirIndex + 1) % 4;								//关一个方向，按照右、下、左、上的方向继续吃蛋糕
	}
}

void GreedySnakeTest()
{
	int n = 0;
	cout << "请输入大于1小于20的整数n:" << endl;
	cin >> n;
	while (n < 1 || n>20)
	{
		cout << "请输入大于1小于20的整数n:" << endl;
		cin >> n;
	}
	Init(n);
	Print(0, n + 1);
	Solve(n);
	Print(1, n);
}
