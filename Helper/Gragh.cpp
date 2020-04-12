#include "stdafx.h"
#include "Gragh.h"
#include<iostream>
#include<queue>
#include<limits>
#include<stack>
using namespace std;

void CreateAMGragh(AMGragh & G)//��������ͼ���ڽӾ���
{
	int i, j;
	VexType u, v;

	VexType vex[] = {'a','b','c','d'};
	VexType edge[] = {'a','b','a','d','b','c','b','d','c','d'};

	cout << "�����붨����" << endl;
	//cin >> G.vexnum;

	G.vexnum = 4;
	cout << G.vexnum << endl;

	cout << "���������" << endl;
	//cin >> G.edgenum;

	G.edgenum = 5;
	cout << G.edgenum << endl;

	cout << "�����붨����Ϣ:" << endl;
	for (i = 0; i < G.vexnum; i++)//���붨����Ϣ�����붨����Ϣ����
	{
		//cin >> G.Vex[i];
		G.Vex[i] = vex[i];
	}
	for (i = 0; i < G.vexnum; i++)//��ʼ���ڽӾ�������ֵΪ0����������Ļ����ʼ��Ϊ�����
		for (j = 0; j < G.vexnum; j++)
			G.Edge[i][j] = 0;
	cout << "������ÿ������������������:" << endl;
	
	int elem = 0;//������
	int edgenum = G.edgenum;
	while (edgenum--)
	{
		//cin >> u >> v;

		u = edge[elem];
		elem++;
		v = edge[elem];
		elem++;

		i = locatevex(G, u);//����u���±�
		j = locatevex(G, v);//����v���±�
		if (i != -1 && j != -1)
			G.Edge[i][j] = G.Edge[j][i] = 1;//�ڽӾ�����Ӧλ�ô洢1�����ΪΪ����ͼ����ΪG.Edge[i][j] = 1
	}
}


//Description������Ϣ������Ѱ��u���ڵ�λ��
//			input����ʼ������AMGragh�������ݺ�VexType���͵Ĵ���ѯԪ��u
//		  output���ɹ��򷵻�����Ԫ���±�,ʧ���򷵻�-1
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
	cout << "Ԫ��Ϊ:" << endl;
	for (int i = 0; i < G.vexnum; i++)
		cout << G.Vex[i] << " ";
	cout << endl;

	cout << "���ڽӾ���Ϊ:" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
			cout << G.Edge[i][j] << " ";
		cout << endl;
	}
}

//�����ڽӾ���Ĺ�����ȱ���
void BFS_AM(AMGragh G, int v)
{
	int u, w;
	queue<int> Q;																	//����һ����ͨ����(�Ƚ��ȳ�����������int����

	bool *visited = new bool[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = false;

	cout << G.Vex[v] << "\t";
	visited[v] = true;
	Q.push(v);			//Դ�����
	while (!Q.empty())
	{
		u = Q.front();			//ȡ��ͷԪ�أ���ֵ��u
		Q.pop();					//ͷԪ�س���
		for (w = 0; w < G.vexnum; w++)//һ�μ��w�������ڽӵ�
		{
			if (G.Edge[u][w] && !visited[w])//u��w�ڽӶ���wδ������
			{
				cout << G.Vex[w] << "\t";
				visited[w] = true;
				Q.push(w);
			}
		}
	}
}

//���������ڽӱ�
void CreateALGragh(ALGragh & G)
{
	int i, j;
	VexType u, v;
	char vexch[] = {'a','b','c','d','e'};
	char edgech[] = {'a','b','a','c','a','e','b','c','c','d','c','e','d','e'};

	cout << "�����붥�����ͱ���" << endl;
	//cin >> G.vexnum >> G.edgenum;
	G.vexnum = 5;
	G.edgenum = 7;

	cout << "�����붥����Ϣ" << endl;
	for (i = 0; i < G.vexnum; i++)					//���붥����Ϣ���洢��������Ϣ����
	{
		//cin >> G.Vex[i].data;
		G.Vex[i].data = vexch[i];
	}
	for (i = 0; i < G.vexnum; i++)
	{
		G.Vex[i].first = NULL;
	}
	cout << "��������ÿ���ߵ���������u,v" << endl;
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
			insertedge(G, i, j);								//����ߣ���Ϊ����ͼ������Ҫ����һ����insertedge(G, j, i);
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
		cout << "����" << i << " :" << G.Vex[i].data;
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
	queue<int> Q;								//����һ����ͨ���У��Ƚ��ȳ���,���int��������

	bool *visited = new bool[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = false;

	cout << G.Vex[v].data << "\t";
	visited[v] = true;
	Q.push(v);
	while(!Q.empty())//������в���
	{
		u = Q.front();						//ȡ��ͷԪ�ظ�ֵ��u
		Q.pop();
		p = G.Vex[u].first;
		while (p)
		{
			w = p->v;
			if (!visited[w])					//���wδ������
			{
				cout << G.Vex[w].data << "\t";
				visited[w] = true;
				Q.push(w);
			}
			p = p->next;
		}
	}
}

void DFS_AM(AMGragh G,int v)//�����ڽӾ���Ĺ����������
{
	int w;
	cout << G.Vex[v] << "\t";

	bool *visited = new bool[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = false;

	visited[v] = true;

	for (w = 0; w < G.vexnum; w++)							//���μ��v�������ڽӵ�
		if (G.Edge[v][w] && !visited[w])							//v,w�ڽ���wδ������
			DFS_AM(G, w);												//��w���㿪ʼ�ݹ���ȱ���
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
		w = p->v;								//wΪv���ڽӽڵ㣻
		if (!visited[w])//w�±�Ľڵ�δ������
			DFS_AL(G, w);					//��w�ڵ��������������ȱ���
		p = p->next;
	}

}

//����ͨͼ�������ڽ��б��������ȱ���
void DFS_AL(ALGragh G)
{
	bool *visited = new bool[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = false;

	for (int i = 0; i < G.vexnum; i++)			//����ͨͼ��Ҫ��©�㣬���δ�����ʵĶ���
		if (!visited[i])										//���i�ڵ�δ������
			DFS_AL(G);
}

#define INF INT_MAX
void Dijkastra(AMGragh G, int u)
{
	//��ʼ���ڽӾ���
	CreateAMNet(G);

	//��̬��������
	EdgeType *dist = new EdgeType[G.vexnum];
	bool *flag = new bool[G.vexnum];
	int *p = new int[G.vexnum];

	//1.��ʼ����������dist[]��ǰ������p[]
	for (int i = 0; i < G.vexnum; i++)
	{
		dist[i] = G.Edge[u][i];								//��ʼ��u���������������С����
		flag[i] = false;
		if (dist[i] == INF)
			p[i] = -1;												//u���ö���ľ��������˵������i��Դ��u������
		else
			p[i] = u;												//���ڣ�������uΪi��ǰ���ڵ�
	}

	dist[u] = 0;
	flag[u] = true;												//��ʼʱ������S��ֻ��u����S{u}

	//2.Ѱ��Դ�㵽ÿһ����������·��
	for (int i = 0; i < G.vexnum; i++)
	{
		int temp = INF, t = u;
		for (int j = 0; j < G.vexnum; j++)						//3.�ڼ���V-SѰ�Ҿ���Դ��u����Ķ���t
		{
			if (!flag[j] && dist[j] < temp)
			{
				t = j;
				temp = dist[j];
			}
		}
		if (t == u)													//�Ҳ���t������ѭ��
		{
			for (int i = 0; i < G.vexnum; i++)
				if (flag[i] != true)
					return;
		}
		flag[t] = true;											//�����t���뵽����S
		for(int j=0;j<G.vexnum;j++)						//4. ������t���ڵĽڵ㵽Դ��u�ľ���
			if(!flag[j] && G.Edge[t][j]<INF)				//j�ڼ���V-S��,t��j֮���б�
				if (dist[j] > (dist[t] + G.Edge[t][j]))
				{
					dist[j] = dist[t] + G.Edge[t][j];
					p[j] = t;
				}
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		if (p[i] != -1)
			cout<< p[i] + 1<<" ";									//���ϵ������1��ʼ��Ϊ�˶�Ӧ��ȥ��
		else
			cout << p[i] << " ";
	}
	cout << endl;

	//5.��ʾ���·����������Щ�ڵ�
	int x;
	stack<int> S;
	for (int i = 0; i < G.vexnum; i++)
	{
		x = p[i];
		if (x == -1 && u != G.Vex[i])
		{
			cout << "ԭ�㵽��������������·��Ϊ" << u << "--" << G.Vex[i] << "sorry,��·�ɴ�";
			cout << endl;
			continue;
		}
		while (x != -1)
		{
			S.push(x);
			x = p[x];
		}
		cout << "Դ�㵽������������·��Ϊ:";
		while (!S.empty())
		{
			cout << G.Vex[S.top()] << "--";
			S.pop();
		}
		cout << G.Vex[i] << "\t��̾���Ϊ" << dist[i] << endl;
	}

}

//���ڴ��������ڽӾ���(��ʱ)
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

	for (i = 0; i < G.vexnum; i++)//���붨����Ϣ�����붨����Ϣ����
		G.Vex[i] = vex[i];

	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.Edge[i][j] = edge[i][j];
}

//ʹ��������G�и�������֮������·��
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
				p[i][j] = i;										//���i��j֮���л�����j��ǰ����Ϊi
			else
				p[i][j] = -1;									//���i��j֮���޻�����j��ǰ����Ϊ-1
		}
	for(k=0;k<G.vexnum;k++)
		for(i=0;i<G.vexnum;i++)
			for(j=0;j<G.vexnum;j++)
				if (dist[i][k] !=INF && dist[k][j]!=INF && dist[i][k] + dist[k][j] < dist[i][j])//��i����k��j��·�����
				{
					dist[i][j] = dist[i][k] + dist[k][j];				//����dist[i][j]
					p[i][j] = p[k][j];										//����j��ǰ��Ϊk;
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

//���ڴ��������ڽӾ���(��ʱ)
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

	for (i = 0; i < G.vexnum; i++)//���붨����Ϣ�����붨����Ϣ����
		G.Vex[i] = vex[i];

	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.Edge[i][j] = edge[i][j];
}
