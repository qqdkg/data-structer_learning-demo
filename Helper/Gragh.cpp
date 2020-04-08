#include "stdafx.h"
#include "Gragh.h"
#include<iostream>
#include<queue>
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

//创建又向邻接表
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

void insertedge(ALGragh & G, int i, int j)
{
	AdjNode *s;
	s = new AdjNode;
	s->v = j;
	s->next = G.Vex[i].first;
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

	for (int i = 0; i < G.vexnum; i++)//非连通图需要查漏点，检查未被访问的顶点
		for (!visited[i])//如果i节点未被访问
			DFS_AL(G);
}
