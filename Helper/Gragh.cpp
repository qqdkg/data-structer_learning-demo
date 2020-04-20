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

void prim(int u0, AMGragh G)
{
	//�������n����ʼ����u0����Ȩ�����ڽӾ���G
	//���s[i]=true,˵��i�Ѿ�������С������
	//�Ķ��㼯��U�����򶥵�i���ڼ���V-U
	//��������ص���СȨֵ���ݵ�����lowcost
	CreateAMNet_prim(G);
	bool *s = new bool[G.vexnum];
	int *lowcost = new int[G.vexnum];
	int *closest = new int[G.vexnum];

	s[u0] = true;//��ʼ��ʱU��ֻ��u0һ��Ԫ��
	int i, j;
	for (int i = 0; i < G.vexnum; i++)//��ʼ��
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
		for (j = 0; j < G.vexnum; j++)//�ڼ���U-V��Ѱ�Ҿ��뼯��U����Ķ���t
		{
			if (s[j] != true && lowcost[j] < temp)
			{
				t = j;
				temp = lowcost[j];
			}
		}
		if (t == u0)
			break;				//�Ҳ���t����ѭ��
		s[t] = true;			//����ҵ���t���t���뼯��U
		for (j = 0; j < G.vexnum; j++)								//����lowcost��colsest
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

	for (i = 0; i < G.vexnum; i++)//���붨����Ϣ�����붨����Ϣ����
		G.Vex[i] = vex[i];

	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.Edge[i][j] = edge[i][j];
}

bool TopologicalSort(ALGragh &G,int topo[])
{
	//����ͼG�����ڽ�����Ĵ洢�ṹ
	//��G�޻�·���γ�һ��G����������topo[]������true����G�л�·���෵��false
	ALGragh G_rev;
	CreateALGragh_Topo(G,G_rev);														//��������ͼ
	int *inDegree = new int[G.vexnum];													//�������
	int i, m;
	stack<int> S;
	int temp=0;																					//���
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
	m = 0;																					//������������0
	while (!S.empty())
	{
		i = S.top();
		S.pop();
		topo[m] = i;
		m++;
		AdjNode *p = G.Vex[i].first;												//pָ��i�ĵ�һ���ڽӵ�
		while (p)																			//i�������ڽӵ���ȼ�һ
		{
			int k = p->v;																	//kΪi���ڽӵ�
			--inDegree[k];																//Ϊi��ÿһ���ڽӵ���ȼ�һ
			if (inDegree[k] == 0)
				S.push(k);													//������Ϊ0������ջ
			p = p->next;
		}
	}

	for (int i = 0; i < G.vexnum; i++)
		cout << topo[i] << " ";
	cout << endl;
	if (m < G.vexnum)
		return false;																		//�������ͼ�л��η���true
	else
		return true;
}

//���������ڽӱ�()
void CreateALGragh_Topo(ALGragh & G, ALGragh & G_rev)
{
	int i, j;
	VexType u, v;
	char vexch[] = { 'V0','V1','V2','V3','V4','V5' };
	char edgech[] = { 'V0','V1','V0','V2','V1','V3','V1','V4','V2','V1','V2','V4','V3','V5','V4','V5' };
	int weight[] = {2,15,10,19,4,11,6,5};

	cout << "�����붥�����ͱ���" << endl;
	G_rev.vexnum=G.vexnum = 6;
	G_rev.edgenum=G.edgenum = 8;

	cout << "�����붥����Ϣ" << endl;
	for (i = 0; i < G.vexnum; i++)					//���붥����Ϣ���洢��������Ϣ����
	{
		G.Vex[i].data = vexch[i];
		G_rev.Vex[i].data = vexch[i];
	}
	for (i = 0; i < G.vexnum; i++)
	{
		G.Vex[i].first = NULL;
		G_rev.Vex[i].first = NULL;
	}
	cout << "��������ÿ���ߵ���������u,v" << endl;
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
			insertedge(G, i, j,weight[weight_count]);								//����ߣ���Ϊ����ͼ������Ҫ����һ����insertedge(G, j, i);
			weight_count++;
			insertedge(G_rev, j,i);						//����ͼ
		}
	}
}

void CriticalPath(ALGragh &G)
{
	int n, i, k, j, e, l;
	int topo[6];
	TopologicalSort(G, topo);
	int *ve = new int[G.vexnum];					//ÿ���¼������緢��ʱ��
	int *vl = new int[G.vexnum];						//ÿ���¼�����ٷ���ʱ��
	n = G.vexnum;
	for (i = 0; i < n; i++)
		ve[i] = 0;
	//��������˳����ÿ���¼������緢��ʱ��
	for (i = 0; i < n; i++)
	{
		k = topo[i];											//��ȡ���������еĶ������k
		AdjNode *p = G.Vex[k].first;					//pָ��k�ĵ�һ���ڽӽڵ�
		while (p != NULL)									//���θ���k�������ڽӽڵ㷢������Сʱ��
		{
			j = p->v;											//jΪ�ڽӽڵ�����
			if (ve[j] < ve[k] + p->weight)					//����j�����緢��ʱ��ve[j]
				ve[j] = ve[k] + p->weight;
			p = p->next;									//pָ��k����һ���ڵ�
		}
	}
	for (i = 0; i < n; i++)									//��ÿ���¼�����ٷ���ʱ�����ó�ֵve[n-1]
	{
		vl[i] = ve[n - 1];
	}
	//��������������ÿ���¼�����ٷ���ʱ��
	for (i = n - 1; i >= 0; i--)
	{
		k = topo[i];											//��ȡ�������˵Ķ������k
		AdjNode *p = G.Vex[k].first;					//pָ��k�ĵ�һ���ڽӵ�
		while (p != NULL)
		{
			j = p->v;
			if (vl[k] > vl[j] - p->weight)				//���¶���k����ٷ���ʱ��vl[k]
			{
				vl[k] = vl[j] - p->weight;
			}
			p=p->next;
		}
	}
	//�ж�ÿһ���Ƿ�Ϊ�ؼ��
	cout << "�ؼ�·��Ϊ:";
	int next_num = 0;													//˳���������
	for (int i = 0; i < n; i++)
	{
		AdjNode *p = G.Vex[next_num].first;				//pָ��i�ĵ�һ���ڽӵ�
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
