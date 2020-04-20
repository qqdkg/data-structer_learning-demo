#include "stdafx.h"
#include "Gragh.h"
#include<iostream>
#include<queue>
#include<limits>
#include<stack>
using namespace std;

void CreateAMGragh(AMGragh & G)//创建无向图的邻接矩阵
{
	int i, j;
	VexType u, v;

	VexType vex[] = {'a','b','c','d'};
	VexType edge[] = {'a','b','a','d','b','c','b','d','c','d'};

	cout << "请输入定点数" << endl;
	//cin >> G.vexnum;

	G.vexnum = 4;
	cout << G.vexnum << endl;

	cout << "请输入边数" << endl;
	//cin >> G.edgenum;

	G.edgenum = 5;
	cout << G.edgenum << endl;

	cout << "请输入定点信息:" << endl;
	for (i = 0; i < G.vexnum; i++)//输入定点信息，存入定点信息数组
	{
		//cin >> G.Vex[i];
		G.Vex[i] = vex[i];
	}
	for (i = 0; i < G.vexnum; i++)//初始化邻接矩阵所有值为0，如果是网的话则初始化为无穷大
		for (j = 0; j < G.vexnum; j++)
			G.Edge[i][j] = 0;
	cout << "请输入每条边依附的两个顶点:" << endl;
	
	int elem = 0;//测试用
	int edgenum = G.edgenum;
	while (edgenum--)
	{
		//cin >> u >> v;

		u = edge[elem];
		elem++;
		v = edge[elem];
		elem++;

		i = locatevex(G, u);//查找u的下标
		j = locatevex(G, v);//查找v的下标
		if (i != -1 && j != -1)
			G.Edge[i][j] = G.Edge[j][i] = 1;//邻接矩阵相应位置存储1，如果为为有向图，则为G.Edge[i][j] = 1
	}
}


//Description：在信息矩阵中寻找u所在的位置
//			input：初始化过的AMGragh类型数据和VexType类型的待查询元素u
//		  output：成功则返回所查元素下标,失败则返回-1
int locatevex(AMGragh & G, VexType u)
{
	for (int i = 0; i < G.vexnum; i++) {
		if (G.Vex[i] == u)
			return i;
	}
	return -1;
}

void AMGraghTest()
{
	AMGragh G;
	CreateAMGragh(G);
	cout << "元素为:" << endl;
	for (int i = 0; i < G.vexnum; i++)
		cout << G.Vex[i] << " ";
	cout << endl;

	cout << "其邻接矩阵为:" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
			cout << G.Edge[i][j] << " ";
		cout << endl;
	}
}

//基于邻接矩阵的广度优先遍历
void BFS_AM(AMGragh G, int v)
{
	int u, w;
	queue<int> Q;																	//创建一个普通队列(先进先出），里面存放int类型

	bool *visited = new bool[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = false;

	cout << G.Vex[v] << "\t";
	visited[v] = true;
	Q.push(v);			//源点入队
	while (!Q.empty())
	{
		u = Q.front();			//取出头元素，赋值给u
		Q.pop();					//头元素出队
		for (w = 0; w < G.vexnum; w++)//一次检查w的所有邻接点
		{
			if (G.Edge[u][w] && !visited[w])//u、w邻接而且w未被访问
			{
				cout << G.Vex[w] << "\t";
				visited[w] = true;
				Q.push(w);
			}
		}
	}
}

//创建有向邻接表
void CreateALGragh(ALGragh & G)
{
	int i, j;
	VexType u, v;
	char vexch[] = {'a','b','c','d','e'};
	char edgech[] = {'a','b','a','c','a','e','b','c','c','d','c','e','d','e'};

	cout << "请输入顶点数和边数" << endl;
	//cin >> G.vexnum >> G.edgenum;
	G.vexnum = 5;
	G.edgenum = 7;

	cout << "请输入顶点信息" << endl;
	for (i = 0; i < G.vexnum; i++)					//输入顶点信息，存储到顶点信息数组
	{
		//cin >> G.Vex[i].data;
		G.Vex[i].data = vexch[i];
	}
	for (i = 0; i < G.vexnum; i++)
	{
		G.Vex[i].first = NULL;
	}
	cout << "依次输入每条边的两个顶点u,v" << endl;
	int edgnum = G.edgenum;

	int count = 0;
	while (edgnum--) {
		//cin >> u >> v;
		
		u = edgech[count];
		count++;
		v = edgech[count];
		count++;
		
		i = locatevex(G, u);
		j = locatevex(G, v);
		if (i != -1 && j != -1)
			insertedge(G, i, j);								//插入边，若为无向图，还需要插入一条边insertedge(G, j, i);
	}
}

int locatevex(ALGragh & G, VexType u)
{
	for (int i = 0; i < G.vexnum; i++) {
		if (G.Vex[i].data == u)
			return i;
	}
	return -1;
}

void insertedge(ALGragh & G, int i, int j,int weight)
{
	AdjNode *s;
	s = new AdjNode;
	s->v = j;
	s->next = G.Vex[i].first;
	if (weight != -1)
		s->weight = weight;
	G.Vex[i].first = s;
}

void ALGraghTest()
{
	ALGragh G;
	CreateALGragh(G);
	for (int i = 0; i < G.vexnum; i++)
	{
		cout << "顶点" << i << " :" << G.Vex[i].data;
		AdjNode *ad;
		ad = G.Vex[i].first;
		if (ad)
		{
			cout << " " << ad->v << " ";
			while (ad->next)
			{
				ad = ad->next;
				cout << " " << ad->v << " ";
			}
		}
		cout << endl;
	}
}

void BFS_AL(ALGragh G, int v)
{
	int u, w;
	AdjNode *p;
	queue<int> Q;								//创建一个普通队列（先进先出）,存放int类型数据

	bool *visited = new bool[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = false;

	cout << G.Vex[v].data << "\t";
	visited[v] = true;
	Q.push(v);
	while(!Q.empty())//如果队列不空
	{
		u = Q.front();						//取出头元素赋值给u
		Q.pop();
		p = G.Vex[u].first;
		while (p)
		{
			w = p->v;
			if (!visited[w])					//如果w未被访问
			{
				cout << G.Vex[w].data << "\t";
				visited[w] = true;
				Q.push(w);
			}
			p = p->next;
		}
	}
}

void DFS_AM(AMGragh G,int v)//基于邻接矩阵的广度优先搜索
{
	int w;
	cout << G.Vex[v] << "\t";

	bool *visited = new bool[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = false;

	visited[v] = true;

	for (w = 0; w < G.vexnum; w++)							//依次检查v的所有邻接点
		if (G.Edge[v][w] && !visited[w])							//v,w邻接且w未被访问
			DFS_AM(G, w);												//从w顶点开始递归深度遍历
}

void DFS_AL(ALGragh G, int v)
{
	int w;
	AdjNode *p;
	cout << G.Vex[v].data << "\t";

	bool *visited = new bool[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = false;

	visited[v] = true;
	p = G.Vex[v].first;
	while (p)
	{
		w = p->v;								//w为v的邻接节点；
		if (!visited[w])//w下标的节点未被访问
			DFS_AL(G, w);					//从w节点出发进行深度优先遍历
		p = p->next;
	}

}

//非连通图，基于邻接列表的深度优先遍历
void DFS_AL(ALGragh G)
{
	bool *visited = new bool[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = false;

	for (int i = 0; i < G.vexnum; i++)			//非连通图需要查漏点，检查未被访问的顶点
		if (!visited[i])										//如果i节点未被访问
			DFS_AL(G);
}

#define INF INT_MAX
void Dijkastra(AMGragh G, int u)
{
	//初始化邻接矩阵
	CreateAMNet(G);

	//动态分配数组
	EdgeType *dist = new EdgeType[G.vexnum];
	bool *flag = new bool[G.vexnum];
	int *p = new int[G.vexnum];

	//1.初始化距离数组dist[]和前驱数组p[]
	for (int i = 0; i < G.vexnum; i++)
	{
		dist[i] = G.Edge[u][i];								//初始化u到其他各顶点的最小长度
		flag[i] = false;
		if (dist[i] == INF)
			p[i] = -1;												//u到该顶点的距离无穷大，说明顶点i与源点u不相邻
		else
			p[i] = u;												//相邻，则设置u为i的前驱节点
	}

	dist[u] = 0;
	flag[u] = true;												//初始时，集合S中只有u，既S{u}

	//2.寻找源点到每一个定点的最短路径
	for (int i = 0; i < G.vexnum; i++)
	{
		int temp = INF, t = u;
		for (int j = 0; j < G.vexnum; j++)						//3.在集合V-S寻找距离源点u最近的顶点t
		{
			if (!flag[j] && dist[j] < temp)
			{
				t = j;
				temp = dist[j];
			}
		}
		if (t == u)													//找不到t，跳出循环
		{
			for (int i = 0; i < G.vexnum; i++)
				if (flag[i] != true)
					return;
		}
		flag[t] = true;											//否则把t加入到集合S
		for(int j=0;j<G.vexnum;j++)						//4. 更新与t相邻的节点到源点u的距离
			if(!flag[j] && G.Edge[t][j]<INF)				//j在集合V-S中,t与j之间有边
				if (dist[j] > (dist[t] + G.Edge[t][j]))
				{
					dist[j] = dist[t] + G.Edge[t][j];
					p[j] = t;
				}
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		if (p[i] != -1)
			cout<< p[i] + 1<<" ";									//书上的坐标从1开始，为了对应上去。
		else
			cout << p[i] << " ";
	}
	cout << endl;

	//5.显示最短路径经过了哪些节点
	int x;
	stack<int> S;
	for (int i = 0; i < G.vexnum; i++)
	{
		x = p[i];
		if (x == -1 && u != G.Vex[i])
		{
			cout << "原点到其他各顶点的最短路径为" << u << "--" << G.Vex[i] << "sorry,无路可达";
			cout << endl;
			continue;
		}
		while (x != -1)
		{
			S.push(x);
			x = p[x];
		}
		cout << "源点到其他各顶点最路径为:";
		while (!S.empty())
		{
			cout << G.Vex[S.top()] << "--";
			S.pop();
		}
		cout << G.Vex[i] << "\t最短距离为" << dist[i] << endl;
	}

}

//用于创建网的邻接矩阵(临时)
void CreateAMNet(AMGragh & G)
{
	int i, j;
	VexType u, v;

	G.vexnum = 5;
	G.edgenum = 8;
	VexType vex[] = { '1','2','3','4','5' };
	int edge[5][5] = {{INF,2,5,INF ,INF},
							{ INF ,INF ,2,6,INF },
							{ INF ,INF ,INF ,7,1},
							{ INF ,INF ,2,INF ,4},
							{ INF ,INF ,INF ,INF ,INF }};

	for (i = 0; i < G.vexnum; i++)//输入定点信息，存入定点信息数组
		G.Vex[i] = vex[i];

	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.Edge[i][j] = edge[i][j];
}

//使用有向网G中各个顶点之间的最短路径
void Floyd(AMGragh G)
{
	CreateAMNet_Floyd(G);
	EdgeType dist[4][4];
	int p[4][4];
	int i, j, k;
	for(i=0;i<G.vexnum;i++)
		for (j = 0; j < G.vexnum; j++)
		{
			dist[i][j] = G.Edge[i][j];
			if (dist[i][j] < INF && i != j)
				p[i][j] = i;										//如果i，j之间有弧，则将j的前驱置为i
			else
				p[i][j] = -1;									//如果i，j之间无弧，则将j的前驱置为-1
		}
	for(k=0;k<G.vexnum;k++)
		for(i=0;i<G.vexnum;i++)
			for(j=0;j<G.vexnum;j++)
				if (dist[i][k] !=INF && dist[k][j]!=INF && dist[i][k] + dist[k][j] < dist[i][j])//从i讲过k到j的路径最短
				{
					dist[i][j] = dist[i][k] + dist[k][j];				//更新dist[i][j]
					p[i][j] = p[k][j];										//更改j的前驱为k;
				}
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
			cout << dist[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
			cout << p[i][j] << " ";
		cout << endl;
	}
}

//用于创建网的邻接矩阵(临时)
void CreateAMNet_Floyd(AMGragh & G)
{
	int i, j;
	VexType u, v;

	G.vexnum = 4;
	G.edgenum = 8;
	VexType vex[4] = { '0','1','2','3' };
	int edge[4][4] = { { 0,1,INF ,4 },
								{ INF,0,9,2 },
								{ 3,5,0,8},
								{ INF ,INF ,6,0}, };

	for (i = 0; i < G.vexnum; i++)//输入定点信息，存入定点信息数组
		G.Vex[i] = vex[i];

	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.Edge[i][j] = edge[i][j];
}

void prim(int u0, AMGragh G)
{
	//顶点个数n、开始顶点u0，带权无向邻接矩阵G
	//如果s[i]=true,说明i已经加入最小生成树
	//的顶点集合U，否则顶点i属于集合V-U
	//将最后的相关的最小权值传递到数组lowcost
	CreateAMNet_prim(G);
	bool *s = new bool[G.vexnum];
	int *lowcost = new int[G.vexnum];
	int *closest = new int[G.vexnum];

	s[u0] = true;//初始化时U中只有u0一个元素
	int i, j;
	for (int i = 0; i < G.vexnum; i++)//初始化
	{
		if (i != u0)
		{
			lowcost[i] = G.Edge[u0][i];
			closest[i] = u0;
			s[i] = false;
		}
		else
		{
			lowcost[i] = 0;
			closest[i] = -1;
		}
	}
	for (i = 0; i < G.vexnum; i++)
	{
		int temp = INF;
		int t = u0;
		for (j = 0; j < G.vexnum; j++)//在集合U-V中寻找距离集合U最近的顶点t
		{
			if (s[j] != true && lowcost[j] < temp)
			{
				t = j;
				temp = lowcost[j];
			}
		}
		if (t == u0)
			break;				//找不到t跳出循环
		s[t] = true;			//如果找到了t则把t加入集合U
		for (j = 0; j < G.vexnum; j++)								//更新lowcost和colsest
		{
			if (s[j] != true && G.Edge[t][j] < lowcost[j])
			{
				lowcost[j] = G.Edge[t][j];
				closest[j] = t;
			}
		}
	}
	for (i = 0; i < G.vexnum; i++)
		cout << closest[i]+1 << " ";
	cout << endl;
	for (i = 0; i < G.vexnum; i++)
		cout << lowcost[i] << " ";
	cout << endl;

}

void CreateAMNet_prim(AMGragh & G)
{
	int i, j;
	VexType u, v;

	G.vexnum = 7;
	G.edgenum = 12;
	VexType vex[7] = { '1','2','3','4','5','6','7' };
	int edge[7][7] = { { INF,23,INF,INF,INF,28,36 },
								{ 23,INF,20,INF,INF,INF,1 },
								{ INF,20,INF,15,INF,INF,4 },
								{ INF,INF,15,INF,3,INF,9 },
								{ INF ,INF ,INF ,3,INF ,17,16},
								{ 28,INF,INF,INF,17,INF,25 },
								{ 36,1,4,9,16,25,INF } };

	for (i = 0; i < G.vexnum; i++)//输入定点信息，存入定点信息数组
		G.Vex[i] = vex[i];

	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.Edge[i][j] = edge[i][j];
}

bool TopologicalSort(ALGragh &G,int topo[])
{
	//有向图G采用邻接链表的存储结构
	//若G无回路则形成一个G的拓扑序列topo[]并返回true，若G有回路，侧返回false
	ALGragh G_rev;
	CreateALGragh_Topo(G,G_rev);														//创建有向图
	int *inDegree = new int[G.vexnum];													//入度数组
	int i, m;
	stack<int> S;
	int temp=0;																					//入度
	for (int i = 0; i < G_rev.vexnum; i++)
	{
		AdjNode *p = G_rev.Vex[i].first;
		while (p != NULL)
		{
			temp++;
			p = p->next;
		}
		inDegree[i] = temp;
		temp = 0;
	}
	for (i = 0; i < G.vexnum; i++)
	{
		if (inDegree[i] == 0)
			S.push(i);
	}
	m = 0;																					//输出项计数等于0
	while (!S.empty())
	{
		i = S.top();
		S.pop();
		topo[m] = i;
		m++;
		AdjNode *p = G.Vex[i].first;												//p指向i的第一个邻接点
		while (p)																			//i的所有邻接点入度减一
		{
			int k = p->v;																	//k为i的邻接点
			--inDegree[k];																//为i的每一个邻接点入度减一
			if (inDegree[k] == 0)
				S.push(k);													//如果入度为0，则入栈
			p = p->next;
		}
	}

	for (int i = 0; i < G.vexnum; i++)
		cout << topo[i] << " ";
	cout << endl;
	if (m < G.vexnum)
		return false;																		//如果有向图有环形返回true
	else
		return true;
}

//创建有向邻接表()
void CreateALGragh_Topo(ALGragh & G, ALGragh & G_rev)
{
	int i, j;
	VexType u, v;
	char vexch[] = { 'V0','V1','V2','V3','V4','V5' };
	char edgech[] = { 'V0','V1','V0','V2','V1','V3','V1','V4','V2','V1','V2','V4','V3','V5','V4','V5' };
	int weight[] = {2,15,10,19,4,11,6,5};

	cout << "请输入顶点数和边数" << endl;
	G_rev.vexnum=G.vexnum = 6;
	G_rev.edgenum=G.edgenum = 8;

	cout << "请输入顶点信息" << endl;
	for (i = 0; i < G.vexnum; i++)					//输入顶点信息，存储到顶点信息数组
	{
		G.Vex[i].data = vexch[i];
		G_rev.Vex[i].data = vexch[i];
	}
	for (i = 0; i < G.vexnum; i++)
	{
		G.Vex[i].first = NULL;
		G_rev.Vex[i].first = NULL;
	}
	cout << "依次输入每条边的两个顶点u,v" << endl;
	int edgnum = G.edgenum;

	int count = 0;
	int weight_count = 0;
	while (edgnum--) {
		//cin >> u >> v;

		u = edgech[count];
		count++;
		v = edgech[count];
		count++;

		i = locatevex(G, u);
		j = locatevex(G, v);
		if (i != -1 && j != -1)
		{
			insertedge(G, i, j,weight[weight_count]);								//插入边，若为无向图，还需要插入一条边insertedge(G, j, i);
			weight_count++;
			insertedge(G_rev, j,i);						//逆序图
		}
	}
}

void CriticalPath(ALGragh &G)
{
	int n, i, k, j, e, l;
	int topo[6];
	TopologicalSort(G, topo);
	int *ve = new int[G.vexnum];					//每个事件的最早发生时间
	int *vl = new int[G.vexnum];						//每个事件的最迟发生时间
	n = G.vexnum;
	for (i = 0; i < n; i++)
		ve[i] = 0;
	//按照拓扑顺序求每个事件的最早发生时间
	for (i = 0; i < n; i++)
	{
		k = topo[i];											//获取拓扑序列中的定点序号k
		AdjNode *p = G.Vex[k].first;					//p指向k的第一个邻接节点
		while (p != NULL)									//依次更新k的所有邻接节点发生的最小时间
		{
			j = p->v;											//j为邻接节点的序号
			if (ve[j] < ve[k] + p->weight)					//更新j的最早发生时间ve[j]
				ve[j] = ve[k] + p->weight;
			p = p->next;									//p指向k的下一个节点
		}
	}
	for (i = 0; i < n; i++)									//给每个事件的最迟发生时间设置初值ve[n-1]
	{
		vl[i] = ve[n - 1];
	}
	//按照拓扑逆序求每个事件的最迟发生时间
	for (i = n - 1; i >= 0; i--)
	{
		k = topo[i];											//获取逆序拓扑的定点序号k
		AdjNode *p = G.Vex[k].first;					//p指向k的第一个邻接点
		while (p != NULL)
		{
			j = p->v;
			if (vl[k] > vl[j] - p->weight)				//更新顶点k的最迟发生时间vl[k]
			{
				vl[k] = vl[j] - p->weight;
			}
			p=p->next;
		}
	}
	//判断每一项活动是否为关键活动
	cout << "关键路径为:";
	int next_num = 0;													//顺序遍历变量
	for (int i = 0; i < n; i++)
	{
		AdjNode *p = G.Vex[next_num].first;				//p指向i的第一个邻接点
		while (p != NULL)
		{
			j = p->v;
			e = ve[next_num];
			l = vl[j] - p->weight;
			if (e == l)
			{
				cout << "<" << G.Vex[next_num].data << "," << G.Vex[j].data << "> ";
				next_num = j;
			}
			p = p->next;
		}
	}
	cout << endl;
}
