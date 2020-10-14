#include "stdafx.h"
#include "Chapter6.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

//描述背包转态的节点的结构体的构造函数实现
ShopBagNode::ShopBagNode()
{
	memset(x, 0, sizeof(x));
}

ShopBagNode::ShopBagNode(int _cp, int _rp, int _rw, int _id)
{
	cp = _cp;
	rp = _rp;
	rw = _rw;
	id = _id;
}

int ZeroOneBagSpan::bfs()
{
	int t;																				//t:当前处理物品序号
	int tcp;																			//tcp:当前装入购物车物品的价值
	int trp;																			//trp:当前剩余物品价值
	int trw;																			//trw:当前剩余容量
	queue<SBNode> q;														//创建一个普通队列（先进先出）
	q.push(SBNode(0, sumv, W, 1));									//压入一个初始节点

	while (!q.empty())															//使用将节点放入队列的方法实现广度优先搜索，而不是递归形式的深度优先搜索
	{
		SBNode livenode, lchild, rchild;								//三个临时变量
		livenode = q.front();													//取出队头元素作为当前扩展节点livenode
		q.pop();																	//抛壳
		t = livenode.id;															//获取当前处理的物品编号
		//搜索到最后一个物品的时候不需要向下继续搜索
		//如果购物车已经装满，也不需要继续扩展（因为0-1背包问题物品不可分割）
		if (t > n || livenode.rw == 0)
		{
			if (livenode.cp >= bestp)										//更新最优解和最优值
			{
				for (int i = 1; i <= n; i++)
				{
					bestx[i] = livenode.x[i];
				}
				bestp = livenode.cp;
			}
			continue;																//处理队列中的下一个节点
		}
		//判断当前节点是否满足限界条件，如果不满足则不继续扩展
		if (livenode.cp + livenode.rp < bestp)
			continue;																//继续往下扩展也不会得到最优解
		//扩展左孩子
		tcp = livenode.cp;														//当前购物车中的价值
		trp = livenode.rp - goods[t].value;							//不论物品是否装入，剩余价值都会减少
		trw = livenode.rw;													//当前购物车剩余容量
		if (trw >= goods[t].weight)										//满足约束条件，可以放入购物车
		{
			lchild.rw = trw - goods[t].weight;
			lchild.cp = tcp + goods[t].value;
			lchild = SBNode(lchild.cp, trp, lchild.rw, t + 1);
			for (int i = 1; i < t; i++)
				lchild.x[i] = livenode.x[i];									//复制前t - 1个物品的状态
			lchild.x[t] = true;
			if (lchild.cp > bestp)												//广度优先中的最优值更新
				bestp = lchild.cp;
			q.push(lchild);														//推入队列
		}

		//扩展右孩子
		if (tcp + trp >= bestp)												//满足限界条件不放入购物车，分支依然是活分支，但如果不满足衔接条件，右孩子直接不放入队列，之后就不会被搜索，相当于被剪枝
		{
			rchild = SBNode(tcp, trp, trw, t + 1);
			for (int i = 1; i < t; i++)
				rchild.x[i] = livenode.x[i];
			rchild.x[t] = false;
			q.push(rchild);
		}
	}// while(!q.empty());

	return bestp;
}

void ZeroOneBagSpan::ZOBSTest()
{
	//输入物品的个数和背包的数量
	cout << "请输入物品的个数n：";
	cin >> n;
	cout << "请输入购物车的容量W：";
	cin >> W;
	cout << "请依次输入每个物品的重量w和价值v，使用空格隔开" << endl;
	bestp = 0;																							//初始化最优解为0
	sumv = 0;
	sumw = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> goods[i].weight >> goods[i].value;
		sumw += goods[i].weight;
		sumv += goods[i].value;
	}
	if (sumw <= W)
	{
		bestp = sumv;
		cout << "放入购物车的最大价值为：" << bestp << endl;
		cout << "所有物品均可放入购物车。" << endl;
		return;
	}
	bfs();																									//使用广度所搜方法搜索最优解
	cout << "放入购物车的物品的最大价值为：" << bestp << endl;
	cout << "放入购物车的物品顺序为：" << endl;
	//输出最优解
	for (int i = 1; i <= n; i++)
	{
		if (bestx[i])
			cout << i << " ";
	}
	cout << endl;

}

ShopBagNodePro::ShopBagNodePro()
{
	memset(x, false, sizeof(x));
}

ShopBagNodePro::ShopBagNodePro(int _cp, double _up, int _rw, int _id)
{
	cp = _cp;
	up = _up;
	rw = _rw;
	id = _id;
}

bool operator <(const ShopBagNodePro & a, const ShopBagNodePro & b)
{
	return a.up < b.up;
}

bool cmp(TSObject a1, TSObject a2)
{
	return a1.d > a2.d;
}

//用于定义优先队列的优先级，cl越小优先级越高
bool operator<(const TSNode & a, const TSNode & b)
{
	return a.cl > b.cl;
}

//定义队列的优先级。以zl为优先级额，zl越小，越优先
bool operator<(const TspNode & a, const TspNode & b)
{
	return a.zl > b.zl;
}

double ZeroOneBagSpanPro::Bound(SBNodePro tnode)
{
	double maxvalue = tnode.cp;											//已装入购物车的物品价值
	int t = tnode.id;																//排序后的编号
	double left = tnode.rw;														//剩余容量
	while (t <= n && w[t] <= left)											//未到达叶子结点，且当前物品还能够装入购物车
	{
		maxvalue += v[t];
		left -= w[t];
	}
	if (t <= n)
	{
		maxvalue += 1.0 * v[t] / w[t] * left;								//如果某一块放不进去了，那就放这一块的一部分进去，用来估算这个上界
	}
	return maxvalue;
}

int ZeroOneBagSpanPro::priorbfs()
{
	int t;																					//当期处理物品编号t
	int tcp;																				//当前状物的物品价值tcp
	int tup;																				//当前装入物品的价值上界(当前路线的可能的最大价值)
	int trw;																				//当前购物车剩余容量 trw;
	priority_queue<SBNodePro> q;										//创建一个优先队列，优先级为装入其中的物品的价值上界
	q.push(SBNodePro(0, sumv, W, 1));									//初始化，将根节点压入
	//使用有线队列，对于子集树进行广度搜索
	while (!q.empty())
	{
		SBNodePro livenode, lchild, rchild;								//定义三个变量
		livenode = q.top();														//取队头元素作为活节点  这个函数，记得带括号
		q.pop();																		//抛壳
		t = livenode.id;																//当前处理的物品序号
		//搜索到最后一个物品的时候不需要往下搜索
		//---------------------//如果当前购物车没有剩余容量(已经装满)则不再扩展
		if (t > n || livenode.rw == 0)
		{
			if (livenode.cp >= bestp)											//更新最优解和最优值		//官渡优先的时候这里一定要 ">="否则，无法到达叶子节点
			{
				for (int i = 1; i <= n; i++)
					bestx[i] = livenode.x[i];
				bestp = livenode.cp;
			}// livenode.cp > bestp
			continue;
		}// t >n || rw == 0
		//判断当前节点是否满足限界条件，如果不满足则不再扩展
		if (livenode.up < bestp)
			continue;

		//!!---------------------//扩展左孩子
		tcp = livenode.cp;															//当前购物车中的价值
		trw = livenode.rw;														//当前购物车中的剩余容量

		if (trw >= w[t])																//如果满足约束条件，可以放入购物车
		{
			lchild.cp = tcp + v[t];
			lchild.rw = trw - w[t];
			lchild.id = t + 1;
			tup = Bound(lchild);													//计算左孩子的可装上界,调用Bound（）函数的时候lchild其实只构造了一部分
			lchild = SBNodePro(lchild.cp, tup, lchild.rw, t + 1);
			for (int i = 1; i < t; i++)
				lchild.x[i] = livenode.x[i];										//获得上一个状态的解向量
			lchild.x[t] = true;
			if (lchild.cp > bestp)													//比最优值大才更新，因为是横向的广度搜索，有必要在这里判断是否更新最优值
				bestp = lchild.cp;
			q.push(lchild);
		}

		//--------------------------// 扩展右孩子
		rchild.cp = tcp;
		rchild.rw = trw;
		rchild.id = t + 1;
		tup = Bound(rchild);														//计算右孩子的上界											//之前做了运算符重载，优先队列似乎会自动比较这个数值然后排序
		if (tup >= bestp);															//满足限界条件，并且不奖当前物品放入购物车的情况
		{
			rchild = SBNodePro(tcp, tup, trw, t + 1);
			for (int i = 1; i <t ; i++)
				rchild.x[i] = livenode.x[i];										//获取上一个状态的解向量
			rchild.x[t] = false;
			q.push(rchild);															//右孩子入队
		}// tup > bestp
	}
	return bestp;
}

void ZeroOneBagSpanPro::ZOBSPTest()
{
	bestp = 0;																			//最优值初始化
	sumw = 0;
	sumv = 0;
	memset(bestx, false, sizeof(bestx));
	cout << "请输入物品个数n：" << endl;
	cin >> n;
	cout << "请输入购物车容量W：" << endl;
	cin >> W;
	cout << "请输入每个物品的重量w和价值v，使用空格分开：" << endl;
	int wArr[] = {2, 5, 4, 2};
	int vArr[] = {6, 3, 5, 4};
	for (int i = 1; i <= n; i++)
	{
		cin >> goods[i].weight >> goods[i].value;					//输入第i个物品的重量和价值
		/*goods[i].weight = wArr[i - 1];
		goods[i].value = vArr[i - 1];
		cout << goods[i].weight << " " << goods[i].value << endl;*/
		sumw += goods[i].weight;
		sumv += goods[i].value;
		S[i - 1].id = i;
		S[i - 1].d = 1.0 * goods[i].value / goods[i].weight;
	}
	if (sumw <= W)
	{
		bestp = sumv;
		cout << "放入购物车的最大价值为：" << bestp << endl;
		cout << "所有物品均可以放入购物车。" << endl;
		return;
	}
	sort(S, S + n, cmp);															//对辅助结构体数组进行排序, a1.d > a2.d; 由大到小
	cout << "排序后的物品重量和价值：" << endl;
	for (int i = 1; i <= n; i++)
	{
		w[i] = goods[S[i - 1].id].weight;									//排序辅助数组可以这样使用啊，辅助数组存储了实际数组的编号，将辅助数组排序之后配个节点位置变化，通过id找到原始数组的对应元素，同时还不用改变原始数组
		v[i] = goods[S[i - 1].id].value;
		cout << w[i] << " " << v[i] << endl;
	}
	priorbfs();																			//使用有线队列实现的0-1背包广度优先搜索（分支限界法）
	//输出最优解
	cout << "放入购物车的最大价值为：" << bestp << endl;
	cout << "放入购物车的物品序号为：";
	//输出最优解
	for (int i = 1; i <= n; i++)
	{
		if (bestx[i])
			cout << S[i - 1].id << " ";											//输入原始物品编号（排序前的编号可以这样直接输出）
	}
	cout << endl;
}

TravelingSalesmanNode::TravelingSalesmanNode()
{
}

TravelingSalesmanNode::TravelingSalesmanNode(double _cl, int _id)
{
	cl = _cl;
	id = _id;
}

double TravelingSalesmanSpan::Travelingbfs()
{
	int t;																		//当前处理的景点序号t
	TSNode livenode, newnode;									//定义当前扩展结点livenode，生成新结点newnode
	priority_queue<TSNode> q;									//创建一个优先队列，优先级为已走过路程cl，cl越小优先级越高
	newnode = TSNode(0, 2);									//创建根结点（为什么根结点在第二层？）
	for (int i = 1; i <= n; i++)
	{
		newnode.x[i] = i;												//初始化根结点解向量
	}
	q.push(newnode);													//根结点加入优先队列
	while (!q.empty())
	{
		livenode = q.top();												//取出队头结点作为活节点
		q.pop();															//抛壳
		t = livenode.id;													//当前处理的景点序号
		//搜索到倒数第二个结点的时候不需要再往下搜索
		if (t == n)
		{
			//例如找到一个路径（1 2 4 3），到达4号景点时，立刻判断g[4][3]和g[3][1]是否有边相连接
			//如果有边相连接则判断当前路径长度 cl + g[4][3] + g[3][1] < bestl,满足则更新最优值和最优解
			double path1 = g[livenode.x[n - 1]][livenode.x[n]];
			double path2 = g[livenode.x[n]][1];
			if (path1 != INF && path2 != INF && livenode.cl + path1 + path2 < bestl)
			{
				bestl = livenode.cl + path1 + path2;
				cout << endl;
				for (int i = 1; i <= n; i++)
				{
					bestx[i] = livenode.x[i];
				}
			}//==if (path1...
			continue;
		}//==if (t == n)
		
		 //判断当前节点是否满足限界条件，如果不满足则不再扩展
		if (livenode.cl >= bestl)
			continue;

		//扩展
		//没有达到叶子结点
		for (int j = t; j <= n; j++)												//搜索扩展结点的所有分支
		{
			if (g[livenode.x[t - 1]][livenode.x[j]] != INF)				//如果x[t - 1]与x[j]相连
			{
				double cl = livenode.cl + g[livenode.x[t - 1]][livenode.x[j]];
				if (cl < bestl)
				{
					newnode = TSNode(cl, t + 1);
					for (int i = 1; i <= n; i++)
					{
						newnode.x[i] = livenode.x[i];							//复制以前的解向量
					}
					swap(newnode.x[t], newnode.x[j]);					//交换newnode中x[t]和x[j]的值，这是实现解空间为排列树的操作
					q.push(newnode);												//新结点入队
				}
			}// == if (g...
		}// == for (int j = t

	}//== while (!q.empty())
	return bestl;
}

void TravelingSalesmanSpan::init()
{
	bestl = INF;
	for (int i = 0; i <= n; i++)
		bestx[i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			g[i][j] = g[j][i] = INF;
}

void TravelingSalesmanSpan::print()
{
	cout << endl;
	cout << "最短路径：";
	for (int i = 1; i <= n; i++)
		cout << bestx[i] << "--->";
	cout << "1" << endl;
	cout << "最短路径长度：" << bestl << endl;
}

void TravelingSalesmanSpan::TSSTest()
{
	int u, v, w;								//u,v代表城市，w代表城市u, v之间的距离
	cout << "请输入景点个数n（结点数）：" << endl;
	cin >> n;
	init();
	cout << "请输入景点间的连线数（边数）：" << endl;
	cin >> m;
	cout << "请依次输入两个景点u, v和两个景点间的距离w，格式：景点u 景点v 距离w：" << endl;
	int uArr[] = {1, 1, 1, 2, 2, 3};
	int vArr[] = { 2, 3, 4, 3, 4, 4 };
	int wArr[] = { 15, 30, 5, 6, 12, 3 };
	for (int i = 1; i <= m; i++)
	{
		/*cin >> u >> v >> w;
		g[u][v] = g[v][u] = w;*/
		cout << uArr[i - 1] << " " << vArr[i - 1] << " " << wArr[i - 1] << endl;
		g[uArr[i - 1]][vArr[i - 1]] = g[vArr[i - 1]][uArr[i - 1]] = wArr[i - 1];
	}
	Travelingbfs();
	print();
}

void TravelingSalesmanSpan::TSSTest2()
{
	int u, v, w;								//u,v代表城市，w代表城市u, v之间的距离
	cout << "请输入景点个数n（结点数）：" << endl;
	cin >> n;
	init();
	cout << "请输入景点间的连线数（边数）：" << endl;
	cin >> m;
	cout << "请依次输入两个景点u, v和两个景点间的距离w，格式：景点u 景点v 距离w：" << endl;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = w;
	}
	Travelingbfs();
	print();
}

TsProNode::TsProNode()
{
}

TsProNode::TsProNode(double _cl, double _rl, double _zl, int _id)
{
	cl = _cl;
	rl = _rl;
	zl = _zl;
	id = _id;
}

bool TravelingSalesmanSpanPro::Bound()													//计算下界（即每个景点最小出边之和）
{
	for (int i = 1; i <= n; i++)
	{
		double minl = INF;																				//初始化景点的出边最小值
		for (int j = 1; j <= n; j++)																		//找出每个景点的最小边
			if (g[i][j] != INF && g[i][j] < minl)
				minl = g[i][j];
		if (minl == INF)
			return false;																						//表示无回路
		minout[i] = minl;																					//记录每个顶点的最小出边
		minsum += minl;																					//记录所有顶点的最小出边之和
	}
	return true;
}

//TravelingSalesmanSpanPro为优化的分支限界法
double TravelingSalesmanSpanPro::Travelingbfsopt()
{
	if (!Bound())
		return -1;																								//表示无回路
	TspNode livenode, newnode;																	//定义当前扩展节点livenode和生成新节点newnode
	priority_queue<TspNode> q;																	//创建一个优先队列，优先级使用当前路径长度的下界
																													//zl = cl + rl;					zl越小越优先
	newnode = TsProNode(0, minsum, minsum, 2);										//创建根结点
	for (int i = 1; i <= n; i++)
	{
		newnode.x[i] = i;																					//初始化根结点解向量
	}
	q.push(newnode);																						//根节点加入优先队列
	while (!q.empty())
	{
		livenode = q.top();																				//取出队头结点作为当前扩展节点livenode
		q.pop();																								//抛壳
		int t = livenode.id;																				//记录当前处理的景点序号
		//搜索到倒数第二个结点时不需要再往下搜索了，因为最好都要回到约点，收到倒数第二个结点时未知已定
		if (t == n)																								//判断是否到达最优解
		{
			//例如当找到一个路径 （1 2 4 3），到达4号结点的时，立刻判断g[4][3]个g[3][1]是否有线连接
			//如果有边相连则判断当前路径是否为最优路径 cl + g[4][3] + g[3][1] < bestl，满足则跟新最优解
			double path1 = g[livenode.x[n - 1]][livenode.x[n]];
			double path2 = g[livenode.x[n]][1];
			if (path1 != INF && path2 != INF && livenode.cl + path1 + path2 < bestl)
			{
				bestl = livenode.cl + path1 + path2;

				//记录当前最优解向量
				for (int i = 1; i <= n; i++)
					bestx[i] = livenode.x[i];
			}// == if (path1 ...
			continue;
		}// == if (t == n)

		if (livenode.cl >= bestl)
			continue;

		//扩展
		//没有到达叶子结点
		for (int j = t; j <= n; j++)																				//所搜扩展节点的所有分支1 ... t - 1 在当前路径上已经被走过了，不用在遍历
		{
			if (g[livenode.x[t - 1]][livenode.x[j]] != INF)
			{																												//如果x[t - 1]与x[j]之间有边相连
				double cl = livenode.cl + g[livenode.x[t - 1]][livenode.x[j]];
				double rl = livenode.rl - minout[livenode.x[j]];
				double zl = cl + rl;
				if (zl < bestl)																							//如果可能获得更短路径
				{
					newnode = TsProNode(cl, rl, zl, t + 1);
					for (int i = 1; i <= n; i++)
						newnode.x[i] = livenode.x[i];															//复制以前的解向量
					swap(newnode.x[t], newnode.x[j]);													//交换两个元素的值（为了限定解空间为排列树）
					q.push(newnode);																				//新节点入队
				}// == if (zl < bestl)
			}// == if (g...
		}// == for (int j...)
	}// == while (!q.empty())

	return bestl;
}

void TravelingSalesmanSpanPro::Init()
{
	bestl = INF;
	minsum = 0;
	for (int i = 0; i <= n; i++)
		bestx[i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			g[i][j] = g[j][i] = INF;																						//初始化为全部不通
}

void TravelingSalesmanSpanPro::print()
{
	cout << endl;
	cout << "最短路径：" << endl;
	for (int i = 1; i <= n; i++)
		cout << bestx[i] << "--->";
	cout << "1" << endl;
	cout << "最短路径长度：" << bestl << endl;
}

void TravelingSalesmanSpanPro::TSSProTest()
{
	int u, v, w;																//描述城市u，城市v，u v之间的距离w
	cout << "请输入景点数n：" << endl;
	cin >> n;
	Init();
	cout << "请输入边数m：" << endl;
	cin >> m;
	cout << "依次输入景点u， 景点v， u v之间的距离w，格式：景点u， 景点v， 距离w" << endl;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = w;
	}
	Travelingbfsopt();
	print();
}

void TravelingSalesmanSpanPro::TSSProTest2()
{
	int u, v, w;																//描述城市u，城市v，u v之间的距离w
	cout << "请输入景点数n：" << endl;
	cin >> n;
	Init();
	cout << "请输入边数m：" << endl;
	cin >> m;
	cout << "依次输入景点u， 景点v， u v之间的距离w，格式：景点u， 景点v， 距离w" << endl;
	int uArr[] = { 1, 1, 1, 2, 2, 3 };
	int vArr[] = { 2, 3, 4, 3, 4, 4 };
	int wArr[] = { 15, 30, 5, 6, 12, 3 };
	for (int i = 1; i <= m; i++)
	{
		/*cin >> u >> v >> w;
		g[u][v] = g[v][u] = w;*/
		cout << uArr[i - 1] << " " << vArr[i - 1] << " " << wArr[i - 1] << endl;
		g[uArr[i - 1]][vArr[i - 1]] = g[vArr[i - 1]][uArr[i - 1]] = wArr[i - 1];
	}
	Travelingbfsopt();
	print();
}

bool FindPathSpan::findpath(Position s, Position e, Position *& path, int & Pathlen)
{
	if (s.x == e.x && s.y == e.y)																//判断起点和终点有没有重合
	{
		Pathlen = 0;
		return true;
	}
	Position DIR[4], here, next;
	DIR[0].x = 0;																						//向右
	DIR[0].y = 1;

	DIR[1].x = 1;																						//向上
	DIR[1].y = 0;

	DIR[2].x = 0;																						//向左
	DIR[2].y = -1;

	DIR[3].x = -1;																					//向下
	DIR[3].y = 0;
	return false;
}
