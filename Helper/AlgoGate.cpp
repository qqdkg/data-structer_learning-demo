#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
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
	int u, v, w, st;
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
typedef struct {
	double weight;					//权值
	int parent;							//双亲节点
	int lchild;							//左孩子
	int rchild;							//右孩子
	char value;						//该节点表示的字符
} HNodeType;

typedef struct {


} HCodeType;


