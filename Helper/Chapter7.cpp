#include "stdafx.h"
#include "Chapter7.h"
#include <iostream>
#include <math.h>
#include <iomanip>
#include <queue>
#include <stdio.h>
using namespace std;


void BestBenefitTank::print()
{
	cout << endl;
	cout << "---------------单纯性表如下：----------------" << endl;
	cout << "  ";
	cout << setw(7) << "b ";
	for (int i = 1; i <= m; i++)
		cout << setw(7) << "x" << FJL[i];
	cout << endl;
	cout << "c ";
	for (int i = 0; i <= n; i++)
	{
		if (i >= 1)
			cout << "x" << JL[i];
		for (int j = 0; j <= m; j++)
			cout << setw(7) << kernel[i][j] << " ";
		cout << endl;
	}
}

void BestBenefitTank::DCXA()
{
	float max1;													//max1用于存放最大的检验数
	float max2;													//max2用于存放最大正检验数对应的基本变量的最大系数
	int e = -1;														//记录入基列
	int k = -1;														//记录出基行
	float min;
	//循环迭代，直到找到问题的解或者无解为止
	while (true)
	{
		max1 = 0;
		max2 = 0;
		min = 100000000;
		for (int j = 1; j <= m; j++)							//找入基列（最大正检验数对应的列）
		{
			if (max1 < kernel[0][j])
			{
				max1 = kernel[0][j];
				e = j;
			}
		}
		if (max1 <= 0)											//最大值<=0，即所有检验数<=0，满足获得最优解的条件
		{
			cout << endl;
			cout << "获得最优解:" << kernel[0][0] << endl << endl;
			break;
		}
		for (int i = 1; i <= n; i++)							//找离基行（常数列/入基列 正比值最小的行）
		{
			if (max2 < kernel[i][e])
			{
				max2 = kernel[i][e];
			}
			float temp = kernel[i][0] / kernel[i][e];
			if (temp > 0 && temp < min)
			{
				min = temp;
				k = i;
			}
		}
		cout << "入基变量" << "x" << FJL[e] << " ";
		cout << "离基变量" << "x" << JL[k] << endl;
		if (max2 == 0)
		{
			cout << "解无界" << endl;
			break;
		}
		//变基变换（转轴变换）
		char temp = FJL[e];
		FJL[e] = JL[k];
		JL[k] = temp;
		for (int i = 0; i <= n; i++)										//计算除了入基列和出基行之外的所有元素
		{
			if (i != k)
			{
				for (int j = 0; j <= m; j++)
				{
					if (j != e)
					{
						if (i == 0 && j == 0)
							kernel[i][j] = kernel[i][j] + kernel[i][e] * kernel[k][j] / kernel[k][e];
						else
							kernel[i][j] = kernel[i][j] - kernel[i][e] * kernel[k][j] / kernel[k][e];;
					}
				}//=for (int j
			}//=if (i != k)
		}//=for (int i)
		for (int i = 0; i <= n; i++)														//计算特殊位置，入基列元素
		{
			if (i != k)
			{
				kernel[i][e] = -kernel[i][e] / kernel[k][e];
			}
		}
		for (int j = 0; j <= m; j++)														//计算特殊位置，离基行元素
		{
			if (j == e)
				kernel[k][j] = kernel[k][j] / kernel[k][e];
		}
		kernel[k][e] = 1 / kernel[k][e];												//计算特殊位置，交叉位置
		print();
	}
}

void BestBenefitTank::BBTTest()
{
	cout << "输入非基本变量的个数和非基本变量的下标：" << endl;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> FJL[i];
	}
	cout << "输入基本变量的个数和基本变量的下标：" << endl;
	cin >> n;
	for (int j = 1; j <= n; j++)
	{
		cin >> JL[j];
	}
	cout << "输入约束标准型初始单纯形表参数：" << endl;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			cin >> kernel[i][j];
		}
	}
	print();
	DCXA();
}

void BestBenefitTank::BBTTest2()
{
	cout << "输入非基本变量的个数和非基本变量的下标：" << endl;
	//cin >> m;]
	m = 3;
	cout << m << endl;
	char mArr[] = {'0', '2', '4', '5'};
	for (int i = 1; i <= m; i++)
	{
		//cin >> FJL[i];
		FJL[i] = mArr[i];
		cout << FJL[i] << " ";
	}
	cout << endl;
	cout << "输入基本变量的个数和基本变量的下标：" << endl;
	//cin >> n;
	n = 4;
	cout << n << endl;
	char nArr[] = {'0', '1', '3', '6', '7' };
	for (int j = 1; j <= n; j++)
	{
		//cin >> JL[j];
		JL[j] = nArr[j];
		cout << JL[j] << " ";
	}
	cout << endl;
	cout << "输入约束标准型初始单纯形表参数：" << endl;
	float cube[5][4] = { {0, 2.5, 2.8, 76.25}, {0, 1, 0, -5}, {0, 0, 1, -2}, {12000, 0, 0, 1}, {1000, 0.1, 0.08, 0.05} };

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			//cin >> kernel[i][j];
			kernel[i][j] = cube[i][j];
			cout << cube[i][j] << " ";
		}
		cout << endl;
	}
	print();
	DCXA();
}

bool NetFlowSapTank::bfs(int s, int t)
{
	memset(pre, -1, sizeof(pre));
	memset(vis, false, sizeof(vis));
	queue<int>q;
	vis[s] = true;
	q.push(s);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)																//寻找可曾广路
		{
			if (!vis[i] && g[now][i] > 0)														//未被访问，且有边相连
			{
				vis[i] = true;
				pre[i] = now;
				if (i == t) return true;
				q.push(i);
			}
		}
	}
	return false;																						//找不到可增广路
}

int NetFlowSapTank::EK(int s, int t)
{
	int v, w, d, maxflow;
	maxflow = 0;
	while (bfs(s, t))																					//可增广
	{
		v = t;
		d = INF;
		while (v != s)																					//找可增量d
		{
			w = pre[v];																				//w记录v的前驱
			if (d > g[w][v])
				d = g[w][v];
			v = w;
		}
		maxflow += d;
		v = t;
		while (v != s)																					//沿着可增广路增流
		{
			w = pre[v];
			g[w][v] -= d;																				//残余网络中正向边减流
			g[v][w] += d;																			//反向边增流

			if (f[v][w] > 0)																			//实流网络如果是反向边则减流，正向边则增流
				f[v][w] -= d;
			else
				f[w][v] += d;
			v = w;
		}
	}
	return maxflow;
}

void NetFlowSapTank::print()
{
	cout << endl;
	cout << "-----------实流网络如下------------" << endl;
	cout << "  ";
	for (int i = 1; i <= n; i++)
		cout << setw(7) << "v" << i;
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "v" << i;
		for (int j = 1; j <= n; j++)
			cout << setw(7) << f[i][j];
		cout << endl;
	}
}

void NetFlowSapTank::NFSTTest()
{
	int u, v, w;
	const static int maxn = 9 + 1;
	//用于调试的预存储数据
	int uArr[maxn] = { 0,1,1,2,3,3,4,4,5,5 };
	int vArr[maxn] = { 0,2,3,4,2,5,3,6,4,6 };
	int wArr[maxn] = { 0,12,10,8,2,13,5,18,6,4 };
	
	memset(g, 0, sizeof(g));
	memset(f, 0, sizeof(f));
	cout << "请输入节点个数n和边数m：" << endl;
	//cin >> n >> m;
	n = 6;
	m = 9;
	cout << n << " " << m << endl;
	cout << "请输入两个节点u，v以及边（u--v）的容量w：" << endl;
	for (int i = 1; i <= m; i++)
	{
		//cin >> u >> v >> w;
		u = uArr[i];
		v = vArr[i];
		w = wArr[i];
		cout << u << " " << v << " " << w << endl;
		g[u][v] += w;
	}
	cout << "最大网络流量：" << EK(1, n);
	print();
}










