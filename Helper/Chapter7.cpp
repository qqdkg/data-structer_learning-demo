#include "stdafx.h"
#include "Chapter7.h"
#include <iostream>
#include <math.h>
#include <iomanip>
#include <queue>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;


void BestBenefitTank::print()
{
	cout << endl;
	cout << "---------------�����Ա����£�----------------" << endl;
	cout << "  ";
	cout << setw(7) << "b ";
	for (int i = 1; i <= m; i++)
		cout << setw(7) << "x" << FJL[i];
	cout << endl;
	cout << "c ";
	for (int i = 0; i <= n; i++)
	{
		if (i >= 1)
			cout << "x" << JL[i];
		for (int j = 0; j <= m; j++)
			cout << setw(7) << kernel[i][j] << " ";
		cout << endl;
	}
}

void BestBenefitTank::DCXA()
{
	float max1;													//max1���ڴ�����ļ�����
	float max2;													//max2���ڴ���������������Ӧ�Ļ������������ϵ��
	int e = -1;														//��¼�����
	int k = -1;														//��¼������
	float min;
	//ѭ��������ֱ���ҵ�����Ľ�����޽�Ϊֹ
	while (true)
	{
		max1 = 0;
		max2 = 0;
		min = 100000000;
		for (int j = 1; j <= m; j++)							//������У��������������Ӧ���У�
		{
			if (max1 < kernel[0][j])
			{
				max1 = kernel[0][j];
				e = j;
			}
		}
		if (max1 <= 0)											//���ֵ<=0�������м�����<=0�����������Ž������
		{
			cout << endl;
			cout << "������Ž�:" << kernel[0][0] << endl << endl;
			break;
		}
		for (int i = 1; i <= n; i++)							//������У�������/����� ����ֵ��С���У�
		{
			if (max2 < kernel[i][e])
			{
				max2 = kernel[i][e];
			}
			float temp = kernel[i][0] / kernel[i][e];
			if (temp > 0 && temp < min)
			{
				min = temp;
				k = i;
			}
		}
		cout << "�������" << "x" << FJL[e] << " ";
		cout << "�������" << "x" << JL[k] << endl;
		if (max2 == 0)
		{
			cout << "���޽�" << endl;
			break;
		}
		//����任��ת��任��
		char temp = FJL[e];
		FJL[e] = JL[k];
		JL[k] = temp;
		for (int i = 0; i <= n; i++)										//�����������кͳ�����֮�������Ԫ��
		{
			if (i != k)
			{
				for (int j = 0; j <= m; j++)
				{
					if (j != e)
					{
						if (i == 0 && j == 0)
							kernel[i][j] = kernel[i][j] + kernel[i][e] * kernel[k][j] / kernel[k][e];
						else
							kernel[i][j] = kernel[i][j] - kernel[i][e] * kernel[k][j] / kernel[k][e];;
					}
				}//=for (int j
			}//=if (i != k)
		}//=for (int i)
		for (int i = 0; i <= n; i++)														//��������λ�ã������Ԫ��
		{
			if (i != k)
			{
				kernel[i][e] = -kernel[i][e] / kernel[k][e];
			}
		}
		for (int j = 0; j <= m; j++)														//��������λ�ã������Ԫ��
		{
			if (j == e)
				kernel[k][j] = kernel[k][j] / kernel[k][e];
		}
		kernel[k][e] = 1 / kernel[k][e];												//��������λ�ã�����λ��
		print();
	}
}

void BestBenefitTank::BBTTest()
{
	cout << "����ǻ��������ĸ����ͷǻ����������±꣺" << endl;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> FJL[i];
	}
	cout << "������������ĸ����ͻ����������±꣺" << endl;
	cin >> n;
	for (int j = 1; j <= n; j++)
	{
		cin >> JL[j];
	}
	cout << "����Լ����׼�ͳ�ʼ�����α������" << endl;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			cin >> kernel[i][j];
		}
	}
	print();
	DCXA();
}

void BestBenefitTank::BBTTest2()
{
	cout << "����ǻ��������ĸ����ͷǻ����������±꣺" << endl;
	//cin >> m;]
	m = 3;
	cout << m << endl;
	char mArr[] = {'0', '2', '4', '5'};
	for (int i = 1; i <= m; i++)
	{
		//cin >> FJL[i];
		FJL[i] = mArr[i];
		cout << FJL[i] << " ";
	}
	cout << endl;
	cout << "������������ĸ����ͻ����������±꣺" << endl;
	//cin >> n;
	n = 4;
	cout << n << endl;
	char nArr[] = {'0', '1', '3', '6', '7' };
	for (int j = 1; j <= n; j++)
	{
		//cin >> JL[j];
		JL[j] = nArr[j];
		cout << JL[j] << " ";
	}
	cout << endl;
	cout << "����Լ����׼�ͳ�ʼ�����α������" << endl;
	float cube[5][4] = { {0, 2.5, 2.8, 76.25}, {0, 1, 0, -5}, {0, 0, 1, -2}, {12000, 0, 0, 1}, {1000, 0.1, 0.08, 0.05} };

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			//cin >> kernel[i][j];
			kernel[i][j] = cube[i][j];
			cout << cube[i][j] << " ";
		}
		cout << endl;
	}
	print();
	DCXA();
}

bool NetFlowSapTank::bfs(int s, int t)
{
	memset(pre, -1, sizeof(pre));
	memset(vis, false, sizeof(vis));
	queue<int>q;
	vis[s] = true;
	q.push(s);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)																//Ѱ�ҿ�����·
		{
			if (!vis[i] && g[now][i] > 0)														//δ�����ʣ����б�����
			{
				vis[i] = true;
				pre[i] = now;
				if (i == t) return true;
				q.push(i);
			}
		}
	}
	return false;																						//�Ҳ���������·
}

int NetFlowSapTank::EK(int s, int t)
{
	int v, w, d, maxflow;
	maxflow = 0;
	while (bfs(s, t))																					//������
	{
		v = t;
		d = INF;
		while (v != s)																					//�ҿ�����d
		{
			w = pre[v];																				//w��¼v��ǰ��
			if (d > g[w][v])
				d = g[w][v];
			v = w;
		}
		maxflow += d;
		v = t;
		while (v != s)																					//���ſ�����·����
		{
			w = pre[v];
			g[w][v] -= d;																				//��������������߼���
			g[v][w] += d;																			//���������

			if (f[v][w] > 0)																			//ʵ����������Ƿ����������������������
				f[v][w] -= d;
			else
				f[w][v] += d;
			v = w;
		}
	}
	return maxflow;
}

void NetFlowSapTank::print()
{
	cout << endl;
	cout << "-----------ʵ����������------------" << endl;
	cout << "  ";
	for (int i = 1; i <= n; i++)
		cout << setw(7) << "v" << i;
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "v" << i;
		for (int j = 1; j <= n; j++)
			cout << setw(7) << f[i][j];
		cout << endl;
	}
}

void NetFlowSapTank::NFSTTest()
{
	int u, v, w;
	const static int maxn = 9 + 1;
	//���ڵ��Ե�Ԥ�洢����
	int uArr[maxn] = { 0,1,1,2,3,3,4,4,5,5 };
	int vArr[maxn] = { 0,2,3,4,2,5,3,6,4,6 };
	int wArr[maxn] = { 0,12,10,8,2,13,5,18,6,4 };
	
	memset(g, 0, sizeof(g));
	memset(f, 0, sizeof(f));
	cout << "������ڵ����n�ͱ���m��" << endl;
	//cin >> n >> m;
	n = 6;
	m = 9;
	cout << n << " " << m << endl;
	cout << "�����������ڵ�u��v�Լ��ߣ�u--v��������w��" << endl;
	for (int i = 1; i <= m; i++)
	{
		//cin >> u >> v >> w;
		u = uArr[i];
		v = vArr[i];
		w = wArr[i];
		cout << u << " " << v << " " << w << endl;
		g[u][v] += w;
	}
	cout << "�������������" << EK(1, n);
	print();
}

//ʹ��������ǩ˼·���������·�㷨
void ISAPTank::init()
{
	memset(V, -1, sizeof(V));
	top = 0;
}

void ISAPTank::add_edge(int u, int v, int c)
{
	//�������ݸ�ʽ��u v ���ߣ�u--v��������c
	//�����top���ڽӱ�߼��Ķ���λ��
	E[top].v = v;
	E[top].cap = c;
	E[top].flow = 0;
	E[top].next = V[u].first;										//���ӵ��ڽӱ���
	V[u].first = top++;
}

void ISAPTank::add(int u, int v, int c)
{
	add_edge(u, v, c);
	add_edge(v, u, 0);
}

void ISAPTank::set_h(int t, int n)							//��ߺ���
{
	queue<int> Q;													//����һ�����У����ڹ����������
	memset(h, -1, sizeof(h));									//��ʼ���߶ȱ������Ϊ-1
	memset(g, 0, sizeof(g));									//��ʼ��ͬ�߶Ƚڽ��������¼����Ϊ0
	h[t] = 0;															//���
	Q.push(t);
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();														//����Ԫ�س���
		++g[h[v]];														//��������߶ȵ�Ԫ�ظ���+1
		for (int i = V[v].first; ~i; i = E[i].next)
		{
			int u = E[i].v;
			if (h[u] == -1)
			{
				h[u] = h[v] + 1;										//��v�����ڽڵ�߶�����Ϊ��v�߶ȸ�һ��
				Q.push(u);
			}
		}
	}
	cout << "��ʼ���߶�" << endl;
	cout << "h[ ] = ";
	for (int i = 1; i <= n; i++)
		cout << " " << h[i];
	cout << endl;
}

int ISAPTank::Isap(int s, int t, int n)
{
	set_h(t, n);																		//��ߺ���
	int ans = 0, u = s;															//��ʼ��ans = 0������ʼ�ڵ����Դ��
	int d;
	while (h[s] < n)
	{
		int i = V[u].first;	
		if (u == s)
			d = inf;
		for (; ~i; i = E[i].next)													//������ǰ�����ڽӱ�
		{
			int v = E[i].v;
			if (E[i].cap > E[i].flow && h[u] == h[v] + 1)			//�����п������͸߶ȷ����1�ķ���������
			{
				u = v;
				pre[v] = i;
				d = min(d, E[i].cap - E[i].flow);							//�õ���С����
				if (u == t)
				{
					cout << "����·��" << t;
					while (u != s)												//�ӻ�㿪ʼ����������·��һֱ������Դ��
					{
						int j = pre[u];											//jΪu��ǰ���ߣ�������·��jΪu�����
						E[j].flow += d;											//j�ߵ�����+d��
						E[j ^ 1].flow -= d;										//j�ߵķ��������-d
						/*
						*j ^ 1��ʾj��1���С�������������㡱����Ϊ����ʱ�ǳɶԴ����ģ�
						*0�űߵķ�����1�ţ�������0��1�������Ľ��������1��
						*��2�űߵķ������3��������10��1���������������11��
						*��3�űߣ���˵�ǰ��ź�1�����������Եõ���ǰ�ߵķ����
						*/
						u = E[j ^ 1].v;											//��ǰ����
						cout << "--" << u;
					}
					cout << "������" << d << endl;
					ans += d;
					d = inf;
				}//=if (u == t)
				break;																//�ҵ�һ�������ڽӱߣ��˳�for��䣬������ǰ��
			}//=if (E[i].cap > ...
		}//=for (; ~i; i = E[i].next)		
		if (i == -1)																//��ǰ���������ڽӽ��������ϣ��޷�����
		{
			if (--g[h[u]] == 0)													//����ø߶ȵĽ��ֻ��һ�����㷨����
				break;
			int hmin = n - 1;
			for (int j = V[u].first; ~j; j = E[j].next)
			{
				if (E[j].cap > E[j].flow)										//�п�����
					hmin = min(hmin, h[E[j].v]);							//�����ڽӵ�߶ȵ���Сֵ
			}
			h[u] = hmin + 1;													//���±�ߣ������ڽӵ�߶ȵ���Сֵ+1
			cout << "������ǩ֮��ĸ߶�" << endl;
			cout << "h[ ] = ";
			for (int i = 1; i <= n; i++)
				cout << " " << h[i];
			cout << endl;
			++g[h[u]];															//���±�ߺ�ĸø߶Ƚڵ���+1
			if (u != s)																//�����ǰ��㲻��Դ��
				u = E[pre[u] ^ 1].v;											//��ǰ�˻�һ����������������·��
		}
	}//=while (h[s] < n)
	return ans;
}

void ISAPTank::printg(int n)																	//��������ڽӱ�
{
	cout << "---------�����ڽӱ����£�----------" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "v" << i << "  [" << V[i].first;
		for (int j = V[i].first; ~j; j = E[j].next)
			cout << "]--[" << E[j].v << "  " << E[j].cap << "  " << E[j].flow << "  " << E[j].next;
		cout << "]" << endl;
	}
}

void ISAPTank::printflow(int n)																						//���ʵ����
{
	cout << "----------ʵ��������----------" << endl;
	for (int i = 1; i <+ n; i++)
		for (int j = V[i].first; ~j; j = E[j].next)
			if (E[j].flow > 0)
			{
				cout << "v" << i << "--" << "v" << E[j].v << "  " << E[j].flow;
				cout << endl;
			}
}

void ISAPTank::ISAPTest()
{
	int n, m;
	int u, v, w;
	cout << "����������n�ͱ���m��" << endl;
	cin >> n >> m;
	init();
	cout << "�����������ڵ�u��v����(u--v)������w��" << endl;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		add(u, v, w);																	//���������
	}
	cout << endl;
	printg(n);																			//�����ʼ�����ڽӱ�
	cout << "�����������ֵΪ��" << Isap(1, n, n) << endl;
	cout << endl;
	printg(n);																			//�����������
	printflow(n);																		//���ʵ����
}









