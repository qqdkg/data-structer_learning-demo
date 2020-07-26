#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <stack>
#include <queue>
#include "AlgoGate.h"

using namespace std;



//2.4高级钟点秘书问题

MeetType meet[1000];

void setMeet::init()
{
	int begArr[10] = {3,1,5,2,5,3,8,6,8,12};
	int endArr[10] = {6,4,7,5,9,8,11,10,12,14};
	cout << "会议总次数n为：" << n << endl;
	cout << "会议的开始和结束时间为：" << endl;
	cout << "会议编号" << "  会议开始时间" << "  会议结束时间" << endl;
	for (int i = 0; i < n; i++)
	{
		meet[i].beg = begArr[i];
		meet[i].end = endArr[i];
		meet[i].num = i + 1;
		cout << "  " << meet[i].num << "\t\t" << meet[i].beg << "\t\t" << meet[i].end << endl;
	}
}

//用于sort的比较函数
bool cmp(MeetType x, MeetType y)
{
	if (x.end == y.end)
		return x.beg > y.beg;
	return x.end < y.end;
}


void setMeet::solve()
{
	sort(meet, meet + n, cmp);
	int i;
	cout << endl;
	cout << "排序之后的会议时间如下:" << endl;
	cout << "会议编号" << "  会议开始时间" << "  会议结束时间" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "  " << meet[i].num << "\t\t" << meet[i].beg << "\t\t" << meet[i].end << endl;
	}
	cout << "--------------------------------------------------------------" << endl;
	cout << "选择的会议的过程：" << endl;
	cout << "  选择第" << meet[0].num << "个会议" << endl;			//选中第一个会议
	ans = 1;
	int last = meet[0].end;																	//记录这一个会议的结束时间
	for (i = 1; i < n; i++)
	{
		if (meet[i].beg >= last)
		{
			//如果会议i的开始时间大于等于选中的最后一个会议的结束时间
			ans++;
			last = meet[i].end;
			cout << "  选择第" << meet[i].num << "个会议" << endl;
		}
	}
	cout << "最多可以安排" << ans << "个会议" << endl;

}


//2.5最短路径

const int N = 100;							//城市个数，可修改
const int INF = 1e7;
int map[N][N];
int dist[N];
int p[N];
int n, m;											//n为城市个数，m为城市之间的路线条数
int flag[N];										//flag[i]==ture,则节点i加入了s集合，否者节点i在V-S集合

struct Node {
	int u, step;
	Node() {};
	Node(int a, int sp)
	{
		u = a;
		step = sp;
	} 
	bool operator < (const Node &a) const {
		return step > a.step;
	}
};

void Dijkstra(int st)
{
	priority_queue <Node> Q;			//优先队列化
	Q.push(Node(st, 0));
	memset(flag, 0, sizeof(flag));			//初始化flag数组为0
	for (int i = 1; i <= n; ++i)
		dist[i] = INF;								//初始化所有距离为无穷大
	dist[st] = 0;
	while (!Q.empty())
	{
		Node it = Q.top();						//优先队列队头元素为最小值
		Q.pop();
		int t = it.u;
		if (flag[t])									//说明已经找到了最短距离，该节点是队列里面重复的元素
			continue;
		flag[t] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (!flag[i] && map[t][i] < INF)
				if (dist[i] > dist[t] + map[t][i])
				{										//求距离当前点的每个点的最短距离，进行松弛操作
					dist[i] = dist[t] + map[t][i];
					Q.push(Node(i, dist[i]));			//把更新过的最短距离压入优先队列
				}
		}
	}
}//void 

void TestDijkstra()
{
	int st;
	system("color 0d");
	cout << "请输入城市个数" << endl;
	n = 5;
	cout << "请输入城市间的路线个数" << endl;
	m =7;
	cout << "请输入城市间的路线以及距离" << endl;
	for(int i=1;i<=n;i++)								//初始化图的邻接矩阵
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = INF;
		}

	int uArr[] = {0,1,1,2,2,3,3,4};
	int vArr[] = {0,2,3,3,4,4,5,5};
	int wArr[] = {0,2,3,5,6,7,1,4};

	int i=1;
	while (m--)
	{
		map[uArr[i]][vArr[i]] = wArr[i];
		i++;
	}
	cout << "请输入小明目前所在的位置" << endl;
	cin >> st;
	Dijkstra(st);
	//findPath(st);
	for (int i = 1; i <= n; i++)
	{
		cout << "小明：" << st << "--->" << "要去的位置：" << i;
		if (dist[i] == INF)
			cout << "sorry,无路可达" << endl;
		else
			cout << "最短距离为：" << dist[i] << endl;
	}
}

void findPath(int u)
{
	int x;
	stack<int> s;
	cout << "源点为：" << u << endl;
	for (int i = 1; i <= n; i++)
	{
		x = p[i];
		while (x != -1)
		{
			s.push(x);									//将前驱节点压入栈中
			x = p[x];
		}
		cout << "源点到其他个点的最短路径为：";
		while (!s.empty())
		{
			cout << s.top() << "--";					//依次弹出后续节点
			s.pop();
		}
		cout << "最短距离为：" << dist[i] << endl;
	}
}




//2.6 哈夫曼编码
HNodeType HuffNode[MAXNODE];						//定义一个节点结构体数组
HCodeType HuffCode[MAXLEAF];						//定义一个编码结构体数组
void dkg_HuffmanTree(HNodeType HuffNode[MAXNODE], int n)
{
	/*i、j：循环变量,m1、m2：构造哈夫曼数不同过程中两个最小权值节点的权值
	 *x1，x2：构造哈夫曼树不同过程中两个最小权值节点在数组中的序号。
	*/
	int i, j, x1, x2;
	double m1, m2;
	//初始化存放在哈夫曼树组HuffNode[]中的节点
	for (i = 0; i < 2 * n - 1; i++)										//二叉树总结点数=叶子数*2-1
	{
		HuffNode[i].weight = 0;		//权值
		HuffNode[i].parent = -1;
		HuffNode[i].lchild = -1;
		HuffNode[i].rchild = -1;
	}
	/*输入n个叶子结点权值*/
	double weightArr[6] = {0.05 , 0.32 , 0.18 , 0.07 , 0.25 , 0.13};
	char valueArr[6] = {'a' , 'b' , 'c' , 'd' , 'e' , 'f'};
	for (i = 0; i < n; i++)
	{
		cout << "Please input value and weight of leaf node" << i + 1 << endl;
		//cin >> HuffNode[i].value >> HuffNode[i].weight;
		HuffNode[i].value = valueArr[i];
		HuffNode[i].weight = weightArr[i];
	}

	/*构造哈夫曼树*/
	for (i = 0; i < n - 1; i++)
	{//执行n-1次合并
		m1 = m2 = MAXVALUE;
		/*m1 m2 用量存放两个无父节点且全职最小的两个节点的权值*/
		x1 = x2 = -1;
		/*找出所有节点中权值最小、无父节点的两个节点，并合并为一颗二叉树*/
		for (j = 0; j < n + i; j++)
		{
			if (HuffNode[j].weight < m1 && HuffNode[j].parent == -1)
			{
				m2 = m1;
				x2 = x1;
				m1 = HuffNode[j].weight;
				x1 = j;
			}
			else if (HuffNode[j].weight < m2 && HuffNode[j].parent == -1)
			{
				////私加 之后有问题的话删除
				//m1 = m2;
				//x1 = x1;

				m2 = HuffNode[j].weight;
				x2 = j;
			}
		}
		/*设置两个子节点x1 x2 的父节点信息*/
		HuffNode[x1].parent = n + i;
		HuffNode[x2].parent = n + i;
		HuffNode[n + i].weight = m1 + m2;
		HuffNode[n + i].lchild = x1;
		HuffNode[n + i].rchild = x2;
		/*用于测试*/
		cout << "X1.weight and x2.weight in round " << i + 1 << "\t" << HuffNode[x1].weight << "\t" << HuffNode[x2].weight << endl;
	}
}

void dkg_HuffmanCode(HCodeType HuffCode[MAXLEAF], int n)
{
	HCodeType cd;
	int i, j, c, p;
	for (i = 0; i < n; i++)
	{
		cd.start = n - 1;
		c = i;
		p = HuffNode[c].parent;
		while (p != -1)
		{
			if (HuffNode[p].lchild == c)
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1;
			cd.start--;						/*求编码低一位*/
			c = p;
			p = HuffNode[c].parent;			/*设置下一循环条件*/
		}
		/*把叶子结点的编码信息从临时编码cd中复制出来，放入编码节后体数组*/
		for (j = cd.start + 1; j < n; j++)
		{
			HuffCode[i].bit[j] = cd.bit[j];
		}
		HuffCode[i].start = cd.start;
	}
}

void HuffmanTest() 
{
	int i, j, n;
	cout << "Please input n：" << endl;
	//cin >> n;
	n = 6;
	dkg_HuffmanTree(HuffNode, n);
	dkg_HuffmanCode(HuffCode, n);

	for (i = 0; i < n; i++)
	{
		cout << HuffNode[i].value << "：Huffman code is：";
		for (j = HuffCode[i].start + 1; j < n; j++)
			cout << HuffCode[i].bit[j];
		cout << endl;
	}
}

