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



//2.4�߼��ӵ���������

MeetType meet[1000];

void setMeet::init()
{
	int begArr[10] = {3,1,5,2,5,3,8,6,8,12};
	int endArr[10] = {6,4,7,5,9,8,11,10,12,14};
	cout << "�����ܴ���nΪ��" << n << endl;
	cout << "����Ŀ�ʼ�ͽ���ʱ��Ϊ��" << endl;
	cout << "������" << "  ���鿪ʼʱ��" << "  �������ʱ��" << endl;
	for (int i = 0; i < n; i++)
	{
		meet[i].beg = begArr[i];
		meet[i].end = endArr[i];
		meet[i].num = i + 1;
		cout << "  " << meet[i].num << "\t\t" << meet[i].beg << "\t\t" << meet[i].end << endl;
	}
}

//����sort�ıȽϺ���
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
	cout << "����֮��Ļ���ʱ������:" << endl;
	cout << "������" << "  ���鿪ʼʱ��" << "  �������ʱ��" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "  " << meet[i].num << "\t\t" << meet[i].beg << "\t\t" << meet[i].end << endl;
	}
	cout << "--------------------------------------------------------------" << endl;
	cout << "ѡ��Ļ���Ĺ��̣�" << endl;
	cout << "  ѡ���" << meet[0].num << "������" << endl;			//ѡ�е�һ������
	ans = 1;
	int last = meet[0].end;																	//��¼��һ������Ľ���ʱ��
	for (i = 1; i < n; i++)
	{
		if (meet[i].beg >= last)
		{
			//�������i�Ŀ�ʼʱ����ڵ���ѡ�е����һ������Ľ���ʱ��
			ans++;
			last = meet[i].end;
			cout << "  ѡ���" << meet[i].num << "������" << endl;
		}
	}
	cout << "�����԰���" << ans << "������" << endl;

}


//2.5���·��

const int N = 100;							//���и��������޸�
const int INF = 1e7;
int map[N][N];
int dist[N];
int p[N];
int n, m;											//nΪ���и�����mΪ����֮���·������
int flag[N];										//flag[i]==ture,��ڵ�i������s���ϣ����߽ڵ�i��V-S����

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
	priority_queue <Node> Q;			//���ȶ��л�
	Q.push(Node(st, 0));
	memset(flag, 0, sizeof(flag));			//��ʼ��flag����Ϊ0
	for (int i = 1; i <= n; ++i)
		dist[i] = INF;								//��ʼ�����о���Ϊ�����
	dist[st] = 0;
	while (!Q.empty())
	{
		Node it = Q.top();						//���ȶ��ж�ͷԪ��Ϊ��Сֵ
		Q.pop();
		int t = it.u;
		if (flag[t])									//˵���Ѿ��ҵ�����̾��룬�ýڵ��Ƕ��������ظ���Ԫ��
			continue;
		flag[t] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (!flag[i] && map[t][i] < INF)
				if (dist[i] > dist[t] + map[t][i])
				{										//����뵱ǰ���ÿ�������̾��룬�����ɳڲ���
					dist[i] = dist[t] + map[t][i];
					Q.push(Node(i, dist[i]));			//�Ѹ��¹�����̾���ѹ�����ȶ���
				}
		}
	}
}//void 

void TestDijkstra()
{
	int st;
	system("color 0d");
	cout << "��������и���" << endl;
	n = 5;
	cout << "��������м��·�߸���" << endl;
	m =7;
	cout << "��������м��·���Լ�����" << endl;
	for(int i=1;i<=n;i++)								//��ʼ��ͼ���ڽӾ���
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
	cout << "������С��Ŀǰ���ڵ�λ��" << endl;
	cin >> st;
	Dijkstra(st);
	//findPath(st);
	for (int i = 1; i <= n; i++)
	{
		cout << "С����" << st << "--->" << "Ҫȥ��λ�ã�" << i;
		if (dist[i] == INF)
			cout << "sorry,��·�ɴ�" << endl;
		else
			cout << "��̾���Ϊ��" << dist[i] << endl;
	}
}

void findPath(int u)
{
	int x;
	stack<int> s;
	cout << "Դ��Ϊ��" << u << endl;
	for (int i = 1; i <= n; i++)
	{
		x = p[i];
		while (x != -1)
		{
			s.push(x);									//��ǰ���ڵ�ѹ��ջ��
			x = p[x];
		}
		cout << "Դ�㵽������������·��Ϊ��";
		while (!s.empty())
		{
			cout << s.top() << "--";					//���ε��������ڵ�
			s.pop();
		}
		cout << "��̾���Ϊ��" << dist[i] << endl;
	}
}




//2.6 ����������
HNodeType HuffNode[MAXNODE];						//����һ���ڵ�ṹ������
HCodeType HuffCode[MAXLEAF];						//����һ������ṹ������
void dkg_HuffmanTree(HNodeType HuffNode[MAXNODE], int n)
{
	/*i��j��ѭ������,m1��m2���������������ͬ������������СȨֵ�ڵ��Ȩֵ
	 *x1��x2���������������ͬ������������СȨֵ�ڵ��������е���š�
	*/
	int i, j, x1, x2;
	double m1, m2;
	//��ʼ������ڹ���������HuffNode[]�еĽڵ�
	for (i = 0; i < 2 * n - 1; i++)										//�������ܽ����=Ҷ����*2-1
	{
		HuffNode[i].weight = 0;		//Ȩֵ
		HuffNode[i].parent = -1;
		HuffNode[i].lchild = -1;
		HuffNode[i].rchild = -1;
	}
	/*����n��Ҷ�ӽ��Ȩֵ*/
	double weightArr[6] = {0.05 , 0.32 , 0.18 , 0.07 , 0.25 , 0.13};
	char valueArr[6] = {'a' , 'b' , 'c' , 'd' , 'e' , 'f'};
	for (i = 0; i < n; i++)
	{
		cout << "Please input value and weight of leaf node" << i + 1 << endl;
		//cin >> HuffNode[i].value >> HuffNode[i].weight;
		HuffNode[i].value = valueArr[i];
		HuffNode[i].weight = weightArr[i];
	}

	/*�����������*/
	for (i = 0; i < n - 1; i++)
	{//ִ��n-1�κϲ�
		m1 = m2 = MAXVALUE;
		/*m1 m2 ������������޸��ڵ���ȫְ��С�������ڵ��Ȩֵ*/
		x1 = x2 = -1;
		/*�ҳ����нڵ���Ȩֵ��С���޸��ڵ�������ڵ㣬���ϲ�Ϊһ�Ŷ�����*/
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
				////˽�� ֮��������Ļ�ɾ��
				//m1 = m2;
				//x1 = x1;

				m2 = HuffNode[j].weight;
				x2 = j;
			}
		}
		/*���������ӽڵ�x1 x2 �ĸ��ڵ���Ϣ*/
		HuffNode[x1].parent = n + i;
		HuffNode[x2].parent = n + i;
		HuffNode[n + i].weight = m1 + m2;
		HuffNode[n + i].lchild = x1;
		HuffNode[n + i].rchild = x2;
		/*���ڲ���*/
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
			cd.start--;						/*������һλ*/
			c = p;
			p = HuffNode[c].parent;			/*������һѭ������*/
		}
		/*��Ҷ�ӽ��ı�����Ϣ����ʱ����cd�и��Ƴ������������ں�������*/
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
	cout << "Please input n��" << endl;
	//cin >> n;
	n = 6;
	dkg_HuffmanTree(HuffNode, n);
	dkg_HuffmanCode(HuffCode, n);

	for (i = 0; i < n; i++)
	{
		cout << HuffNode[i].value << "��Huffman code is��";
		for (j = HuffCode[i].start + 1; j < n; j++)
			cout << HuffCode[i].bit[j];
		cout << endl;
	}
}

