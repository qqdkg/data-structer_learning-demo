#include "stdafx.h"
#include "Gragh.h"
#include<iostream>
#include<queue>
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

	for (int i = 0; i < G.vexnum; i++)//����ͨͼ��Ҫ��©�㣬���δ�����ʵĶ���
		for (!visited[i])//���i�ڵ�δ������
			DFS_AL(G);
}
