#include "stdafx.h"
#include "Chapter5.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

double ZOPackBacktrackTank::Bound(int i)									//计算上界
{
	//剩余物品为第i~n中物品
	int rp = 0;
	while (i <= n)
	{
		rp += v[i];
		i++;
	}
	return cp + rp;
}

double ZOPackBacktrackTank::BoundPro(int i)
{
	//剩余物品为第i~n种物品
	double cleft = W - cw;													//剩余容量
	double brp = 0.0;
	while (i <= n && w[i] < cleft)
	{
		cleft -= w[i];
		brp += v[i];
		i++;
	}
	if (i <= n)																		//采用切割的方式装满背包，设定上界（求解时不允许切割）
	{
		brp += v[i] / w[i] * cleft;
	}
	return cp + brp;
}

void ZOPackBacktrackTank::Backtrack(int t)
{
	if (t > n)
	{
		for (int j = 1; j <= n; j++)
		{
			bestx[j] = x[j];
		}
		bestp = cp;
		return;
	}
	if (cw + w[t] < W)																			//满足限制条件，则搜索左子树
	{
		x[t] = 1;
		cw += w[t];
		cp += v[t];
		Backtrack(t + 1);
		cw -= w[t];
		cp -= v[t];
	}
	if (Bound(t + 1) > bestp)																//满足限界条件，搜索右子树
	{
		x[t] = 0;
		Backtrack(t + 1);
	}
}

void ZOPackBacktrackTank::Knapsack(double W, int n)
{
	//初始化
	cw = 0;																							//当前重量
	cp = 0;																							//当前价值
	bestp = 0;																						//当前最优价值
	double sumw = 0.0;																		//用来统计物品的总重量
	double sumv = 0.0;																		//用来统计物品的总价值
	for (int i = 1; i <= n; i++)
	{
		sumv += v[i];
		sumw += w[i];
	}
	if (sumw <= W)
	{
		bestp = sumv;
		cout << "放入购物车的最大价值为：" << bestp << endl;
		cout << "所有物品都可以放入购物车" << endl;
		return;
	}
	Backtrack(1);																					//从第一层开始向深度方向搜索
	cout << "放入购物车的最大价值为：" << bestp << endl;
	cout << "放入购物车的物品的序号为：" << endl;
	for (int i = 1; i <= n; i++)
	{
		if (bestx[i] == 1)
			cout << i << " ";
	}
	cout << endl;
}

void ZOPackBacktrackTank::KnapsackPro(double W, int n)
{
	cw = 0;																							//购物车当前重量
	cp = 0;																							//购物车当前价值
	bestp = 0;																						//当前最优值
	double sumw = 0;																		//输入物品总重量
	double sumv = 0;																			//输入物品总价值

	ObjectNode *Q = new ObjectNode[n];										//物品结构体，包含物品的序号和单位质量价值
	double *a = new double[n + 1];													//辅助数组用于把排序后的重量和价值传递给原数组  a[]表示临时重量数组
	double *b = new double[n + 1];													//b[]表示临时价值数组
																										//动态分配了内从之后记得要清理
	for (int i = 1; i <= n; i++)
	{
		Q[i - 1].id = i;
		Q[i - 1].d = 1.0 * v[i] / w[i];
		sumv += v[i];
		sumw += w[i];
	}
	if (sumw <= W)
	{
		bestp = sumv;
		cout << "放入购物车的最大价值为：" << bestp << endl;
		cout << "所有物品都可以放入购物车" << endl;
		return;
	}
	sort(Q, Q + n, cmp);																		//按照(价值/重量)的顺序从大到小排序
	for (int i = 1; i <= n; i++)
	{
		a[i] = w[Q[i - 1].id];																	//把排序后的数据传递给辅助数组
		b[i] = v[Q[i - 1].id];
	}
	for (int i = 1; i <= n; i++)
	{
		w[i] = a[i];
		v[i] = b[i];
	}
	Backtrack(1);																					//从第一层开始深度优先搜索
	cout << "放入购物车的物品的最大价值为：" << bestp << endl;
	cout << "放入购物车的物品序号为：" << endl;
	for (int i = 1; i <= n; i++)
	{
		if (bestx[i] == 1)
			cout << i << " ";
	}
	cout << endl;

	//释放内存
	delete []Q;
	delete []a;
	delete []b;
}

void ZOPackBacktrackTank::ZOPBTest()
{
	cout << "请输入物品的总个数：" << endl;
	cin >> n;
	cout << "请输入购物车承重极限：" << endl;
	cin >> W;
	cout << "请分别输入各个物品的重量w和价值v，用空格分开：" << endl;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
	Knapsack(W, n);
}

void ZOPackBacktrackTank::ZOPBTestPro()
{
	cout << "请输入物品的总个数：" << endl;
	cin >> n;
	cout << "请输入购物车承重极限：" << endl;
	cin >> W;
	cout << "请分别输入各个物品的重量w和价值v，用空格分开：" << endl;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
	KnapsackPro(W, n);
}

bool cmp(ObjectNode a1, ObjectNode a2)
{
	return a1.d > a2.d;
}