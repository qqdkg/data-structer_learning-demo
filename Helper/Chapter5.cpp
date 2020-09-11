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


