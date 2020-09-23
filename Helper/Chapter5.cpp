#include "stdafx.h"
#include "Chapter5.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
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

//判断是否可以把结点t加入团中
bool BigestRollTank::Place(int t)
{
	bool result = true;
	for (int j = 1; j < t; j++)													//判断结点t与前t - 1个结点是否相连
	{
		if (x[j] && a[t][j] == 0)														//相当于x[j] == true,表示j是被选中结点,a[t][j] == 0表示t和j没有边相连
		{
			result = false;
			break;
		}
	}
	return result;
}

void BigestRollTank::Backtrack(int t)
{
	if (t > n)
	{
		for (int i = 1; i <= n; i++)
		{
			bestx[i] = x[i];
		}
		bestn = cn;
		return;
	}
	if (Place(t))																		//满足约束条件，进入左子树，即把结点t加入团中
	{
		x[t] = 1;
		cn++;
		Backtrack(t + 1);
		cn--;
	}
	if (cn + (n - t) > bestn)														//满足限界条件，进入右子树
	{
		x[t] = 0;
		Backtrack(t + 1);
	}
}

void BigestRollTank::BigestRollTest()
{
	int u, v;
	//int uArr[] = { 0, 1, 1, 1, 1, 2, 3, 3, 4 };
	//int vArr[] = { 0, 2, 3, 4, 5, 3, 4, 5, 5 };
	cout << "请输入部落人数n（节点数）" << endl;
	cin >> n;
	cout << "请输入人与人的友好关系数（边数）" << endl;
	cin >> m;
	memset(a, 0, sizeof(a));														//把邻接矩阵中的数据初始化为0，<string.h>
	cout << "请依次输入有友好关系的两个人（有边相连的两个节点u和v）用空格分开" << endl;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		a[u][v] = a[v][u] = 1;
		//cout << uArr[i] << " " << vArr[i] << endl;
		//a[uArr[i]][vArr[i]] = a[vArr[i]][uArr[i]] = 1;
	}
	bestn = 0;
	cn = 0;
	Backtrack(1);																		//从第一层开始搜索
	cout << "国王护卫队的最大人数为：" << bestn << endl;
	cout << "国王护卫队的成员为：";
	for (int i = 1; i <= n; i++)
	{
		if (bestx[i])
			cout << i << " ";
	}
	cout << endl;
}

//创建邻接矩阵
void ColorMapQuesTank::CreatMap()
{
	int u, v;
	cout << "请输入边数：" << endl;
	cin >> edge;
	memset(map, 0, sizeof(map));											//将邻接矩阵里的数值初始化为0
	cout << "依次输入有边相连接的两个节点u和v，用空格分开：" << endl;
	for (int i = 1; i <= edge; i++)
	{
		cin >> u >> v;
		map[u][v] = map[v][u] = 1;
	}
}

//约束条件
bool ColorMapQuesTank::OK(int t)
{
	for (int j = 1; j < t; j++)														//对1~ t - 1遍历
	{
		if (map[t][j])
		{
			if (x[t] == x[j])
				return false;
		}
	}// for j
	return true;
}

void ColorMapQuesTank::Backtrack(int t)
{
	if (t > n)																			//到达叶子结点
	{
		sum++;																		//可行解计数变量
		cout << "第" << sum << "种可行解：";
		for (int i = 1; i <= n; i++)
			cout << x[i] << " ";
		cout << endl;
	}
	else
	{
		for (int j = 1; j <= m; j++)
		{
			x[t] = j;																		//第t层节点的颜色遍历颜色池
			if (OK(t))																	//如果发现邻接的节点颜色不同，则继续向下搜索
				Backtrack(t + 1);													//本次只寻找可行解，不寻找最优解，没有设置限界函数
		}
	}
}

void ColorMapQuesTank::CMQTest()
{
	cout << "请输入节点数n：" << endl;
	cin >> n;
	cout << "请输入颜色数m：" << endl;
	cin >> m;
	CreatMap();																		//生成由地图转化而来的无向连通图的邻接矩阵
	Backtrack(1);																		//从m叉树结构的解的组织形式的第一层开始搜索（该过程并不需要真的生成一棵m叉树）
}

bool NQueenTank::Place(int t)
{
	bool ok = true;
	for (int i = 1; i < t; i++)														//判断第t个皇后是否与前t - 1个皇后冲突（此时前t个皇后的位置已经被确定）
	{
		if (x[t] == x[i] || t - i == abs(x[t] - x[i]))
		{
			ok = false;
			break;
		}
	}
	return ok;
}

void NQueenTank::Backtrack(int t)
{
	if (t > n)
	{
		count++;
		for (int i = 1; i <= n; i++)
			cout << x[i] << " ";
		cout << endl;
		cout << "---------------" << endl;
	}
	else
		for (int i = 1; i <= n; i++)
		{																					//判断m个分支（m = n）的结果
			x[t] = i;
			if (Place(t))																//如果第t层的皇后放置在放置在第i列不冲突，则向着深度方向搜索
				Backtrack(t + 1);
		}
}

void NQueenTank::NQueenTest()
{
	cout << "请输入皇后的个数n：" << endl;
	cin >> n;
	Backtrack(1);																		//从第一层开始搜索
	cout << "答案的个数是" << count << "个" << endl;
}


//5.6 最优加工顺序
void BestProcessOrderTank::Backtrack(int t)
{
	if (t > n)
	{
		for (int i = 1; i <= n; i++)
			bestx[i] = x[i];
		bestf = f2;																		//最快数值
		return;
	}

	for (int i = t; i <= n; i++)
	{
		f1 += T[x[i]].x;
		int temp = f2;
		f2 = max(f1, temp) + T[x[i]].y;
		if (f2 < bestf)
		{
			//这里这部分逻辑是关于排列树的生成的，之后需要单独看下。
			swap(x[t], x[i]);
			Backtrack(t + 1);
			swap(x[t], x[i]);
		}
		f1 -= T[x[i]].x;
		f2 = temp;
	}
}

void BestProcessOrderTank::BPOTest()
{
	cout << "请输入机器零件个数n：" << endl;
	cin >> n;
	cout << "请输入每个零件在第一台机器和第二台机器的加工时间，并用空隔开" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> T[i].x >> T[i].y;
		x[i] = i;
	}
	//初始化
	bestf = INF;
	f1 = f2 = 0;
	memset(bestx, 0, sizeof(bestx));
	Backtrack(1);														//从第一层开始遍历		深度搜索排列树
	cout << "最优零件加工顺序为" << endl;
	for (int i = 1; i <= n; i++)
		cout << bestx[i] << " ";
	cout << endl;
	cout << "最优的机器零件加工时间为：" << endl;
	cout << bestf << endl;
}

void ArrayTree::myarray(int t)
{
	if (t > n)
	{
		for (int i = 1; i <= n; i++)					//输出排列
			cout << x[i] << " ";
		cout << endl;
		return;
	}
																//可以实现排列树的递归输出，是对所谓的{1、2、...、n}的1和每一个数交换换后去头递推的实现
	for (int i = t; i <= n; i++)						//枚举
	{
		swap(x[t], x[i]);									//交换
		myarray(t + 1);									//继续深度搜索
		swap(x[t], x[i]);									//回溯时的反操作
	}
}

void ArrayTree::ArrayTreeTest()
{
	cout << "输出排列的元素个数n（求1..n的排列）：" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
		x[i] = i;
	myarray(1);
}
