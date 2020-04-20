#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include"GreedySnake.h"
using namespace std;

int m[30][30];//��ͼ
Position here_g, next_g;
Position DIR[4] = { 0,1,1,0,0,-1,-1,0 };//�ҡ��¡����Ϸ�������

void Init(int n)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < n; j++)
			m[i][j] = 0;											//��ʼ�����ķ������Ϊ0

	for (int j = 0; j <= n + 1; j++)
		m[0][j] = m[n + 1][j] = -1;						//��ʼ����������߽�Ϊ-1
	
	for (int i = 0; i < n + 1; i++)
		m[i][0] = m[i][n + 1] = -1;						//��ʼ����������߽�Ϊ-1
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
	here_g.x = 1;		//���Ͻ��е����λ��
	here_g.y = 1;
	int dirIndex = 0;
	int num = 1;
	m[1][1] = 1;
	while (num < n*n)
	{
		next_g.x = here_g.x + DIR[dirIndex].x;
		next_g.y = here_g.y + DIR[dirIndex].y;
		if (m[next_g.x][next_g.y] == 0)									//�ж���һ��λ����û�е���
		{
			m[next_g.x][next_g.y] = ++num;							//���˵��������������ּ�һ
			here_g = next_g;
		}
		else
			dirIndex = (dirIndex + 1) % 4;								//��һ�����򣬰����ҡ��¡����ϵķ�������Ե���
	}
}

void GreedySnakeTest()
{
	int n = 0;
	cout << "���������1С��20������n:" << endl;
	cin >> n;
	while (n < 1 || n>20)
	{
		cout << "���������1С��20������n:" << endl;
		cin >> n;
	}
	Init(n);
	Print(0, n + 1);
	Solve(n);
	Print(1, n);
}
